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

/*void DFS(AdjacentList adjList) {

}*/

void BFS(AdjacentList adjList) {
	QueueList queue;
	InitQueue(&queue);

	int visited[20] = { UNVISIT, };

	for (int i = 0; i < adjList.vertexSize; i++) {
		if (visited[i] == UNVISIT) {
			Enqueue(&queue, adjList.vertexes[i]->val);
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
	InitAdjList(&adjList, 5);

	InsertintoGraph(&adjList, 0, 1);
	InsertintoGraph(&adjList, 0, 2);
	InsertintoGraph(&adjList, 0, 4);
	InsertintoGraph(&adjList, 1, 0);
	InsertintoGraph(&adjList, 1, 3);
	InsertintoGraph(&adjList, 1, 4);
	InsertintoGraph(&adjList, 2, 0);
	InsertintoGraph(&adjList, 2, 4);
	InsertintoGraph(&adjList, 3, 1);
	InsertintoGraph(&adjList, 4, 0);
	InsertintoGraph(&adjList, 4, 1);
	InsertintoGraph(&adjList, 4, 2);

	PrintGraph(adjList);

	BFS(adjList);

	return 0;
}