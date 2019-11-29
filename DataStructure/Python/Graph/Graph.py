# Graph.py
class Graph():
	VISIT = 1
	UNVISIT = 0

	def __init__(self, vertexNum):
		self.adjList = { vertex:[] for vertex in range(1, vertexNum + 1) }
		self.vertexNum = vertexNum


	def InsertEdge(self, vertex, adjVertex):
		self.adjList[vertex].append(adjVertex)
		self.adjList[vertex].sort()


	def DFS(self, startPoint):
		visited = { vertex:Graph.UNVISIT for vertex in range(1, self.vertexNum + 1) }

		def DFS_helper(currVertex): # @currVertex 현재 정점
			# @currAdjVertex 현재 정점에 인접해있는 정점
			for currAdjVertex in self.adjList[currVertex]:
				if (visited[currAdjVertex] is Graph.UNVISIT):
					visited[currAdjVertex] = Graph.VISIT
					print(currAdjVertex, end = ' ')
					DFS_helper(currAdjVertex)

		visited[startPoint] = Graph.VISIT
		print(startPoint, end = ' ')
		DFS_helper(startPoint)
		print('')


	def BFS(self, startPoint):
		visited = { vertex:Graph.UNVISIT for vertex in range(1, self.vertexNum + 1) }
		queue = []

		queue.append(startPoint)
		visited[startPoint] = Graph.VISIT
		print(startPoint, end = ' ')

		while (queue):
			# @currVertex 현재 정점
			currVertex = queue.pop(0)

			# @currAdjVertex 현재 정점에 인접해있는 정점
			for currAdjVertex in self.adjList[currVertex]:
				if (visited[currAdjVertex] is Graph.UNVISIT):
					visited[currAdjVertex] = Graph.VISIT
					print(currAdjVertex, end = ' ')
					queue.append(currAdjVertex)
		print('')