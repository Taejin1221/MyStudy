// cannyedge.h
#ifndef CANNYEDGE
#define CANNYEDGE

#include "bitmap.h"

#define TRUE 1
#define FALSE 0

typedef int BOOL;

typedef struct tagPosition {
	int row, col;
} Position;

BYTE** ImageOpen(char* fileName, PBITMAPFILEHEADER headPtr, PBITMAPINFOHEADER infoPtr, RGBQUAD rgb[] );
BYTE** WriteEdgeToFile( char* fileName, BYTE** img, PBITMAPFILEHEADER fileHeader, PBITMAPINFOHEADER infoHeader, RGBQUAD rgb[] );
void CannyEdge(char* inputFile, char* outputFile, int t_low, int t_high);
void FollowEdge( BYTE** edge, double** edgeGradientMap, BOOL** visited, int row, int col, int threshold );

#endif