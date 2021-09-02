#ifndef function_h
#define function_h
#include<iostream>
#include<fstream>
using namespace std;
struct node {
	int data;
	node* pNext;
};

struct myList {
	node* pHead;
	node* pTail;
};
void createList(myList& n);
node* createNode(int x);
void addTail(myList& n, node* p);
void loadFile(myList& l);
void sumNode(myList l, myList& l1);
void saveFile(myList l);

#endif // !function_h