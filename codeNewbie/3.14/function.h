#ifndef function_h
#define function_h
#include<iostream>
#include<fstream>
using namespace std;
struct book {
	char title[200];
	char ISBN[10];
	char author[40];
	char language[30];
	int year, price, stockLever;
};
struct node {
	book data;
	node* pNext;
};
struct myList
{
	node* pHead;
	node* pTail;
};

void createList(myList& l);
node* createNode(book x);
void initBook(myList& l);
void addTail(myList& l, node* p);
void saveFileDG(myList l);
book nhapDS();
void printList(myList l);
void sellBook(myList& l);
void findBook(myList l);
void removeNodeK(myList& l, int x);
void removeLessThan(myList& l);
void loadFile(myList& l);
void insertNode(myList& l);
void saveFile(myList l);

#endif
