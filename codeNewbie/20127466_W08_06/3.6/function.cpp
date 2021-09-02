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
	f.open("fileIn6.txt");
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
	
void sumNode(myList l, myList &l1)
{
	node* p = createNode(l.pHead->data);
	addTail(l1, p);
	
	int sum = l.pHead->data;
	for (node* i = l.pHead->pNext; i!= NULL; i = i->pNext)
	{
		sum += i->data;
	
		 p = createNode(sum);
		addTail(l1, p);
	}
}

void saveFile(myList l)
{
	ofstream f;
	f.open("fileOut6.txt");
	for (node* i = l.pHead; i != NULL; i = i->pNext)
	{
		f << i->data << " ";
	}
	f << "0";
	f.close();
}