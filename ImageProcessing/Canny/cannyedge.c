// cannyedge.c
#include <stdio.h>
#include <stdlib.h> /* malloc(), free() */
#include <math.h> /* pow(), sqrt(), atan() */
#include <string.h> /* memset() */
#include "cannyedge.h"

#define Free2D( ptr, h ) { for ( int i = 0; i < (h); i++ ) free( ptr[i] ); free(ptr); }

const int sobelFilter_y[3][3] = {
	{ -1, -2, -1 },
	{ 0, 0, 0 },
	{ 1, 2, 1 }
};

const int sobelFilter_x[3][3] = {
	{ 1, 0, 1 },
	{ -2, 0, 2 },
	{ -1, 0, 1 }
};


BYTE** ImageOpen(char* fileName, PBITMAPFILEHEADER headPtr, PBITMAPINFOHEADER infoPtr, RGBQUAD rgb[] ) {
	FILE* fp = fopen(fileName, "rb");
	if ( fp == NULL ) {
		printf("Error: Failed to input file open\n");
		return NULL;
	}

	fread( headPtr, sizeof(BITMAPFILEHEADER), 1, fp );
	fread( infoPtr, sizeof(BITMAPINFOHEADER), 1, fp );
	fread( rgb, sizeof(RGBQUAD), 256, fp );

	INT width = infoPtr->biWidth, height = infoPtr->biHeight;
	INT stepWidth = WIDTHBYTES( ( infoPtr->biBitCount / 8 ) * width );

	BYTE** inputImg = (BYTE**)malloc(sizeof(BYTE*) * height);
	for ( int i = 0; i < height; i++ ) {
		inputImg[i] = (BYTE*)malloc(sizeof(BYTE) * stepWidth);
		fread( inputImg[i], sizeof(BYTE), stepWidth, fp );
	}

	fclose( fp );

	return inputImg;
}

BYTE** WriteEdgeToFile( char* fileName, BYTE** img, PBITMAPFILEHEADER fileHeader, PBITMAPINFOHEADER infoHeader, RGBQUAD rgb[] ) {
	FILE* fp = fopen(fileName, "wb");
	if ( fp == NULL ) {
		printf("Error: Failed to output file open\n");
		return -1;
	}

	fwrite( fileHeader, sizeof(BITMAPFILEHEADER), 1, fp );
	fwrite( infoHeader, sizeof(BITMAPINFOHEADER), 1, fp );
	fwrite( rgb, sizeof(RGBQUAD), 256, fp );

	INT width = infoHeader->biWidth, height = infoHeader->biHeight;
	INT stepWidth = WIDTHBYTES( ( infoHeader->biBitCount / 8 ) * width );


	for ( int i = 0; i < height; i++ )
		fwrite( img[i], sizeof(BYTE), stepWidth, fp );

	fclose(fp);
}

