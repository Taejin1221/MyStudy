// SelectionSort.cpp
void SelectionSort( int arr[], int size ) {
	for ( int i = size - 1; i > 0; i-- ) {
		int maxIdx = 0;
		for ( int j = 1; j <= i; j++ )
			if ( arr[maxIdx] < arr[j] )
				maxIdx = j;

		int temp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;
	}
}