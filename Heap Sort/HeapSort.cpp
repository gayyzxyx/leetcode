#include <stdio.h>
#include <stdlib.h>
struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;
#define MINDATA -65536

struct HeapStruct {
	int capacity;
	int size;
	int *elements;
};

PriorityQueue Initialize(int maxElements) {
	PriorityQueue H =  new struct HeapStruct;
	H->elements = (int *)malloc(sizeof(int) * (maxElements + 1));
	H->capacity = maxElements;
	H->size = 0;
	H->elements[0] = MINDATA;
	return H;
}

void insert(int x, PriorityQueue q) {
	int i;
	for(i=++q->size; q->elements[i/2] > x; i /= 2) {
		q->elements[i] = q->elements[i/2];
	}
	q->elements[i] = x;
}

int deleteMin(PriorityQueue q) {
	int i, child;
	int minElement, lastElement;
	minElement = q->elements[1];
	lastElement = q->elements[q->size--];
	for(i = 1; i * 2 <= q->size; i = child) {
		child = i * 2;
		if(child != q->size && q->elements[child] > q->elements[child+1]) {
			child++;
		}
		if(lastElement > q->elements[child]) {
			q->elements[i] = q->elements[child];
		} else {
			break;
		}
	}
	q->elements[i] = lastElement;
	return minElement;
}

int main() {
	PriorityQueue q = Initialize(5);
	insert(4, q);
	insert(24, q);
	insert(44, q);
	insert(34, q);
	insert(14, q);
	for(int i = 0; i<5; i++) {
		printf("%d ", deleteMin(q));
	}
}