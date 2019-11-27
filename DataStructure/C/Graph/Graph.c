// Graph.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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


void InitQueue(QueueListPtr queue) {
	queue->front = queue->rare = NULL;
}

bool isEmpty(QueueListPtr queue) {
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

void PrintList(ListNodePtr head) {
	for (ListNodePtr curr = head; curr; curr = curr->next)
		printf("[%d]->", curr->val);
	printf("NULL\n");
}

/*void DFS(AdjacentList adjList) {

}*/

void BFS(AdjacentList adjList) {
	QueueList queue;
	InitQueue(&queue);

	int visited[20] = { UNVISIT, };

	for (int i = 0; i < adjList.vertexSize; i++) {
		if (visited[i] == UNVISIT) {
			Enqueue(&queue, i);
			visited[i] = VISIT;
		}
		if (! isEmpty(&queue)) {
			int currVertex = Dequeue(&queue);
			printf("[%d]->", currVertex);
			for (ListNodePtr temp = adjList.vertexes[currVertex]; temp; temp = temp->next) {
				int adjVertex = temp->val;
				if (visited[adjVertex] == UNVISIT) {
					visited[adjVertex] = VISIT;
					Enqueue(&queue, adjVertex);
				}
			}
		}
	}

}

int main(void) {
	AdjacentList adjList;
	AdjacentListPtr adjListPtr = &adjList;

	// InitAdjList(&adjList, 5);

	// InsertintoGraph(&adjList, 0, 1);
	// InsertintoGraph(&adjList, 0, 2);
	// InsertintoGraph(&adjList, 0, 4);
	// InsertintoGraph(&adjList, 1, 0);
	// InsertintoGraph(&adjList, 1, 3);
	// InsertintoGraph(&adjList, 1, 4);
	// InsertintoGraph(&adjList, 2, 0);
	// InsertintoGraph(&adjList, 2, 4);
	// InsertintoGraph(&adjList, 3, 1);
	// InsertintoGraph(&adjList, 4, 0);
	// InsertintoGraph(&adjList, 4, 1);
	// InsertintoGraph(&adjList, 4, 2);

	InitAdjList(adjListPtr, 7);

	InsertintoGraph(adjListPtr, 0, 1);
	InsertintoGraph(adjListPtr, 0, 4);
	InsertintoGraph(adjListPtr, 1, 0);
	InsertintoGraph(adjListPtr, 1, 2);
	InsertintoGraph(adjListPtr, 1, 3);
	InsertintoGraph(adjListPtr, 2, 1);
	InsertintoGraph(adjListPtr, 2, 5);
	InsertintoGraph(adjListPtr, 3, 1);
	InsertintoGraph(adjListPtr, 3, 4);
	InsertintoGraph(adjListPtr, 3, 5);
	InsertintoGraph(adjListPtr, 3, 6);
	InsertintoGraph(adjListPtr, 4, 0);
	InsertintoGraph(adjListPtr, 4, 3);
	InsertintoGraph(adjListPtr, 4, 6);
	InsertintoGraph(adjListPtr, 5, 2);
	InsertintoGraph(adjListPtr, 5, 3);
	InsertintoGraph(adjListPtr, 5, 6);
	InsertintoGraph(adjListPtr, 6, 3);
	InsertintoGraph(adjListPtr, 6, 4);
	InsertintoGraph(adjListPtr, 6, 5);

	PrintGraph(adjList);

	BFS(adjList); puts("");

	return 0;
}