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
void addTail(myList & l, node *p)
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
	f.open("fileIn2.txt");
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


void removeDump(myList& l)
{
if (l.pHead == l.pTail)
		return;
	node* ptr1, * ptr2, * dup;
	ptr1 = l.pHead;

	while (ptr1 != NULL && ptr1->pNext != NULL)
	{
		ptr2 = ptr1;

		while (ptr2->pNext != NULL)
		{
	
			if (ptr1->data == ptr2->pNext->data)
			{
			
				dup = ptr2->pNext;
				ptr2->pNext = ptr2->pNext->pNext;
				delete dup;
			}
			else
				ptr2 = ptr2->pNext;
		}
		ptr1 = ptr1->pNext;
	}
}
void saveFile(myList l)
{
	ofstream f;
	f.open("FileOut2.txt");
	for (node* i = l.pHead; i != NULL; i = i->pNext)
	{
		f << i->data << " ";
	}
	f << "0";
	f.close();
}