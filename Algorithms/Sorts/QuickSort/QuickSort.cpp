// QuickSort.cpp
void Swap( int* i, int* j ) {
	int temp = *i;
	*i = *j;
	*j = temp;
}

int Partition( int arr[], int start, int end ) {
	int pivot = arr[end];

	int midIdx = start;
	for ( int i = start; i < end; i++ )
		if ( arr[i] < pivot )
			Swap( arr + i, arr + midIdx++ );

	arr[end] = arr[midIdx];
	arr[midIdx] = pivot;

	return midIdx;
}

void QuickSort( int arr[], int start, int end ) {
	if ( start < end ) {
		int mid = Partition( arr, start, end );
		QuickSort( arr, start, mid - 1 );
		QuickSort( arr, mid + 1, end );
	}
}