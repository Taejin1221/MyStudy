// Graph.c
typedef struct _ListNode {
	int val;
	struct _ListNode* next;
} ListNode, * ListNodePtr;

typedef struct _AdjacentList {
	ListNodePtr vertexes[20];
	int vertexSize;
} AdjacentList, * AdjacentListPtr;

void InsertintoGraph(AdjacentListPtr adjList, int vertex, int edge);
void PrintGraph(AdjacentList adjList);
void DFS(AdjacentList adjList);
void BFS(AdjacentList adjList);