#include<iostream>
using namespace std;

struct node {
	int data;
	node* pNext;
};

struct myList {
	node* pHead;
	node* ptail;
};
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
//add node linklist
void addHead(myList& n, node* p)
{
	//list empty
	if (n.pHead == NULL)
		n.pHead = n.ptail = p;
	else
	{
		p->pNext = n.pHead;
		n.pHead = p;
	}
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

void xoaDau(myList& l)
{
	if (l.pHead == NULL)
		return;
	node* p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
}
void xoaCuoi(myList& l)
{
	if (l.pHead == NULL)
		return;
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
void xoaSauMotNode(myList& l, node* q)
{
	for (node* i = l.pHead; i != NULL; i = i->pNext)
	{
		if (i->data == q->data)
		{
			node* temp = i->pNext;
			i->pNext = temp->pNext;
			delete temp;
		}
	}
}
void delAll(myList& l)
{
	node* temp;
	while (l.pHead != NULL)
	{
		temp = l.pHead;
		l.pHead = l.pHead->pNext;
		delete temp;
	}
}
int main()
{
	myList l;
	createList(l);
	int n;
	node* p1, * p2;
	int xh, xt;
	cout << "nhap so luong node can them: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cout << "nhap gia tri: ";
		cin >> x;
		node* p = createNode(x);
		addTail(l, p);
	}
	printList(l);

	cout << "\nthem dau: ";
	cin >> xh;
	p1 = createNode(xh);
	addHead(l, p1);

	cout << "them cuoi: ";
	cin >> xt;
	p2 = createNode(xt);
	addTail(l, p2);

	printList(l);
	cout << "\n=================\n";

	cout << "\ndanh sach sau khi xoa dau: ";
	xoaDau(l);
	printList(l);

	cout << "\ndanh sach sau khi xoa cuoi: ";
	xoaCuoi(l);
	printList(l);

	cout << "\nnhap node truoc node can xoa: ";
	int x;
	cin >> x;
	node* q3 = createNode(x);
	xoaSauMotNode(l, q3);
	cout << "\ndanh sach sau khi xoa : ";
	printList(l);

	cout << "\n danh sach sau khi xoa all: ";
	delAll(l);
	printList(l);
	return 0;
}