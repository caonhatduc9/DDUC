
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
	f.open("fileIn.txt");
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
void xoaNode2(myList& l, int x)
{
	/*if (l.pHead->data == x)
	{
		node* p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
	if (l.ptail->data == x)
		for (node* i = l.pHead; i != NULL; i = i->pNext)
		{
			if (i->pNext == l.ptail)
			{
				delete l.ptail;
				i->pNext = NULL;
				l.ptail = i;
				
			}

		}*/
		node* k = new node;
		for (node* i = l.pHead; i != NULL; i = i->pNext)
		{
			if (i->data == x&&i!=l.pHead&&i!=l.ptail)
			{
				node* temp = i;
				k->pNext = i->pNext;
				i = k;
				delete temp;

			}
			k = i;
		}
		if (l.pHead->data == x)
{
	node* p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;

}
if (l.ptail->data == x)
	for (node* i = l.pHead; i != NULL; i = i->pNext)
	{
		if (i->pNext == l.ptail)
		{
			delete l.ptail;
			i->pNext = NULL;
			l.ptail = i;
		}
	}
}
void xoaNode(myList& l, int x)
{
	if (l.pHead->data == x)
	{
		node* p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;

	}
	if (l.ptail->data == x)
		for (node* i = l.pHead; i != NULL; i = i->pNext)
		{
			if (i->pNext == l.ptail)
			{
				delete l.ptail;
				i->pNext = NULL;
				l.ptail = i;
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

void saveFile(myList l)
{
	ofstream f;
	f.open("fileOut.txt");
	for (node* i = l.pHead; i != NULL; i = i->pNext)
	{
		f << i->data << " ";
	}
	f << "0";
	f.close();
}