#include<iostream>
using namespace std;

struct NODE {
	int key;
	NODE* pNext;
};
struct List {
	NODE* pHead;
	NODE* pTail;
};
NODE* createNode(int data)
{
	NODE* q = new NODE;
	if (q == NULL)
		return NULL;
	q->key = data;
	q->pNext = NULL;
	return q;
}
bool isEmpty(List* s)
{
	if (s->pHead == NULL)
		return true;
	return false;
}
void initStack(List*& s)
{
	s = new List;
	s->pHead = s->pTail = NULL;

}
void pushStack(List* &s, int data)
{
	if (isEmpty(s))
		s->pHead = s->pTail = createNode(data);
	else
	{
		NODE* q = createNode(data);
		q->pNext = s->pHead;
		s->pHead = q;
	}
}
int popStack(List* &s)
{
	int x;
	if (!isEmpty(s)){
		x = s->pHead->key;
		NODE* q = s->pHead;
		s->pHead = s->pHead->pNext;

		delete q;
		return x;
	}
}
int main(void) {
	List* stack;
	initStack(stack);
	for (int i = 0; i < 5; i++)
		pushStack(stack, i);
	for (int i = 0; i < 5; i++)
		cout << endl << popStack(stack);
	return 0;
}