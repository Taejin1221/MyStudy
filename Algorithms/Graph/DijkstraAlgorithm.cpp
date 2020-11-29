// DijkstraAlgorithm.cpp
/* struct Node {
	int vertex, weight;
	bool operator<( const Node& n2 ) {
		return weight > n2.weight;
	}
};
*/

int DijkstraAlgorithm(vector<vector<Node>>& adjList, int start, int end) {
	int shortestPath = 0;

	vector<bool> visited( adjList.size() );
	priority_queue<Node> pq;

	pq.push( Node( start, 0 ) );
	while ( !pq.empty() ) {
		Node curr = pq.top(); pq.pop();

		if ( curr.vertex == end ) {
			shortestPath = curr.weight;
			break;
		}

		if ( !visited[curr.vertex] ) {
			visited[curr.vertex] = true;

			for ( Node& adj : adjList[curr.vertex] ) {
				if ( !visited[adj.vertex] )
					pq.push( Node( adj.vertex, curr.weight + adj.weight ) );
			}
		}
	}

	return shortestPath;
}
