#ifndef HEAP_H
#define HEAP_H

#include "../Data.h"

#define MAX_HEAP_SIZE 100

typedef struct _Heap {
	Data heap[MAX_HEAP_SIZE];
	int size;
} Heap, * HeapPtr;

void Init(HeapPtr h);
void Insert_Max(HeapPtr h, Data item);
Data Delete_Max(HeapPtr h);
void Insert_Min(HeapPtr h, Data item);
Data Delete_MIn(HeapPtr h);
void PrintHeap(HeapPtr h);

#endif