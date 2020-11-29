// PrimAlgorithm.cpp

/*
struct Node {
	int vertex, weight;
	bool operator<( const Node& n2 ) {
		return weight > n2.weight;
	}
};
*/

int PrimAlgorithm(vector<vector<Node>>& adjList, int start) {
	int mst = 0, connectedVertex = 1;

	vector<bool> visited( adjList.size() );
	priority_queue<Node> pq;

	pq.push( Node( start, 0 ) );
	while ( !pq.empty() && connectedVertex < adjList.size() ) {
		Node curr = pq.top(); pq.pop();

		if ( !visited[curr.vertex] ) {
			visited[curr.vertex] = true;

			mst += curr.weight;
			connectedVertex++;

			for ( Node& adj : adjList[curr.vertex] ) {
				if ( !visited[adj.vertex] )
					pq.push( Node( adj.vertex, adj.weight ) );
			}
		}
	}

	return mst;
}
