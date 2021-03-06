// InsertionSort.cpp
void InsertionSort( int arr[], int size ) {
	for ( int i = 1; i < size; i++ ) {
		int j, value = arr[i];
		for ( j = i - 1; (j >= 0) && (arr[j] > value); j-- )
			arr[j + 1] = arr[j];
		arr[j + 1] = value;
	}
}