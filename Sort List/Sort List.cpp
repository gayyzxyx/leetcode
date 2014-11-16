#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL){}
};

class Solution {
public:

	ListNode *sortList(ListNode *head) {	
		if(head == NULL || head->next == NULL) {
			return head;
		}
		ListNode *p = head, *q = head, *pre = NULL;
		while(q && q->next) {
			pre = p;
			p = p->next;
			q = q->next->next;
		}
		pre->next = NULL;				
		return mergeList(sortList(head), sortList(p));
	}

	ListNode *mergeList(ListNode *l, ListNode * r) {
		ListNode *p1, *p2, *result;
		if(l->val < r->val) {
			p1 = l;
			p2 = r;			
		} else {
			p1 = r;
			p2 = l;

		}
		result = p1;
		ListNode * pre;
		while(p1 && p2) {
			if(p1->val <= p2->val) {
				pre = p1;
				p1 = p1->next;
			} else {
				pre->next = p2;
				p2 = p2->next;
				pre = pre->next;
				pre->next = p1;
			}
		}
		if(p2) {
			pre->next = p2;
		}
		return result;
	}
	

};

ListNode *createList(int a[], int n) {
	ListNode *head = NULL, *p=NULL;
	for(int i = 0; i < n; i++) {
		if(head == NULL) {
			head = p = new ListNode(a[i]);
		} else {
			p->next = new ListNode(a[i]);
			p = p->next;
		}
	}
	return head;
}

void printList(ListNode *a) {
	while(a!=NULL) {
		printf("%d ", a->val);
		a = a->next;
	}
	printf("\n");
}

int main() {
	srand(time(NULL));
	int *a = new int[10];
	for(int i = 0; i<10; i++) {
		a[i] =  rand()%10+1;
	}
	Solution s;
	ListNode *p = createList(a, 10); 
	printList(p);
	ListNode *end;
	ListNode *q = s.sortList(p);
	printList(q);
	int b = 2, c = 3;
	printf("%d, %d", b, c);

}