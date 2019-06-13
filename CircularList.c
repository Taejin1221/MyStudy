#include <stdio.h>
#include <stdlib.h>
#include "CircularList.h"

CircularListPtr InsertNode_First(CircularListPtr head, Data item) {
	CircularListPtr newNode = malloc(sizeof(CircularList));
	newNode->data = item;

	if (! head) {
		head = newNode;
		newNode->next = head;
		return head;
	}

	newNode->next = head->next;
	head->next = newNode;

	return head;
}

CircularListPtr InsertNode_Last(CircularListPtr head, Data item) {
	CircularListPtr newNode = malloc(sizeof(CircularList));
	newNode->data = item;

	if (! head) {
		head = newNode;
		newNode->next = head;
		return head;
	}

	newNode->next = head->next;
	head->next = newNode;
	head = head->next;

	return head;
}

CircularListPtr Search(CircularListPtr head, Data item) {
	CircularListPtr p = head->next;
	do {
		if (! CompareData(p->data, item)) return p;
		else p = p->next;
	} while (p != head->next);

	return NULL;
}

int GetSize(CircularListPtr head) {
	int size = 0;

	CircularListPtr p = head->next;
	do {
		size++;
		p = p->next;
	} while (p != head->next);


	return size;
}

void PrintList(CircularListPtr head) {
	CircularListPtr p = head->next;
	do {
		PrintData(p->data);
		p = p->next;
	} while (p != head->next);
	puts("NULL");
}