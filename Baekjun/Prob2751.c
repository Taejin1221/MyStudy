// Baekjun 2751
#include <stdio.h>
#include <stdlib.h> /* malloc(), free() */

// MergeSort O(nlogn)
void Merge(int* arr, int left, int mid, int right) {
	int startRight = mid + 1;

	int idxLeft = 0, idxRight = 0, idxOrigin = left;
	int lenLeft = (mid - left) + 1, lenRight = (right - startRight) + 1;

	int* arrLeft = malloc(sizeof(int) * lenLeft);
	int* arrRight = malloc(sizeof(int) * lenRight);

	// Copy left array and right array
	for (int i = left; i <= mid; i++) arrLeft[i - left] = arr[i];
	for (int i = startRight; i <= right; i++) arrRight[i - startRight] = arr[i];

	idxLeft = 0, idxRight = 0;
	while ((idxLeft < lenLeft) && (idxRight < lenRight))
		arr[idxOrigin++] = ((arrLeft[idxLeft] <= arrRight[idxRight]) ? (arrLeft[idxLeft++]) : (arrRight[idxRight++]));

	// Move left nums
	while (idxLeft < lenLeft)
		arr[idxOrigin++] = arrLeft[idxLeft++];

	while (idxRight < lenRight)
		arr[idxOrigin++] = arrRight[idxRight++];

	free(arrLeft); free(arrRight);
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

int main(void) {
	int len;
	int* arr;

	scanf("%d", &len);
	arr = malloc(sizeof(int) * len);

	for (int i = 0; i < len; i++)
		scanf("%d", &arr[i]);

	MergeSort(arr, 0, len - 1);

	for (int i = 0; i < len; i++)
		printf("%d\n", arr[i]);

	free(arr);

	return 0;
}
