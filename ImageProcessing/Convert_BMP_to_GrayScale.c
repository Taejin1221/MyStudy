// OS Windows 10
// Compiler Visual Studio 2019
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define WIDTHBYTES(b) ( ( ( b ) + 3 ) / 4 * 4 )

int main(void) {
	FILE* fp;

	// Read Headers
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;

	fp = fopen("Lenna.bmp", "rb");
	fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, fp);
	fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fp);

	// Read pixel Images
	LONG width = infoHeader.biWidth, height = infoHeader.biHeight;
	LONG stepWidth = WIDTHBYTES((infoHeader.biBitCount / 8) * width);
	LONG inputSize = stepWidth * height, outputSize = width * height;

	BYTE* inputData = (BYTE*)malloc(sizeof(BYTE) * inputSize);
	if (inputData == NULL) {
		printf("Error: Failed to Allocate Memories(Input)");
		return -1;
	}

	fseek(fp, fileHeader.bfOffBits, SEEK_SET);
	fread(inputData, sizeof(BYTE), inputSize, fp);

	fclose(fp);

	// Convert input data to gray output using YCrCb
	BYTE* outputData = (BYTE*)malloc(sizeof(BYTE) * outputSize);
	if (outputData == NULL) {
		printf("Error: Failed to Allocate Memories(Output)");
		return -1;
	}

	int outputIdx = 0, inputIdx = 0;
	while (outputIdx < outputSize) {
		BYTE currData = (BYTE)(0.114 * inputData[inputIdx] + 0.587 * inputData[inputIdx + 1] + 0.299 * inputData[inputIdx + 2]);
		outputData[outputIdx++] = currData;
		inputIdx += 3;
	}

	// Write output Image
	fp = fopen("Lenna(Gray).raw", "wb");

	fwrite(outputData, sizeof(BYTE), outputSize, fp);

	fclose(fp);

	// Free Heap datas;
	free(inputData);
	free(outputData);

	return 0;
}