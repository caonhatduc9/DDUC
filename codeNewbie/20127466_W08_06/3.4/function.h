#ifndef function_h
#define function_h
#include<iostream>
#include<fstream>
using namespace std;
struct node {
	int data;
	node* pNext;
};
struct myList
{
	node* pHead;
	node* pTail;
};

void createList(myList& l);
node* createNode(int x);
void addTail(myList& l, node* p);
void loadFile(myList& l);
void insertNode(myList& l);
void saveFile(myList l);

#endif
