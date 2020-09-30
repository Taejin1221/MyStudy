// OS Windows 10
// Compiler Visual Studio 2019
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

#define SIZE 374

BYTE** DeclareBuffer();
void FreeBuffer(BYTE**);

int main(void) {
	FILE* fp;

	// Declare Read Buffer
	BYTE** readBuf = DeclareBuffer();

	// Read File
	fp = fopen("lena.raw", "rb");
	for (int i = 0; i < SIZE; i++)
		fread(readBuf[i], sizeof(BYTE), SIZE, fp);
	fclose(fp);

	// Declare Write Buffer and Flip(left and right) Original Image
	BYTE** writeBuf = DeclareBuffer();
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			writeBuf[i][j] = readBuf[i][SIZE - j];

	fp = fopen("lena(Fliped).raw", "wb");
	for (int i = 0; i < SIZE; i++)
		fwrite(writeBuf[i], sizeof(BYTE), SIZE, fp);
	fclose(fp);

	FreeBuffer(readBuf);
	FreeBuffer(writeBuf);

	return 0;
}

BYTE** DeclareBuffer() {
	BYTE** temp = (BYTE**)malloc(sizeof(BYTE*) * SIZE);
	for (int i = 0; i < SIZE; i++)
		temp[i] = (BYTE*)malloc(sizeof(BYTE) * SIZE);

	return temp;
}

void FreeBuffer(BYTE** buf) {
	for (int i = 0; i < SIZE; i++)
		free(buf[i]);
	free(buf);
}