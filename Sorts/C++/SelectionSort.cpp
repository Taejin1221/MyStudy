// SelectionSort.cpp
#define SWAP( a, b ) { int temp = ( a ); ( a ) = ( b ); ( b ) = temp; }

void SelectionSort( int arr[], int size ) {
	for ( int i = size - 1; i > 0; i-- ) {
		int maxIdx = 0;
		for ( int j = 1; j <= i; j++ )
			if ( arr[maxIdx] < arr[j] )
				maxIdx = j;

		SWAP( arr[i], arr[maxIdx] );
	}
}