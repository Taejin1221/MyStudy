typedef struct _ListNode {
	int val;
	struct _ListNode *next;
} ListNode, * ListNodePtr;

ListNodePtr CreateNode(int val) {
	ListNodePtr newNode = malloc(sizeof(ListNode));
	newNode->val = val;
	newNode->next = NULL;

	return newNode;
}

ListNodePtr mergeTwoLists(ListNodePtr l1, ListNodePtr l2) {
	if (!(l1 || l2))
		return NULL;
	else if (! l1)
		return l2;
	else if (! l2)
		return l1;
    
	ListNodePtr l3 = NULL;

	ListNodePtr currL1 = l1, currL2 = l2, currL3;
	if (currL1->val <= currL2->val) {
		l3 = CreateNode(l1->val);
		currL1 = currL1->next;
	} else {
		l3 = CreateNode(l2->val);
		currL2 = currL2->next;
	}

	currL3 = l3;
	while (currL1 && currL2) {
		if (currL1->val <= currL2->val) {
			currL3->next = CreateNode(currL1->val);
			currL1 = currL1->next;
		} else {
			currL3->next = CreateNode(currL2->val);
			currL2 = currL2->next;
		}
		currL3 = currL3->next;
	}

	for (; currL1; currL1 = currL1->next) {
		currL3->next = CreateNode(currL1->val);
		currL3 = currL3->next;
	}

	for ( ; currL2; currL2 = currL2->next) {
		currL3->next = CreateNode(currL2->val);
		currL3 = currL3->next;
	}

	return l3;
}
