#include<iostream>
using namespace std;

struct NODE {
	int key;
	NODE* pNext;
	NODE* pPrev;
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
	q->pPrev = NULL;
	return q;
}
void createList(List*& l)
{
	l = new List;
	l->pHead = l->pTail = NULL;
}
bool addHead(List*& l, int data)
{
	NODE* q = createNode(data);
	if (q == NULL)
		return false;
	if (l->pHead == NULL)
		l->pHead = l->pTail = q;
	else {
		q->pNext = l->pHead;
		l->pHead->pPrev = q;
		l->pHead = q;
	}
	return true;
}
bool addTail(List*& l, int data)
{
	NODE* q = createNode(data);
	if (q == NULL)
		return false;
	if (l->pHead == NULL)
	{
		l->pHead = l->pTail = q;
	}
	else {
		l->pTail->pNext = q;
		q->pPrev = l->pTail;
		l->pTail = q;
	}
	return true;
}
void removeHead(List*& l)
{
	if (l->pHead == NULL)
		return;
	NODE* q = l->pHead;
	l->pHead = l->pHead->pNext;
	l->pHead->pPrev = NULL;
	delete q;
}
void removeTail(List*& l)
{
	if (l->pHead == NULL)
		return;
	NODE* q = l->pTail;
	l->pTail = l->pTail->pPrev;
	l->pTail->pNext = NULL;
	delete q;
}
void removeAllNode(List*& l) {
	if (l->pHead == NULL)
		return;
	else
	{
		NODE* temp;
		while (l->pHead != NULL)
		{
			temp = l->pHead;
			l->pHead = l->pHead->pNext;
			if (l->pHead == NULL)
				return;
			l->pHead->pPrev = NULL;
			delete temp;
		}
	}
}
void removeBefore(List*& l, int val)
{
	if (l->pHead->pNext->key == val)
		removeHead(l);
	if (l->pHead->key == val)
		return;
	else {
		NODE* i;
		for (i = l->pHead; i->pNext != NULL; i = i->pNext)
			if (i->pNext->key == val)
			{

				i->pPrev->pNext = i->pNext;
				i->pNext->pPrev = i->pPrev;
				delete i;
				break;
			}

	}
}
void removeAfter(List*& l, int val)
{
	if (l->pTail->key == val)
		return;
	NODE* i;
	for (i = l->pHead->pNext; i != NULL; i = i->pNext)
		if (i->pPrev->key == val)
			break;
	if (i == l->pTail)
		removeTail(l);
	else
	{
		i->pPrev->pNext = i->pNext;
		i->pNext->pPrev = i->pPrev;
		delete i;
	}
}
void showList(List* l)
{
	if (l->pHead == NULL)
		cout << "\aempty\n";
	else
		for (NODE* i = l->pHead; i != NULL; i = i->pNext)
			cout << i->key << "\t";
}
int countElements(List* l)
{
	int n = 0;
	for (NODE* i = l->pHead; i != NULL; i = i->pNext)
		n++;
	return n;
}
bool addPos(List*& l, int data, int pos)
{
	int dem = 0, n = 0;
	n = countElements(l);
	if (n < 1)
		return false;
	if (pos == 1)
		addHead(l, data);
	else if (pos >= n + 1)
		addTail(l, data);
	else {
		for (NODE* i = l->pHead; i != NULL; i = i->pNext)
		{
			dem++;
			if (pos == dem)
			{
				NODE* q = createNode(data);
				i->pPrev->pNext = q;
				q->pNext = i;
			}
		}
	}
	return true;
}

void RemovePos(List*& l, int pos)
{
	int dem = 0, n = 0;
	n = countElements(l);
	if (pos < 1)
		return;
	if (pos == 1)
	{
		removeHead(l);
		return;
	}
	if (pos >= n)
	{
		removeTail(l);
		return;
	}

	for (NODE* i = l->pHead; i != NULL; i = i->pNext)
	{
		dem++;
		if (dem == pos)
		{
			i->pPrev->pNext = i->pNext;
			i->pNext->pPrev = i->pPrev;
			delete i;
			break;
		}
	}
}

bool addBefore(List*& l, int data, int val)
{
	if (l->pHead == NULL)
		return false;
	if (val == l->pHead->key)
	{
		addHead(l, data);
		return true;
	}
	NODE* i;
	for (i = l->pHead; i != NULL; i = i->pNext)
	{
		if (i->key == val)
		{
			NODE* q = createNode(data);
			i->pPrev->pNext = q;
			q->pPrev = i->pPrev;
			q->pNext = i;
			i->pPrev = q;
			return true;
		}
	}
	return false;
}

