// Graph.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isEmpty(QueueList queue) {
	return queue.front == NULL;
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

	queue->front = queue->front->next;

	free(remove);
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

void DFS(AdjacentList adjList) {

}

void BFS(AdjacentList adjList) {
	QueueList queue;
	InitQueue(&queue);

	Enqueue(&queue, adjlist.vertex[0].val)
	while (! isEmpty()) {
		adjlist.vertex[Dequeue(&queue)].val
	}

}

void main(void) {
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
}