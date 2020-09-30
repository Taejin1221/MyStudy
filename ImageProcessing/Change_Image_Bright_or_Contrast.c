// OS Windows 10
// Compiler Visual Studio 2019
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define WIDTHBYTES(b) ( ( ( b ) + 3 ) / 4 * 4 )

void Operator(BYTE* data) {
	// + Operator
	if (*data + 20 > 255)
		*data = 255;
	else
		*data += 20;

	// - Operator
	if (*data - 20 < 0)
		*data = 0;
	else
		*data -= 20;

	// * Operator
	if (*data * 1.2 > 255)
		*data = 255;
	else
		*data *= 1.2;

	// / Operator
	if (*data / 1.2 < 0)
		*data = 0;
	else
		*data = (BYTE)(*data / 1.2);
}

int main(void) {
	FILE* fp;

	// Read Headers
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;

	fp = fopen("Lenna.bmp", "rb");
	fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, fp);
	fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fp);

	// Read Pixels
	LONG width = infoHeader.biWidth, height = infoHeader.biHeight;
	LONG stepWidth = WIDTHBYTES((infoHeader.biBitCount / 8) * width);
	LONG size = stepWidth * height;

	BYTE* inputData = (BYTE*)malloc(sizeof(BYTE) * size);
	if (inputData == NULL) {
		printf("Error: Faild to malloc input data\n");
		return -1;
	}

	fseek(fp, fileHeader.bfOffBits, SEEK_SET);
	fread(inputData, sizeof(BYTE), size, fp);

	fclose(fp);

	// Convert input data to output data using +, -, *, / Operator
	BYTE* outputData = (BYTE*)malloc(sizeof(BYTE) * size);
	if (outputData == NULL) {
		printf("Error: Failed to malloc output data\n");
		return -1;
	}

	for (int i = 0; i < size; i++) {
		outputData[i] = inputData[i];
		Operator(outputData + i);
	}

	// Write output data
	fp = fopen("Lenna(Operator).raw", "wb");

	fwrite(outputData, sizeof(BYTE), size, fp);

	fclose(fp);

	free(inputData);
	free(outputData);

	return 0;
}