#include <stdio.h>
#include <stdlib.h> /* malloc(), free() */
#include <string.h> /* memset() */

#define WIDTH 374
#define HEIGHT 374
#define N 3

typedef unsigned char BYTE;

int main() {
	const int imgSize = WIDTH * HEIGHT;
	BYTE Struc[N][N] = {
		{0, 1, 0},
		{1, 1, 1},
		{0, 1, 0}
	};


	FILE* fp = fopen("lenna.raw", "rb");

	BYTE* inputImg = (BYTE*)malloc(imgSize);
	fread(inputImg, 1, imgSize, fp);
	fclose(fp);

	BYTE* binImg = (BYTE*)malloc(imgSize);
	int threshold = 120;
	for (int i = 0; i < imgSize; i++) {
		if (inputImg[i] > threshold)
			binImg[i] = 255; // 전경(White)
		else
			binImg[i] = 0; // 배경(Black)
	}

	fp = fopen("lenna_binarization.raw", "wb");
	fwrite(binImg, 1, imgSize, fp);
	fclose(fp);

	BYTE* outputImg = (BYTE*)malloc(imgSize);
	for (int i = 0; i < imgSize; i++) {
		BYTE tempP = 1; // 1 &연산, 0 |연산
		int hh = i / WIDTH;
		int ww = i % WIDTH;

		if (hh >= N / 2 && hh < HEIGHT - N / 2 && ww >= N / 2 && ww < WIDTH - N / 2) {
			for (int ii = -N / 2; ii < N / 2 + 1; ii++) {
				for (int jj = -N / 2; jj < N / 2 + 1; jj++) {
					if (Struc[ii + N / 2][jj + N / 2] == 1) {
						tempP = binImg[(hh + ii) * WIDTH + ww + jj] & Struc[ii + N / 2][jj + N / 2] & tempP; // Erosion
					}
				}
			}
		}

		if (tempP == 1)
			outputImg[i] = 255;
		else
			outputImg[i] = 0;
	}


	fp = fopen("lenna_erosion.raw", "wb");
	fwrite(outputImg, 1, imgSize, fp);
	fclose(fp);

	free( inputImg );
	free( binImg );
	free( outputImg );

	return 0;
}
