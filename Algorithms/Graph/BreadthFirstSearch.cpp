// BreadthFirstSearch.cpp
/* Breadth First Seach on Adjacent List with C++*/
#include <queue>

typedef int Node;

void BFS( int start ) {
	queue<Node> q;
	q.push( start );
	while ( !q.empty() ) {
		Node curr = q.front(); q.pop();

		for ( Node& next : adjList[curr] ) {
			if ( !visited[next.node] ) {
				visited[next.node] = true;
				q.push( Node( next.node ) );
			}
		}
	}
}