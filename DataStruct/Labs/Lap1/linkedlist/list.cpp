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
	delete q;
}
void showList(List* l)
{
	if (l->pHead == NULL)
		cout << "\aempty\n";
	else
		for (NODE* i = l->pHead; i != NULL; i = i->pNext)
			cout << i->key << "\t";
}
void removeTail(List*& l)
{
	if (l->pHead == NULL)
		return;
	for (NODE* i = l->pHead; i != NULL; i = i->pNext) {
		if (i->pNext == l->pTail)
		{
			delete l->pTail;
			i->pNext = NULL;
			l->pTail = i;
		}
	}
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
			delete temp;
		}
	}
}
void removeBefore(List*& l, int val)
{
	if (l->pHead->pNext->key == val)
		removeHead(l);

	else {
		NODE* k = NULL;
		for (NODE* i = l->pHead; i != NULL; i = i->pNext)
		{
			if (i->pNext->key == val)
			{
				k->pNext = i->pNext;
				NODE* g = i;
				delete g;
				i = k->pNext;
				break;
			}
			k = i;
		}

	}
}
void removeAfter(List*& l, int val)
{
	for (NODE* i = l->pHead; i != NULL; i = i->pNext)
	{
		if (i->key == val)
		{
			NODE* k = i->pNext;
			i->pNext = k->pNext;
			delete k;
			if (i->pNext == l->pTail)
				l->pTail = i;
		}
	}
}
bool addPos(List*& l, int data, int pos)
{
	NODE* k = NULL;
	int dem = 0, n = 0;
	for (NODE* i = l->pHead; i != NULL; i = i->pNext)
		n++;
	if (pos < 1 || pos>n + 1)
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
				k->pNext = q;
				q->pNext = i;
				break;
			}
			k = i;
		}
	}
	return true;
}
void RemovePos(List*& l, int pos)
{
	int dem = 0, n = 0;
	for (NODE* i = l->pHead; i != NULL; i = i->pNext)
		n++;
	if (pos < 0)
		return;
	if (pos == 0)
		removeHead(l);
	else if (pos >= n - 1)
		removeTail(l);
	else
	{
		NODE* k = l->pHead;
		for (NODE* i = l->pHead->pNext; i != NULL; i = i->pNext)
		{
			dem++;
			if (dem == pos)
			{
				NODE* q = i;
				k->pNext = i->pNext;
				delete q;
				i = k->pNext;
				break;
			}
			k = i;
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

	for (NODE* i = l->pHead; i->pNext != NULL; i = i->pNext)
	{
		if (i->pNext->key == val)
		{
			NODE* q = createNode(data);
			q->pNext = i->pNext;
			i->pNext = q;
			return true;
		}
	}

}
bool addAfter(List*& l, int data, int val)
{
	if (l->pHead == NULL)
		return false;
	for (NODE* i = l->pHead; i != NULL; i = i->pNext)
	{
		if (i->key == val)
		{
			if (i == l->pTail)
			{
				addTail(l, data);
				return true;
			}
			else {
				NODE* q = createNode(data);
				q->pNext = i->pNext;
				i->pNext = q;
				return true;
			}
		}
	}
}
int countElements(List* l)
{
	int n = 0;
	for (NODE* i = l->pHead; i != NULL; i = i->pNext)
		n++;
	return n;
}
//doi chieu ds bai16
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
//bai 17 xoa trung
void removeDuplicate(List*& l)
{
	NODE* ptr1, * ptr2, * dup;
	ptr1 = l->pHead;
	while (ptr1 != NULL && ptr1->pNext != NULL) {
		ptr2 = ptr1;
		while (ptr2->pNext != NULL)
		{
			if (ptr2->pNext->key == ptr1->key)
			{
				if (ptr2->pNext == l->pTail)
					l->pTail = ptr2;
				dup = ptr2->pNext;
				ptr2->pNext = ptr2->pNext->pNext;
				delete dup;

			}
			else ptr2 = ptr2->pNext;
		}
		ptr1 = ptr1->pNext;
	}
}
bool removeElement(List*& l, int key)
{
	int flag = 0;
	if (l->pHead == NULL)
		return false;
	while (l->pHead->key == key)
	{
		removeHead(l); flag = 1;
		if (l->pHead == NULL)
			return true;
	}
	while (l->pTail->key == key)
	{
		removeTail(l); flag = 1;
	}
	for (NODE* i = l->pHead; i->pNext != NULL; i = i->pNext)
	{
		if (i->pNext->key == key)
		{
			NODE* q = i;
			NODE* temp = i->pNext;
			q->pNext = i->pNext->pNext;
			delete temp;
			i = q->pNext;
		}
	}
	return (flag = 0) ? false : true;
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
	menu(l);
	return 0;
}