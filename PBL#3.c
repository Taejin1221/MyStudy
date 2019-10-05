// Prob#3.c
// Baekjun 2750
#include <stdio.h>
#include <stdlib.h> /* malloc(), free() */

// Selection Sort O(n^2)
void SelectionSort(int arr[], int len) {
	int idx = len - 1;

	while (idx > 0) {
		int max = 0;
		for (int i = 1; i <= idx; i++)
			if (arr[i] > arr[max])
				max = i;

		int temp = arr[idx];
		arr[idx--] = arr[max];
		arr[max] = temp;
	}
}

// Bubble Sort O(n^2)
void BubbleSort(int arr[], int len) {
	for (int i = len - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}

int main(void) {
	int len;
	int* arr;

	scanf("%d", &len);
	arr = malloc(sizeof(int) * len);

	for (int i = 0; i < len; i++)
		scanf("%d", &arr[i]);

	SelectionSort(arr, len);
	BubbleSort(arr, len);

	for (int i = 0; i < len; i++)
		printf("%d\n", arr[i]);

	free(arr);

	return 0;
}