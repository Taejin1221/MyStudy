// SegmentTree.cpp
#define MAX_ARR_SIZE
#define MAX_TREE_SIZE
#define NO_CARE

int arr[MAX_ARR_SIZE];
int tree[MAX_TREE_SIZE];

struct Range {
	int start, end;
	Range( int s, int e ): start(s), end(e) { }
	int getMid() {
		return ( start + end ) / 2;
	}
};

int Operator(int a, int b);
void MakeTree( int me, Range curr );
int GetSegment( int me, Range curr, Range& segment );
void UpdateTree( int me, Range curr, int& idx, int& value );

// 사용법
int main(void) {
	Range wholeRange = Range( 0, n - 1 );

	MakeTree( 1, wholeRange );

	// 구하려는 구간을 start, end에 저장
	Range segment = Range( start, end );
	int segValue = GetSegment( 1, wholeRange, segment );

	// idx를 value로 Update
	UpdateTree( 1, wholeRange, idx, value );

	return 0;
}

// Max Value Segment Tree면 max, 합이면 + 등 원하는 Operator 삽입
int Operator(int a, int b) {

}

void MakeTree( int me, Range curr ) {
	if ( curr.start == curr.end )
		tree[me] = arr[curr.start];
	else {
		int mid = curr.getMid();
		int left = me * 2, right = me * 2 + 1;

		MakeTree( left, Range( curr.start, mid ) );
		MakeTree( right, Range( mid + 1, curr.end ) );

		tree[me] = Operator( tree[left], tree[right] );
	}
}

int GetSegment( int me, Range curr, Range& segment ) {
	if ( segment.end < curr.start || curr.end < segment.start )
		return NO_CARE // max면 최솟값, 곱이면 1 등 신경 쓰지 않아도 되는 값
	else if ( segment.start <= curr.start && curr.end <= segment.end )
		return tree[me];
	else {
		int mid = curr.getMid();
		int left = me * 2, right = me * 2 + 1;

		return ( Operator(
			GetSegment( left, Range( curr.start, mid ), segment ),
			GetSegment( right, Range( mid + 1, curr.end ), segment )
			) );
	}
}

void UpdateTree( int me, Range curr, int& idx, int& value ) {
	if ( curr.start == curr.end && curr.start == idx )
		tree[me] = value;
	else if ( curr.end < idx || idx < curr.start )
		return;
	else {
		int mid = curr.getMid();
		int left = me * 2, right = me * 2 + 1;

		UpdateTree( left, Range( curr.start, mid ), idx, value );
		UpdateTree( right, Range( mid + 1, curr.end ), idx, value );

		tree[me] = Operator( tree[left], tree[right] );
	}
}