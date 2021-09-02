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
	f.open("fileIn3.txt");
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

void  reverseList(myList &l)
{
	node* temp = NULL, * current = l.pHead, * prev = NULL;
	l.pTail = l.pHead;
	while (current != NULL)
	{
		temp = current->pNext;
		current->pNext = prev;
		prev = current;
		current = temp;
	}
	l.pHead = prev;
	
}



void saveFile(myList l)
{
	ofstream f;
	f.open("FileOut3.txt");
	for (node* i = l.pHead; i != NULL; i = i->pNext)
	{
		f << i->data << " ";
	}
	f << "0";
	f.close();
}

