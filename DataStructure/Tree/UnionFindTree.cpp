// UnionFindTree.cpp
int parents[MAX_NODE_SIZE];

int Find( int target ) {
	return ( (parents[target] == target) ? target : Find(parents[target] ) );
}

void Union( int a, int b ) {
	int aParents = Find(a);
	int bParents = Find(b);

	if ( aParents < bParents)
		parents[bParents] = aParents;
	else
		parents[aParents] = bParents;
}