#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * Definition for singly-linked list.
 **/
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *p = head, *q = head->next;
		while(q!=NULL) {
			ListNode *q1 = q;
			ListNode *temp = head, *pre=NULL;
			while(temp != q){
				
				if(temp->val > q1->val && pre) {
					pre->next = q1;
					q1->next = temp;
					pre = q1;
					pre = temp;
					temp = temp->next;	
					break;				
				} else if(temp->val > q1->val && !pre) {
					temp->next = q1->next;
					q1->next = temp;
					pre = q1;
					p =  head = pre;
					break;
				}else {
					pre = temp;
					temp = temp->next;
				}
			}
			q = q->next;
		}
		return head;
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
	ListNode *q = s.insertionSortList(p);
	printList(p);
	int b = 2, c = 3;
	printf("%d, %d", b, c);
}