/*
 * File Name: Floyd-Warshall_Algorithm.cpp
 * Author: Taejin, An
 * Date: 01/04/2021
 * Description: C++ Code of Floyd-Warshall Algorithm
 */

// Input is AdjacentMatrix, output is Shortest Path from i to j
vector<vector<int>> FloydWarshallAlgorithm( vector<vector<int>>& adjMatrix ) {
	int vertexSize = adjMatrix.size();

	vector<vector<int>> shortestMatrix;
	for ( int i = 0; i < vertexSize; i++ ) {
		shortestMatrix.push_back( vector<int> () );
		for ( int j = 0; j < vertexSize; j++ ) {
			if ( adjMatrix[i][j] == 0 )
				shortestMatrix[i].push_back( INT_MAX );
			else
				shortestMatrix[i].push_back( adjMatrix[i][j] );
		}
	}

	for ( int k = 1; k <= vertexSize; k++ )
		for ( int i = 1; i <= vertexSize; i++ )
			for ( int j = 1; j <= vertexSize; j++ )
				if ( i != j )
					if ( shortestMatrix[i][j] > shortestMatrix[i][k] + shortestMatrix[k][j] )
						shortestMatrix[i][j] = shortestMatrix[i][k] + shortestMatrix[k][j];

	return shortestMatrix;
}