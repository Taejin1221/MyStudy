# Graph.py
class Graph():
	VISIT = 1
	UNVISIT = 0

	def __init__(self, vertexNum):
		self.adjList = { vertex:[] for vertex in range(1, vertexNum + 1) }
		self.vertexNum = vertexNum


	#InsertEdge No Direction, No Weight
	def InsertEdge(self, vertex, adjVertex):
		self.adjList[vertex].append(adjVertex)
		self.adjList[vertex].sort()


	# InsertEdge Direction, Weight
	def InsertEdge_DW(self, vertex, adjVertex, weight):
		self.adjList[vertex].append((adjVertex, weight))


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


	# To use this method, use the InsertEdge_DW method
	def DijkstraAlgorithm(self, start):
		visited = { vertex: Graph.UNVISIT for vertex in range(1, self.vertexSize + 1) }
		shortest = { vertex: -1 for vertex in range(1, self.vertexSize + 1) }
		queue = []

		heappush(queue, (0, start))
		while (queue):
			prevWeight, prevVertex = heappop(queue)

			if (visited[prevVertex] is Graph.VISIT):
				continue

			shortest[prevVertex] = prevWeight
			visited[prevVertex] = Graph.VISIT

			for adjVertex, adjWeight in self.adjList[prevVertex]:
				if (visited[adjVertex] is Graph.UNVISIT):
					heappush(queue, (prevWeight + adjWeight, adjVertex))

		for short in shortest:
			if shortest[short] is -1:
				print('INF')
			else:
				print(shortest[short])	