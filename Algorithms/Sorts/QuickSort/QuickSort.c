/* QuickSort.c */

// pivot is end of array
int Partition1(int arr[], int left, int right) {
	int target = arr[right];
	int low = left, high = left;
	int temp;

	for (; high < right; high++) {
		if (arr[high] < target) {
			temp = arr[high];
			arr[high] = arr[low];
			arr[low++] = temp;
		}
	}

	arr[right] = arr[low];
	arr[low] = target;

	return low;
}

// pivot is start of array
int Partition2(int arr[], int left, int right) {
	int target = arr[left];
	int low = left, high = left + 1;
	int temp;

	for (; high <= right; high++) {
		if (arr[high] < target) {
			temp = arr[high];
			arr[high] = arr[++low];
			arr[low] = temp;
		}
	}

	arr[left] = arr[low];
	arr[low] = target;

	return low;
}

void QuickSort(int arr[], int left, int right) {
	if (left >= right) return;
	else {
		int mid = 
			// Partition1(arr, left, right);
			// Partition2(arr, left, right);
		QuickSort(arr, left, mid - 1);
		QuickSort(arr, mid + 1, right);
	}
}
