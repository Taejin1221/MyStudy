// MedianFilter.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEIGHT 512
#define WIDTH 512
#define N 3
#define M 3

typedef unsigned char BYTE;

void BubbleSort( BYTE values[], int size ) {
	for ( int i = size - 1; i > 0; i-- ) {
		for ( int j = 0; j < i; j++ ) {
			if ( values[j] > values[j + 1] ) {
				int temp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = temp;
			}
		}
	}
}

int main(void) {
	const int fileSize = WIDTH * HEIGHT, filterSize = N * M;

	FILE* fp = fopen( "SemiconductNoise512.raw", "rb" );
	if ( fp == NULL ) {
		printf("Error to file open\n" );
		return -1;
	}

	BYTE* inputImg = (BYTE*)malloc( sizeof(BYTE) * fileSize );
	fread( inputImg, sizeof(BYTE), fileSize, fp );
	fclose(fp);

	BYTE* outputImg = (BYTE*)malloc( sizeof(BYTE) * fileSize );
	memset( outputImg, 0, fileSize );

	BYTE* values = (BYTE*)malloc( sizeof(BYTE) * filterSize );
	for ( int idx = WIDTH + 1; idx < (HEIGHT - 2) * WIDTH + (WIDTH - 1); idx++ ) {
		if ( (idx % WIDTH != 0) && ((idx + 1) % WIDTH != 0) ) {
			int valueIdx = 0;
			for ( int i = -(N / 2); i <= (N / 2); i++ ) {
				for ( int j = -(M / 2); j <= (M / 2); j++ ) {
					int newIdx = idx + i * WIDTH + j;
					values[valueIdx++] = inputImg[newIdx];
				}
			}
			BubbleSort( values, filterSize );

			outputImg[idx] = values[filterSize / 2];
		} else
			outputImg[idx] = inputImg[idx];

	}

	fp = fopen( "SemiconductNoise512_filtered.raw", "wb" );
	if ( fp == NULL ) {
		printf("Error to file open\n" );
		return -1;
	}

	fwrite( outputImg, sizeof(BYTE), fileSize, fp );
	fclose( fp );

	free( inputImg );
	free( outputImg );
	free( values );

	return 0;
}