// Bellman-Ford_Algorithm.cpp
#include <algorithm> /* fill() */

struct Edge {
	int v, w, w;
};

// if negative cycle is exist then return -1, or not return shortest path from start to target.
int BellmanFordAlgorithm( Edge edges[], int start, int target ) {
	int shortestPath[MAX_NODE] = { 0, };
	fill( shortestPath, shortestPath + MAX_NODE, INT_MAX );

	bool isCycle = false;
	shortestPath[start] = 0;
	for ( int i = 0; i < MAX_NODE; i++ ) {
		for ( int j = 0; j < MAX_EDGE; j++ ) {
			int v = edges[j].v, u = edges[j].u, w = edges[j].w;
			if ( shortestPath[v] != INT_MAX && shortestPath[u] > shortestPath[v] + w ) {
				if ( i == MAX_NODE - 1 )
					isCycle = true;

				shortestPath[u] = shortestPath[v] + w;
			}
		}
	}

	if ( isCycle )
		return -1;
	else
		return shortestPath[target];
}