// DepthFirstSearch.cpp
/* Depth First Search on Adjacent List with C++*/
typedef int Node;

void DFS( Node curr ) {
	for ( Node& next : adjList[curr] ) {
		if ( !visited[next] ) {
			visited[next] = true;
			DFS( next );
		}
	}
}