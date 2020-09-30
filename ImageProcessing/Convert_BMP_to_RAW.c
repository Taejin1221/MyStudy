// OS Windows 10
// Compiler Visual Studio 2019
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define WIDTHBYTES(b) ( ( ( b ) + 3 ) / 4 * 4 )

int main(void) {
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;

	FILE* fp;
	fp = fopen("Lenna.bmp", "rb");

	fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, fp);
	fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fp);

	LONG width = infoHeader.biWidth, height = infoHeader.biHeight;
	LONG stepWidth = WIDTHBYTES((infoHeader.biBitCount / 8) * width) ;
	LONG imgSize = stepWidth * height;

	BYTE* inputImg = (BYTE*)malloc(sizeof(BYTE) * imgSize);
	if (inputImg == NULL) {
		printf("Error: Failed to Allocate Input Image");
		return -1;
	}

	fseek(fp, fileHeader.bfOffBits, SEEK_SET);
	fread(inputImg, sizeof(BYTE), imgSize, fp);

	fclose(fp);

	fp = fopen("Lenna(bmp_to_raw).raw", "wb");
	
	fwrite(inputImg, sizeof(BYTE), imgSize, fp);

	fclose(fp);

	free(inputImg);

	return 0;
}