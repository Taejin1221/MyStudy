char nums[1000][11];

bool Compare( char* str1, char* str2 ) {
	if ( strcmp( str1, str2 ) >= 0 )
		return true;
	else
		return false;
}

void MergeSort( int start, int end ) {
	if ( start < end) {
		int mid = ( start + end ) / 2;
		MergeSort( start, mid );
		MergeSort( mid + 1, end );
		Merge( start, mid, end );
	}
}

void Merge( int start, int mid, int end ) {
	char copyNums[1000][11];
	int originIdx = 0;
	for ( int i = 0; i < end - start; i++ )
		strcpy( copyNums[i], nums[originIdx++] );
	originIdx = 0;

	int leftIdx = 0, leftLen = mid + 1 - start;
	int rightIdx = ( end - mid ) + 1, rightLen = end - mid;
	while ( leftIdx < leftLen && rightIdx < rightLen ) {
		if ( strcmp( copyNums[leftIdx], copyNums[rightIdx] ) >= 0 )
			strcpy( nums[originIdx++], copyNums[leftIdx++] );
		else
			strcpy( nums[originIdx++], copyNums[rightIdx++] );
	}

	while ( leftIdx < leftLen )
		strcpy( nums[originIdx++], copyNums[leftIdx++] );
	while ( rightIdx < rightLen )
		strcpy( nums[originIdx++], copyNums[rightIdx++] );
}