void CannyEdge(char* inputFile, char* outputFile, int t_low, int t_high) {
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;
	RGBQUAD rgb[256];
	BYTE** inputImg = ImageOpen( inputFile, &fileHeader, &infoHeader, rgb );
	if ( inputImg == NULL ) {
		printf("Failed to Canny Edge\n");
		return;
	}

	// Apply Sobel Filter
	int imgHeight = infoHeader.biHeight, imgWidth = WIDTHBYTES( ( infoHeader.biBitCount / 8 ) * infoHeader.biWidth );;
	double** edgeGradientMap = (double**)malloc(sizeof(double*) * imgHeight);
	for ( int i = 0; i < imgHeight; i++ )
		edgeGradientMap[i] = (double*)malloc(sizeof(double) * imgWidth);

	int** edgeDirectionMap = (int**)malloc(sizeof(int*) * imgHeight);
	for ( int i = 0; i < imgHeight; i++ )
		edgeDirectionMap[i] = (int*)malloc(sizeof(int) * imgWidth);

	for ( int row = 1; row < imgHeight - 1; row++ ) {
		for ( int col = 1; col < imgWidth - 1; col++ ) {
			int d_y = 0;
			for ( int i = -1; i <= 1; i++ )
				for ( int j = -1; j <= 1; j++ )
					d_y += sobelFilter_y[i + 1][j + 1] * inputImg[row + i][col + j];

			int d_x = 0;
			for ( int i = -1; i <= 1; i++ )
				for ( int j = -1; j <= 1; j++ )
					d_x += sobelFilter_x[i + 1][j + 1] * inputImg[row + i][col + j];

			edgeGradientMap[row][col] = sqrt((double)(pow(d_x, 2) + pow(d_y, 2)));
			double currGradientDirection = atan( (double)d_y / d_x ) - 90;
			currGradientDirection -= 22.5;
			if ( currGradientDirection < 0 || currGradientDirection >= 315 )
				edgeDirectionMap[row][col] = 0;
			else
				edgeDirectionMap[row][col] = (int)ceil(currGradientDirection / 45) + 1;
		}
	}

	// Non Maximum Supression
	for ( int row = 1; row < imgHeight - 1; row++ ) {
		for ( int col = 1; col < imgWidth - 1; col++ ) {
			Position neig[2]; // neighborhood
			int direction = edgeDirectionMap[row][col];
			if ( direction == 0 || direction == 4 ) {
				neig[0].row = row - 1, neig[0].col = col;
				neig[1].row = row + 1, neig[1].col = col;
			} else if ( direction == 1 || direction == 5 ) {
				neig[0].row = row - 1, neig[0].col = col + 1;
				neig[1].row = row + 1, neig[1].col = col - 1;
			} else if ( direction == 2 || direction == 6 ) {
				neig[0].row = row, neig[0].col = col - 1;
				neig[1].row = row, neig[1].col = col + 1;
			} else if ( direction == 3 || direction == 7 ) {
				neig[0].row = row - 1, neig[0].col = col - 1;
				neig[1].row = row + 1, neig[1].col = col + 1;
			}

			if ( edgeGradientMap[row][col] <= edgeGradientMap[neig[0].row][neig[0].col] ||
				edgeGradientMap[row][col] <= edgeGradientMap[neig[1].row][neig[1].col] ) {
				edgeGradientMap[row][col] = 0.0;
			}
		}
	}

	BYTE** edge = (BYTE**)malloc(sizeof(BYTE*) * imgHeight);
	BOOL** visited = (BOOL**)malloc(sizeof(BOOL*) * imgHeight);
	for ( int i = 0; i < imgHeight; i++ ) {
		edge[i] = (BYTE*)malloc(sizeof(BYTE) * imgWidth);
		visited[i] = (BOOL**)malloc(sizeof(BOOL) * imgWidth);
		memset( edge[i], 0, sizeof(BYTE) * imgWidth );
		for ( int j = 0; j < imgWidth; j++ )
			visited[i][j] = FALSE;
	}

	for ( int row = 1; row < imgHeight - 1; row++ )
		for ( int col = 1; col < imgWidth - 1; col++ )
			if ( edgeGradientMap[row][col] > t_high && !visited[row][col] )
				FollowEdge( edge, edgeGradientMap, visited, row, col, t_low );

	WriteEdgeToFile( outputFile, edge, &fileHeader, &infoHeader, rgb );

	Free2D( inputImg, imgHeight );
	Free2D( edgeGradientMap, imgHeight );
	Free2D( edgeDirectionMap, imgHeight );
	Free2D( edge, imgHeight  );
	Free2D( visited, imgHeight );
}

void FollowEdge( BYTE** edge, double** gradientMap, BOOL** visited, int row, int col, int threshold ) {
	visited[row][col] = TRUE;
	edge[row][col] = 255;

	for ( int i = -1; i <= 1; i++ ) {
		for ( int j = -1; j <= 1; j++ ) {
			if ( i == 0 && j == 0 ) continue;

			if ( (gradientMap[row + i][col + j] > threshold) && !visited[row + i][col + j] )
				FollowEdge( edge, gradientMap, visited, row + i, col + j, threshold );
		}
	}
}
