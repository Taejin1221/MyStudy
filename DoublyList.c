#include <stdio.h>
#include <stdlib.h>
#include "DoublyList.h"

void InitHeader(DoublyListPtr header) {
	header->next = header;
	header->prev = header;
}

void InsertNode_First(DoublyListPtr header, Data item) {
	DoublyListPtr newNode = malloc(sizeof(DoublyList));
	newNode->data = item;
	
	// if list is empty
	if (header->next == header) {
		header->prev = newNode;
		header->next = newNode;
		newNode->next = newNode->prev = header;
	} else {
		newNode->prev = header;
		newNode->next = header->next;
		header->next = header->next->prev = newNode;
	}
}

void InsertNode_Last(DoublyListPtr header, Data item) {
	DoublyListPtr newNode = malloc(sizeof(DoublyList));
	newNode->data = item;
	
	// if list is empty
	if (header->next == header) {
		header->prev = newNode;
		header->next = newNode;
		newNode->prev = newNode->next = header;
	} else {
		newNode->prev = header->prev;
		newNode->next = header;
		header->prev = header->prev->next = newNode;
	}
}

DoublyListPtr Search(DoublyListPtr header, Data item) {
	for (DoublyListPtr p = header->next; p != header; p = p->next) {
		if (! CompareData(p->data, item))
			return p;
	}

	return NULL;
}

void PrintList(DoublyListPtr header) {
	for (DoublyListPtr p = header->next; p != header; p = p->next)
		PrintData(p->data);
	puts("NULL");
}

void PrintList_Reverse(DoublyListPtr header) {
	printf("Print List Reverse: ");
	for (DoublyListPtr p = header->prev; p != header; p = p->prev)
		PrintData(p->data);
	puts("NULL");
}
