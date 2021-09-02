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
	f.open("fileIn5.txt");
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
void insertAscending(myList& l, node* p)
{
	if (p->data < l.pHead->data)
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
	else if (p->data > l.pTail->data)
		addTail(l, p);
	else {
		for (node* i = l.pHead; i->pNext != NULL; i = i->pNext)
		{
			if (p->data < i->pNext->data)
			{
				p->pNext = i->pNext;
				i->pNext = p;
				return;
			}
		}
	}
}
void saveFile(myList l)
{
	ofstream f;
	f.open("FileOut5.txt");
	for (node* i = l.pHead; i != NULL; i = i->pNext)
	{
		f << i->data << " ";
	}
	f << "0";
	f.close();
}