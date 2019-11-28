// Graph.c
/* ========== Define ========== */
#define VISIT 1
#define UNVISIT 0

typedef struct _ListNode {
	int val;
	struct _ListNode* next;
} ListNode, * ListNodePtr;

typedef struct _AdjacentList {
	ListNodePtr vertexes[20];
	ListNodePtr end[20];
	int vertexSize;
} AdjacentList, * AdjacentListPtr;

typedef struct _QueueList {
	ListNodePtr front;
	ListNodePtr rare;
} QueueList, * QueueListPtr;
/* ============================ */

/* ========== Queue Function ========== */
void InitQueue(QueueListPtr queue) {
	queue->front = queue->rare = NULL;
}

int isEmpty(QueueListPtr queue) {
	return queue->front == NULL;
}

void Enqueue(QueueListPtr queue, int val) {
	ListNodePtr newNode = malloc(sizeof(ListNode));
	newNode->val = val;
	newNode->next = NULL;

	if (isEmpty(queue))
		queue->front = queue->rare = newNode;
	else {
		queue->rare->next = newNode;
		queue->rare = newNode;
	}
}

int Dequeue(QueueListPtr queue) {
	ListNodePtr remove = queue->front;
	int rtrnVal = remove->val;

	queue->front = queue->front->next;

	free(remove);

	return rtrnVal;
}
/* ==================================== */

/* ========== Graph Function ========== */
void InitAdjList(AdjacentListPtr adjList, int size) {
	adjList->vertexSize = size;
	for (int i = 0; i < size; i++) {
		adjList->vertexes[i] = adjList->end[i] = NULL;
	}
}

void InsertintoGraph(AdjacentListPtr adjList, int vertex, int edge) {
	// Create New Node
	ListNodePtr newNode = malloc(sizeof(ListNode));
	newNode->val = edge;
	newNode->next = NULL;

	// if adjlist is empty
	if (adjList->vertexes[vertex] == NULL) {
		adjList->vertexes[vertex] = adjList->end[vertex] = newNode;
	} else {
		// Add vertex
		adjList->end[vertex]->next = newNode;
		adjList->end[vertex] = newNode;
	}
}

void PrintGraph(AdjacentList adjList) {
	for (int i = 0; i < adjList.vertexSize; i++) {
		printf("V(%d) { ", i);
		for (ListNodePtr temp = adjList.vertexes[i]; temp; temp = temp->next)
			printf("[%d] -> ", temp->val);
		printf("NULL }\n");
	}
}

int visited_DFS[20];
void DFS_helper(AdjacentList adjList, int currVertex) {
	for (ListNodePtr temp = adjList.vertexes[currVertex]; temp; temp = temp->next) {
		int adjVertex = temp->val;
		if (visited_DFS[adjVertex] == UNVISIT) {
			visited_DFS[adjVertex] = VISIT;
			printf("[%d]->", adjVertex);
			DFS_helper(adjList, adjVertex);
		}
	}
}

void DFS(AdjacentList adjList) {
	for (int i = 0; i < adjList.vertexSize; i++)
		visited_DFS[i] = UNVISIT;

	for (int i = 0; i < adjList.vertexSize; i++)
		if (visited_DFS[i] == UNVISIT) {
			visited_DFS[i] = VISIT;
			printf("[%d]->", i);
			DFS_helper(adjList, i);
		}
}

void BFS(AdjacentList adjList) {
	QueueList queue;
	InitQueue(&queue);

	int visited_BFS[20] = { UNVISIT, };

	for (int i = 0; i < adjList.vertexSize; i++) {
		if (visited_BFS[i] == UNVISIT) {
			Enqueue(&queue, i);
			visited_BFS[i] = VISIT;
		}
		
		if (! isEmpty(&queue)) {
			int currVertex = Dequeue(&queue);
			printf("[%d]->", currVertex);
			for (ListNodePtr temp = adjList.vertexes[currVertex]; temp; temp = temp->next) {
				int adjVertex = temp->val;
				if (visited_BFS[adjVertex] == UNVISIT) {
					visited_BFS[adjVertex] = VISIT;
					Enqueue(&queue, adjVertex);
				}
			}
		}
	}

}
/* ==================================== */
