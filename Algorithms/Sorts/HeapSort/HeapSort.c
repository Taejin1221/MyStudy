/* HeapSort.c */
typedef int * intPtr;

void Swap(intPtr a, intPtr b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void MaxHeapify(int arr[], int me, int len) {
	int leftChild = me * 2, rightChild = me * 2 + 1;
	int largeChild;

	if (rightChild <= len)
		largeChild = ((arr[leftChild] < arr[rightChild]) ? rightChild : leftChild);
	else if (leftChild <= len) largeChild = leftChild;
	else return;

	if (arr[me] <= arr[largeChild]) {
		Swap(&arr[me], &arr[largeChild]);
		MaxHeapify(arr, largeChild, len);
	}
}

void BuildMaxHeap(int arr[], int len) {
	for (int i = len / 2; i > 0; i--)
		MaxHeapify(arr, i, len);
}

void HeapSort(int arr[], int len) {
	BuildMaxHeap(arr, len);
	for (int i = len; i > 1; i--) {
		Swap(&arr[1], &arr[i]);
		MaxHeapify(arr, 1, i - 1);
	}
}