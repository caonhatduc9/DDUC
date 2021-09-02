#include"function.h"
void createList(myList& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
node* createNode(int x)
{
	node* p = new node;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->pNext = NULL;
	return p;
}
void addTail(myList& l, node* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void loadFile(myList& l)
{
	ifstream f;
	f.open("fileIn4.txt");
	while (!f.eof())
	{
		int x;
		f >> x;
		if (f.eof())
			break;
		node* p = createNode(x);
		addTail(l, p);

	}
	f.close();
}
void insertNode(myList& l)
{
	int k = 1;

	node* p = createNode(2*k);
	p->pNext = l.pHead;
	l.pHead = p;
	for (node* i = l.pHead->pNext; i->pNext != NULL; i = i->pNext->pNext)
	{
		k++;
		node* q = createNode(2*k);
		q->pNext = i->pNext;
		i->pNext = q;
	}
	cout << endl;
}
void saveFile(myList l)
{
	ofstream f;
	f.open("FileOut4.txt");
	for (node* i = l.pHead; i != NULL; i = i->pNext)
	{
		f << i->data << " ";
	}
	f << "0";
	f.close();
}