bool addAfter(List*& l, int data, int val)
{
	if (val == l->pTail->key)
	{
		addTail(l, data);
		return true;
	}
	NODE* i;
	for (i = l->pHead; i != NULL; i = i->pNext)
	{
		if (i->key == val)
		{
			NODE* q = createNode(data);
			q->pNext = i->pNext;
			i->pNext = q;
			q->pPrev = i;
			q->pNext->pPrev = q;
			return true;
		}
	}
	return false;
}
void showTail(List* l)
{
	cout << endl;
	for (NODE* i = l->pTail; i != NULL; i = i->pPrev)
		cout << i->key << "\t";
}
List* reverseList(List* l)
{
	List* l1;
	createList(l1);
	for (NODE* i = l->pHead; i != NULL; i = i->pNext)
	{
		addHead(l1, i->key);
	}
	return l1;
}
void removeDuplicate(List*& l)
{
	NODE* ptr1, * ptr2, * dup;

	for (ptr1 = l->pHead; ptr1 != NULL && ptr1->pNext != NULL; ptr1 = ptr1->pNext)
	{
		for (ptr2 = ptr1->pNext; ptr2 != NULL; ptr2 = ptr2->pNext)
		{
			if (ptr2->key == ptr1->key)
			{
				if (ptr2 == l->pTail)
				{
					removeTail(l);
					break;
				}
				else {
					NODE* q = ptr2;
					ptr2->pPrev->pNext = ptr2->pNext;
					ptr2->pNext->pPrev = ptr2->pPrev;
					ptr2 = q->pPrev;
					delete q;
				}
			}
		}
	}
}
bool removeElement(List*& l, int key)
{
	if (l->pHead == NULL)
		return false;
	for (NODE* i = l->pHead; i != NULL; i = i->pNext)
	{
		if (i->key == key)
		{
			if (i == l->pTail)
			{
				removeTail(l);
				break;
			}
			if (i == l->pHead)
			{
				removeHead(l);
				break;
			}
			else {
				NODE* q = i;
				i->pPrev->pNext = i->pNext;
				i->pNext->pPrev = i->pPrev;
				i = q->pPrev;
				delete q;
			}
		}
	}
	return true;
}
void menu(List* l)
{
	while (1) {
		cout << "\n1 create Node\n2 create List\n3 add head:\n4 add tail\n5 remove head\n6 remove tail\n7 remove all";
		cout << "\n8 remove before\n9 remove after\n10 add pos\n11 remove pos\n12 add before\n13 add after";
		cout << "\n14 printf list\n15 count element\n16 reverse list\n17 remove Duplicate\n18 remove element";
		cout << "\n\t\t0 quit : ";
		int choice, x;
		cin >> choice;
		if (choice == 1)
		{
			int x;
			cin >> x;
			createNode(x);
		}
		else if (choice == 2)
		{
			createList(l);
			//	print_LNR(pRoot);
		}
		else if (choice == 3) 
		{
			cout << "nhap: x: ";
			cin >> x;
			addHead(l, x);
		}
		else if (choice == 4) {
			cout << "nhap x: ";
			cin >> x;
			addTail(l, x);
		}
		else if (choice == 5)
			removeHead(l);
		else if (choice == 6)
		{
			removeTail(l);
		}
		else if (choice == 7)
		{
			removeAllNode(l);
		}
		else if (choice == 8)
		{
			cout << "nhap x: ";
			cin >> x;
			removeBefore(l, x);
		}
		else if (choice == 9)
		{
			cout << "nhap x: ";
			cin >> x;
			removeAfter(l, x);
		}
		else if (choice == 10)
		{
			cout << "nhap x: ";
			cin >> x;
			cout << "nhap pos: "; int pos;
			cin >> pos;
			addPos(l, x, pos);
		}
		else if (choice == 11)
		{
			cout << "nhap pos: ";
			cin >> x;
			RemovePos(l, x);
		}
		else if (choice == 12) {
			cout << "nhap data";
			cin >> x; int val;
			cout << " nhap value: ";
			cin >> val;
			addBefore(l, x, val);
		}
		else if (choice == 13) {
			cout << "nhap data";
			cin >> x; int val;
			cout << " nhap value: ";
			cin >> val;
			addAfter(l, x, val);
		}
		else if (choice == 14)
			showList(l);
		else if (choice == 15)
			cout << countElements(l);
		else if (choice == 16) {
			List* l1 = reverseList(l);
			showList(l1);
		}
		else if (choice == 17)
			removeDuplicate(l);
		else if (choice == 18) {
			cout << "nhap x: ";
			cin >> x;
			removeElement(l, x);
		}
		else if (choice == 0)
			break;

	}
}

int main()
{

	List* l = NULL;
	//createList(l);
	//addHead(l, 69);
	//addPos(l, 4, 1);
	//menu(l);

	return 0;
}