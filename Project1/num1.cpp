#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct ListNode{
	int data;
	struct ListNode* link;
}ListNode;

typedef struct {
	ListNode* head;
}LinkedListType;

void init(LinkedListType* L) {
	L->head = NULL;
}

void traverse(ArrayList* L) {
	for (int i = 0; i < L->n; i++)
		printf("[%d] ", L->V[i]);
	printf("\n");
}

void add(ArrayList* L, int pos, int item) {
	for (int i = L->n - 1; i >= pos; i--)
		L->V[i + 1] = L->V[i];
	L->V[pos] = item;
	L->n++;
}

int remove(ArrayList* L, int pos) {
	int item = L->V[pos];
	for (int i = pos + 1; i <= L->n - 1; i++)
		L->V[i - 1] = L->V[i];
	L->n--;
	return item;
}

void main() {
	ArrayList list;
	init(&list);

	add(&list, 0, 10);	traverse(&list);
	add(&list, 0, 20);	traverse(&list);
	add(&list, 1, 30);	traverse(&list);
	add(&list, 1, 40);	traverse(&list);
	add(&list, 3, 50);	traverse(&list);

	getchar();
	remove(&list, 1); traverse(&list);
	remove(&list, 2); traverse(&list);
}