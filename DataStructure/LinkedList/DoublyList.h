#include "Data.h"

typedef struct _DoublyList {
	Data data;
	struct _DoublyList * next;
	struct _DoublyList * prev;
} DoublyList, * DoublyListPtr;

void InitHeader(DoublyListPtr header);
void InsertNode_First(DoublyListPtr header, Data item);
void InsertNode_Last(DoublyListPtr header, Data item);
DoublyListPtr Search(DoublyListPtr header, Data item);
void PrintList(DoublyListPtr header);
void PrintList_Reverse(DoublyListPtr header);
