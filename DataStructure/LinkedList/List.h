#include "Data.h"

typedef struct _ListNode {
	Data data;
	struct _ListNode * next;
} ListNode, * ListNodePtr;

ListNodePtr InsertNode_Sorted(ListNodePtr head, Data item);
ListNodePtr InsertNode_Last(ListNodePtr head, Data item);
ListNodePtr DeleteNode_value(ListNodePtr head, Data item);
ListNodePtr DeleteNode_odd(ListNodePtr head);
Data Max(ListNodePtr head);
int Sum(ListNodePtr head);
int GetLength(ListNodePtr head);
int Frequency(ListNodePtr head, Data item);
ListNodePtr Alternate(ListNodePtr A, ListNodePtr B);
void Split(ListNodePtr headSrc, ListNodePtr* headDst1, ListNodePtr* headDst2);
ListNodePtr Merge(ListNodePtr A, ListNodePtr B);
void PrintList(ListNodePtr head);
