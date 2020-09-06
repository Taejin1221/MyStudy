// BubbleSort.cpp
#define SWAP( a, b ) { int temp = ( a ); ( a ) = ( b ); ( b ) = temp; }

void BubbleSort( int arr[], int size ) {
	for ( int i = size - 1; i > 0; i-- )
		for ( int j = 0; j < i; j++ )
			if ( arr[j] > arr[j + 1] )
				SWAP( arr[j], arr[j + 1] );
}