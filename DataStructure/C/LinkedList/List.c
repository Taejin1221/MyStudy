#include <stdio.h>
#include <stdlib.h>
#include "List.h"

ListNodePtr InsertNode_Sorted(ListNodePtr head, Data item) {
	ListNodePtr newNode = malloc(sizeof(ListNode));
	newNode->data = item;

	// if list is empty
	if (head == NULL) {
		head = newNode;
		newNode->next = NULL;
		return head;
	}

	ListNodePtr prev = head;
	for (ListNodePtr p = head; p; p = p->next) {
		if (p->data.num > newNode->data.num) {
			if (p == head) {
				newNode->next = head;
				head = newNode;
				return head;
			}
			else {
				newNode->next = prev->next;
				prev->next = newNode;
				return head;
			}
		}
		else {
			prev = p;
		}
	}

	// Insert Last
	prev->next = newNode;
	newNode->next = NULL;
	return head;
}

ListNodePtr InsertNode_Last(ListNodePtr head, Data item) {
	ListNodePtr newNode = malloc(sizeof(ListNode));
	newNode->data = item;
	newNode->next = NULL;

	if (head == NULL) {
		head = newNode;
		return head;
	}

	ListNodePtr p;
	for (p = head; p->next; p = p->next);

	p->next = newNode;

	return head;
}

ListNodePtr DeleteNode_value(ListNodePtr head, Data item) {
	ListNodePtr removed;

	ListNodePtr prev = head;
	for (ListNodePtr p = head; p; p = p->next) {
		int comp = CompareData(p->data, item);
		if (comp == 0) {
			removed = p;
			if (p == head)
				head = removed->next;
			else
				prev->next = removed->next;
			free(removed);

			return head;
		}
		else
			prev = p; 
	}
}

ListNodePtr DeleteNode_odd(ListNodePtr head) {
	ListNodePtr prev;
	for (ListNodePtr p = head; p; p = p->next) {
		ListNodePtr removed;
		removed = p;
		p = p->next;
		
		if (removed == head)
			head = removed->next;
		else
			prev->next = removed->next;
		free(removed);

		prev = p;

		if (!p)
			break;
	}

	return head;
}

Data Max(ListNodePtr head) {
	Data max;

	max = head->data;
	for (ListNodePtr p = head->next; p; p = p->next) {
		if (CompareData(max ,p->data) < 0)
			max = p->data;
	}

	return max;
}

int Sum(ListNodePtr head) {
	int sum = 0;

	for (ListNodePtr p = head; p; p = p->next)
		sum += p->data.num;

	return sum;
}

int GetLength(ListNodePtr head) {
	int len = 0;

	for (ListNodePtr p = head; p; p = p->next)
		len++;

	return len;
}

int Frequency(ListNodePtr head, Data item) {
	int frqc = 0;

	for (ListNodePtr p = head; p; p = p->next)
		if (! CompareData(item, p->data))
			frqc++;

	return frqc;
}

ListNodePtr Alternate(ListNodePtr A, ListNodePtr B) {
	ListNodePtr a = A;
	ListNodePtr b = B;
	ListNodePtr C;

	int count = 1;

	while (a && b) {
		if (count) {
			C = InsertNode_Last(C, a->data);
			a = a->next;
			count = 0;
		}
		else {
			C = InsertNode_Last(C, b->data);
			b = b->next;
			count = 1;
		}
	}

	for (; a; a = a->next)
		C = InsertNode_Last(C, a->data);

	for (; b; b = b->next)
		C = InsertNode_Last(C, b->data);

	return C;
}

void Split(ListNodePtr headSrc, ListNodePtr* headDst1, ListNodePtr* headDst2) {
	ListNodePtr A = NULL;
	ListNodePtr B = NULL;
	ListNodePtr src = headSrc;

	int count = 1;

	while (src) {
		if (count) {
			A = InsertNode_Last(A, src->data);
			count = 0;
		}
		else {
			B = InsertNode_Last(B, src->data);
			count = 1;
		}

		src = src->next;
	}

	*headDst1 = A;
	*headDst2 = B;
}

ListNodePtr Merge(ListNodePtr A, ListNodePtr B) {
	ListNodePtr C = NULL;
	ListNodePtr a = A;
	ListNodePtr b = B;

	while (a && b) {
		int comp = CompareData(a->data, b->data);
		if (comp < 0) {
			C = InsertNode_Last(C, a->data);
			a = a->next;
		} else if (comp > 0) {
			C = InsertNode_Last(C, b->data);
			b = b->next;
		} else {
			C = InsertNode_Last(C, a->data);
			C = InsertNode_Last(C, b->data);
			a = a->next; b = b->next;
		}
	}

	for ( ; a; a = a->next)
		C = InsertNode_Last(C, a->data);
	for ( ; b; b = b->next)
		C = InsertNode_Last(C, b->data);

	return C;
}

void PrintList(ListNodePtr head) {
	for (ListNodePtr p = head; p; p = p->next)
		PrintData(p->data);
	puts("NULL");
}
