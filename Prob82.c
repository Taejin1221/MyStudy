// Prob82.c

typedef struct _ListNode {
	int val;
	struct _ListNode* next;
} ListNode, * ListNodePtr;

ListNodePtr deleteDuplicates(ListNodePtr head) {
	ListNodePtr pre = head, curr = head;

	while (curr && curr->next) {
		if (curr->val == curr->next->val) {
			int target = curr->val;
			while (curr && curr->val == target) { // if list is null, then break while
                // If Remove Node is First Node 
				if (curr == head) { // if pre is null, then head points curr
                    head = curr->next;
                    pre = head;
                } else pre->next = curr->next;
				ListNodePtr remove = curr;
				curr = curr->next;

				free(remove);
			}
		} else {
			pre = curr;
			curr = curr->next;
		}
	}

	return head;
}