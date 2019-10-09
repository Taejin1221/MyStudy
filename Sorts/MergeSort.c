// MergeSort O(nlogn)
#include <stdlib.h>

void Merge(int* arr, int left, int mid, int right) {
	int startRight = mid + 1;

	int idxLeft, idxRight, idxOrigin = left;
	int lenLeft = (mid - left) + 1, lenRight = (right - startRight) + 1;

	int* arrCopy = malloc(sizeof(int) * (lenLeft + lenRight));

	// Copy left array and right array
	for (int i = left; i <= right; i++) arrCopy[i - left] = arr[i];

	idxLeft = 0, idxRight = lenLeft;
	while ((idxLeft < lenLeft) && (idxRight - lenLeft < lenRight))
		arr[idxOrigin++] = ((arrCopy[idxLeft] <= arrCopy[idxRight]) ? (arrCopy[idxLeft++]) : (arrCopy[idxRight++]));

	// Move left nums
	while (idxLeft < lenLeft)
		arr[idxOrigin++] = arrCopy[idxLeft++];

	while (idxRight < lenRight)
		arr[idxOrigin++] = arrCopy[idxRight++];

	free(arrCopy);
}

void MergeSort(int* arr, int left, int right) {
	if (left >= right) return;
	else {
		int mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		Merge(arr, left, mid, right);
	}
}
