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

		ListNode* p = head;
		ListNode* q = head->next;
		int value = head->val;
		while(q){
			if(q->val < value) {
				p = p->next;
				swap(p->val, q->val);
			}
			q = q->next;
		}
		swap(p->val, value);
		return p;
	}

	void qsort(ListNode *he
		)
	void swap(int &a, int &b) {
		int temp = a;
		b = a;
		a = temp;
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
}

int main() {
	srand(time(NULL));
	int *a = new int[10];
	for(int i = 0; i<10; i++) {
		a[i] =  rand()%10+1;
	}
	ListNode *p = createList(a, 10);
	printList(p);
}