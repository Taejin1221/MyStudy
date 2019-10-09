/* InsertiontionSort.c */
void InsertionSort(int arr[], int len) {
	for (int i = 1; i < len; i++) {
		int cmp;
		int target = arr[i];
		for (cmp = i - 1; (target < arr[cmp]) && (cmp >= 0); cmp--)
			arr[cmp + 1] = arr[cmp];
		arr[cmp + 1] = target;
	}
}