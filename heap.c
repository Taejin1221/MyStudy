#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void Init(HeapPtr h) {
	h->size = 0;
}

void Insert_Max(HeapPtr h, Data item) {
	h->heap[++(h->size)] = item;
	int parent = h->size / 2;
	int child = h->size;

	while ( (parent >= 1) && (CompareData(h->heap[parent], item) < 0)) {
		h->heap[child] = h->heap[parent];
		child = parent;
		parent /= 2;
	}

	h->heap[child] = item;
}

Data Delete_Max(HeapPtr h) {
	Data removed = h->heap[1];
	Data comp = h->heap[(h->size)--];

	int parent = 1;
	int child;
	int childLeft = 2;
	int childRight = 3;

	while(childLeft <= h->size) {
		if (childRight <= h->size)
			child = (CompareData(h->heap[childLeft], h->heap[childRight]) > 0) ? childLeft : childRight;
		else
			child = childLeft;
		if (CompareData(comp, h->heap[child]) < 0) {
			h->heap[parent] = h->heap[child];
			childLeft = child * 2;
			childRight = child * 2 + 1;
			parent = child;
		} else break;
	}

	h->heap[parent] = comp;

	return removed;
}

void Insert_Min(HeapPtr h, Data item) {
	h->heap[++(h->size)] = item;
	int parent = h->size / 2;
	int child = h->size;

	while ( (parent >= 1) && (CompareData(h->heap[parent], item) > 0)) {
		h->heap[child] = h->heap[parent];
		child = parent;
		parent /= 2;
	}

	h->heap[child] = item;
}

Data Delete_Min(HeapPtr h) {
	Data removed = h->heap[1];
	Data comp = h->heap[(h->size)--];

	int parent = 1;
	int child;
	int childLeft = 2;
	int childRight = 3;

	while(childLeft <= h->size) {
		if (childRight <= h->size)
			child = (CompareData(h->heap[childLeft], h->heap[childRight]) < 0) ? childLeft : childRight;
		else
			child = childLeft;
		if (CompareData(comp, h->heap[child]) > 0) {
			h->heap[parent] = h->heap[child];
			childLeft = child * 2;
			childRight = child * 2 + 1;
			parent = child;
		} else break;
	}

	h->heap[parent] = comp;

	return removed;
}

void PrintHeap(HeapPtr h) {
	for (int i = 1; i <= h->size; i++) {
		PrintData(h->heap[i]); printf("->");
	}
	puts("NULL");
}