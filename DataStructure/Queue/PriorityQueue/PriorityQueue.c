/* PriorityQueue.c */
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

void Enqueue(int queue[], int* size, int data) {
	int me = *size;
	queue[(*size)++] = data;
	for ( ; (queue[me / 2] <= queue[me]) && (me != 1); me /= 2)
		swap(&queue[me / 2], &queue[me]);
}

int Dequeue(int queue[], int* size) {
	int rtrn = queue[1];
	queue[1] = queue[--(*size)];

	MaxHeapify(queue, 1, *size);

	return rtrn;
}

void PrintQueue(int queue[], int size) {
	printf("[ ");
	for (int i = 1; i < size; i++)
		printf("%d ", queue[i]);
	printf(" ]\n");
}