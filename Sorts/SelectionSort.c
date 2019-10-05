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
