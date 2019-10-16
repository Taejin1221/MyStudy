/* Bubble Sort O(n^2) */
void BubbleSort(int arr[], int len) {
	for (int i = len - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}
