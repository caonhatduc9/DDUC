#include"function.h"
void initQueue(Queue& q, int capacity)
{
	q.phead = NULL;
	q.ptail = NULL;
	q.capacity = capacity;
}
node* createNode(int x) {
	node* p = new node;
	if (p == NULL)
	{
		cout << "error memory";
		return NULL;
	}
	p->data = x;
	p->pnext = NULL;
	return p;
}
bool isEmpty(Queue q)
{
	if (q.phead == NULL)
		return true;
	return false;
}
void enQueue(Queue& q, int x)
{
	if (q.capacity == 0) {
		cout << "FULL";
		return;
	}
	node* p = createNode(x);
	if (isEmpty(q))
		q.phead = q.ptail = p;
	else
	{
		q.ptail->pnext = p;
		q.ptail = p;
	}
	q.capacity--;
}
int deQueue(Queue &q)
{
	if (isEmpty(q))
		return NULL;
	else {
		int x = q.phead->data;
		node* temp = q.phead;
		q.phead = q.phead->pnext;
		delete temp;
		return x;
	}
}
void empTy(Queue& q)
{
	q.capacity = 0;
	node* temp;
	while (q.phead != NULL)
	{
		temp = q.phead;
		q.phead = q.phead->pnext;
		delete temp;
	}
	q.phead == NULL;
	q.ptail = NULL;
}
int sizeQueue(Queue q)
{
	int size = 0;
	while (q.phead != NULL)
	{
		size++;
		q.phead = q.phead->pnext;
	}
	return size;
}