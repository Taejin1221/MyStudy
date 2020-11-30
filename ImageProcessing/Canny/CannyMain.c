// CannyMain.c
#include <stdio.h>
#include "cannyedge.h"

int main(void) {
	CannyEdge( "Lenna(gray).bmp", "Lenna(Canny).bmp", 50, 150 );

	return 0;
}