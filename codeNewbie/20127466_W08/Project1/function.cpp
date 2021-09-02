
#include"function.h"

void createList(myList& n)
{
	n.pHead = NULL;
	n.ptail = NULL;
}
node* createNode(int x) {
	node* p = new node;
	if (p == NULL)
	{
		cout << "error memory";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

void addTail(myList& n, node* p)
{
	if (n.pHead == NULL)
		n.pHead = n.ptail = p;
	else
	{
		n.ptail->pNext = p;
		n.ptail = p;
	}
}
void loadFile(myList& l)
{
	ifstream f;
	f.open("Text.txt");
	while (!f.eof())
	{
		int x;
		f >> x;
		if (x != 0)
		{
			node* p = createNode(x);
			addTail(l, p);
		}
	}
	f.close();
}
void printList(myList l)
{
	if (l.pHead == NULL)
	{
		cout << "\nNULL";
		return;
	}
	for (node* i = l.pHead; i != NULL; i = i->pNext)
	{
		cout << i->data << " ";
	}
}
void xoaNode(myList& l, int x)
{
	if (l.pHead->data == x)
	{
		node* p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
		return;
	}
	if (l.ptail->data == x)
		for (node* i = l.pHead; i != NULL; i = i->pNext)
		{
			if (i->pNext == l.ptail)
			{
				delete l.ptail;
				i->pNext = NULL;
				l.ptail = i;
				return;
			}

		}

	node* k = new node;
	for (node* i = l.pHead; i != NULL; i = i->pNext)
	{
		if (i->data == x)
		{
			k->pNext = i->pNext;
			delete i;
			return;
		}
		k = i;
	}
}

int findNode(myList l, int x)
{
	int cnt = 0;
	for (node* i = l.pHead; i != NULL; i = i->pNext)
	{
		if (i->data == x)
			cnt++;
	}
	return cnt;
}
void xoaNhieuNode(myList& l, int x)
{
	int k = findNode(l, x);
	for (int i = 0; i < k; i++)
	{
		xoaNode(l, x);
	}
}
void removeDup(myList& l)
{
	if (l.pHead == l.ptail)
		return;

	for (node* i = l.pHead; i != NULL; i = i->pNext)
	{
		if (i->data == i->pNext->data)
		{
			node* q = i->pNext;
			i->pNext = q->pNext;
			delete q;
		}

	}
}
void saveFile(myList l)
{
	ofstream f;
	f.open("outFile.txt");
	for (node* i = l.pHead; i != NULL; i = i->pNext)
	{
		f << i->data << " ";
	}
	f.close();
}