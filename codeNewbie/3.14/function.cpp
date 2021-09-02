#include"function.h"
void createList(myList& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
void initBook(myList& l)
{
	book b;
	strcpy_s(b.title, "Math");
	strcpy_s(b.ISBN, "1");
	strcpy_s(b.author, "cao nhat duc");
	b.year = 2020;
	strcpy_s(b.language, "Vietnamese");
	b.stockLever = 10;
	b.price = 1;
	node* p = createNode(b);
	addTail(l, p);

	strcpy_s(b.title, "physical");
	strcpy_s(b.ISBN, "2");
	strcpy_s(b.author, "cao nhat duc");
	b.year = 2020;
	strcpy_s(b.language, "English");
	b.stockLever = 5;
	b.price = 5;
	 p = createNode(b);
	addTail(l, p);
	
	strcpy_s(b.title, "chemistry");
	strcpy_s(b.ISBN, "3");
	strcpy_s(b.author, "cao nhat duc 3");
	b.year = 2020;
	strcpy_s(b.language, "Vietnamese");
	b.stockLever = 1;
	b.price = 2;
	 p = createNode(b);
	addTail(l, p);
}
book nhapDS()
{
	book b;
	cin.ignore();
	cout << "Title: ";
	cin.getline(b.title, 200);

	cout << "ISBN: ";
	cin.getline(b.ISBN, 10);

	cout << "Year Publish: ";
	cin >> b.year;

	cin.ignore();
	cout << "Author:  ";
	cin.getline(b.author,40);

	cout << "Language: ";
	cin.getline(b.language,30);

	cout << "Stock Level: ";
	cin >> b.stockLever;

	cout << "Price: ";
	cin >> b.price;

	return b;
}
ostream& operator<<(ostream& os, const book& data)
{
	os<<" title: ";
	os << data.title << endl;
	os << " ISBN: ";
	os << data.ISBN << endl;
	os << " Author: ";
	os << data.author << endl;
	os << " Language: ";
	os << data.language << endl;
	os << " Stock Level: ";
	os << data.stockLever << endl;
	os << " Year Publish: ";
	os << data.year << endl;
	os << " Price: ";
	os << data.price << endl;
	return os;
}
node* createNode(book x)
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
	else {
		for (node* i = l.pHead; i != NULL; i = i->pNext)
		{
			if (strcmp(i->data.title, p->data.title) == 0)
			{
				i->data.stockLever += p->data.stockLever;
				return;
			}
		}
		l.pTail->pNext = p;
		l.pTail = p;
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
	
		cout <<"\n"<< i->data;
}
void findBook(myList l)
{
	char name[100];
	cout << "enter name: ";
	cin.ignore();
	cin.getline(name, 100);
	for (node* i = l.pHead; i != NULL; i = i->pNext)
	{
		if (strcmp(i->data.title, name) == 0)
		{
			cout << " ISBN: " << i->data.ISBN << endl;
			cout << " TITLE: " << i->data.title << endl;
			return;
		}
	}
	cout << "\n NOT EXIST!\n\n";
}
void sellBook(myList& l)
{
	char d[10];
	cout << "enter ISBN: ";
	cin.ignore();
	cin.getline(d, 10);
	for (node* i = l.pHead; i != NULL; i = i->pNext)
	{
		if (strcmp(i->data.ISBN, d) == 0)
		{
			cout << " title: " << i->data.title << endl;
			cout << "Price: " << i->data.price << endl;
			if (i->data.stockLever == 0)
				cout << "\n\n\n\t\t!!! OUT OF STOCK!!!\n\n\n";
			else
				i->data.stockLever--;
		}
	}
}
void removeLessThan(myList& l)
{
	cout << "enter K: ";
	int k;
	cin >> k;
	
	node* ptr1;
	for (node* i = l.pHead; i->pNext != NULL; i = i->pNext)
	{
		if (i->pNext->data.stockLever < k)
		{
			if (i->pNext == l.pTail)
				break;
			ptr1 = i->pNext;
			i->pNext = i->pNext->pNext;
			delete ptr1;
		}
	}

	if (l.pTail->data.stockLever < k)
		for (node* i = l.pHead; i != NULL; i = i->pNext)
		{
			if (i->pNext == l.pTail)
			{ 
				delete l.pTail;
				i->pNext = NULL;
				l.pTail = i;
			}
		}

	if (l.pHead->data.stockLever < k)
	{
		{
			node* p = l.pHead;
			l.pHead = l.pHead->pNext;
			delete p;
		}
	}
	
}