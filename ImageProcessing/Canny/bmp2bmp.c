// bmp2bmp.c
#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"

#define WIDTHBYTES(b) ( ( ( b ) + 3 ) / 4 * 4 )

int main(void) {
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;
	RGBQUAD rgbQuad[256];

	FILE* fp = fopen( "Lenna.bmp", "rb" );

	fread( &fileHeader, sizeof(BITMAPFILEHEADER), 1, fp );
	fread( &infoHeader, sizeof(BITMAPINFOHEADER), 1, fp );
	fread( rgbQuad, sizeof(RGBQUAD), 256, fp );

	INT width = infoHeader.biWidth, height = infoHeader.biHeight;
	INT stepWidth = WIDTHBYTES( ( infoHeader.biBitCount / 8 ) * width );

	BYTE** inputImg = (BYTE**)malloc(sizeof(BYTE*) * height);
	for ( int i = 0; i < height; i++ ) {
		inputImg[i] = (BYTE*)malloc(sizeof(BYTE) * stepWidth);
		fread( inputImg[i], sizeof(BYTE), stepWidth, fp );
	}

	fclose(fp);

	fp = fopen( "Lenna(bmp_bmp).bmp", "wb" );

	fwrite( &fileHeader, sizeof(BITMAPFILEHEADER), 1, fp );
	fwrite( &infoHeader, sizeof(BITMAPINFOHEADER), 1, fp );
	fwrite( rgbQuad, sizeof(RGBQUAD), 256, fp );

	for ( int i = 0; i < height; i++ )
		fwrite( inputImg[i], sizeof(BYTE), stepWidth, fp );

	fclose(fp);

	for ( int i = 0; i < height; i++ )
		free( inputImg[i] );
	free( inputImg );

	return 0;
}