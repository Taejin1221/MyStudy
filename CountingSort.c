 /* CountingSort.c */
void CountingSort(int arr[], int len, int max) {
	int* count = calloc(max + 1, sizeof(int));
	int idx = 0;
	
	for (int i = 0; i < len; i++)
		count[arr[i]]++;

	for (int i = 1; i <= max; i++)
		for (int j = 0; j < count[i]; j++)
			arr[idx++] = i;

	free(count);
}