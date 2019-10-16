/* RadixSort.c */
// before use this sort, define max digit
#define MAX_DIGIT 

#define TRUE 1
#define FALSE 0

typedef struct _ListNode {
	int val;
	struct _ListNode * next;
} ListNode, * ListNodePtr;

typedef struct _Bucket {
	ListNodePtr front;
	ListNodePtr end;
} Bucket, * BucketPtr;

void PrintList(ListNodePtr head) {
	for (ListNodePtr curr = head; curr; curr = curr->next)
		printf("%d -> ", curr->val);
	puts("NULL");
}

ListNodePtr RadixSort(ListNodePtr head) {
	Bucket bucket[10] = { 0, };

	int digit = 1;
	for (int i = 0; i < MAX_DIGIT; i++) {
		for (int i = 0; i < 10; i++)
			bucket[i].front = bucket[i].end = NULL;

		for (ListNodePtr curr = head; curr; curr = curr->next) {
			BucketPtr bucCurr = &bucket[curr->val / digit % 10];
			// if bucCurr is null
			if (! bucCurr->front)
				bucCurr->front = bucCurr->end = curr;
			else {
				bucCurr->end->next = curr;
				bucCurr->end = bucCurr->end->next;
			}
		}

		BucketPtr bucPrev = &bucket[0];
		int isHead = TRUE;
		for (int i = 0; i < 10; i++) {
			BucketPtr bucCurr = &bucket[i];
			// if bucket is null then next
			if (! bucCurr->front) continue;
			else {
				if (isHead) {
					head = bucCurr->front;
					bucPrev = bucCurr;
					isHead = FALSE;
				} else {
					bucPrev->end->next = bucCurr->front;
					bucPrev = bucCurr;
				}
			}
		}
		bucPrev->end->next = NULL;
		PrintList(head);

		digit *= 10;
	}

	return head;
}