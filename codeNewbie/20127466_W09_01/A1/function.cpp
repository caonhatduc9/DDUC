#include"function.h"

node* createNode(int x) {
	node* p = new node;
	if (p == NULL)
		return NULL;
	p->pNext = NULL;
	p->data = x;
	return p;
}
void init(stack& s,int &capacity)
{
	s.pHead = NULL;
	capacity = s.capacity = 0;
}


void push(stack& s, node* p)
{
	if (p == NULL)
		return;
	if (isEmpty(s)==true)
	{
		s.pHead = p;
		s.capacity++;
	}
	else
	{
		p->pNext = s.pHead;
		s.pHead = p;
		s.capacity++;
	}
}

int pop(stack& s)
{
	int k;
	if (isEmpty(s) == true)
		return 0;
	else
	{
		node* p = s.pHead;
		k = p->data;
		s.pHead = s.pHead->pNext;
		delete p;
	}
	return k;
}
bool isEmpty(stack s) {
	if (s.pHead == NULL)
		return true;
	return false;
}
int sizeS(stack s)
{
	return s.capacity;
}
void printList(stack s)
{
	if (s.pHead == NULL)
	{
		cout << "\nNULL";
		return;
	}
	for (node* i = s.pHead; i != NULL; i = i->pNext)
	{
		cout << i->data << " ";
	}
}