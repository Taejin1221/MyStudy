/* PriorityQueue.c */
void BuildMaxHeap(int heap[], int size);

void heapify(int heap[], int size);

void Enqueue(int queue[], int* size, int data) {
	int me = *size;
	queue[(*size)++] = data;
	for ( ; (queue[me / 2] <= queue[me]) && (me != 1); me /= 2)
		swap(&queue[me / 2], &queue[me]);
}

int Dequeue(int queue[], int* size) {
	int rtrn = queue[1];
	queue[1] = queue[--(*size)];

	heapify(queue, 1, *size);

	return rtrn;
}

void PrintQueue(int queue[], int size) {
	printf("[ ");
	for (int i = 1; i < size; i++)
		printf("%d ", queue[i]);
	printf(" ]\n");
}