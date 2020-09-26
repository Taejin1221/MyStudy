#include "../../Data.h"

typedef struct _CircularList {
	Data data;
	struct _CircularList* next;
} CircularList, * CircularListPtr;

CircularListPtr InsertNode_First(CircularListPtr head, Data item);
CircularListPtr InsertNode_Last(CircularListPtr head, Data item);
CircularListPtr Search(CircularListPtr head, Data item);
int GetSize(CircularListPtr head);
void PrintList(CircularListPtr head);
