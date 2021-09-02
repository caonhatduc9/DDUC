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
	node* ptail;
};
void createList(myList& n);
node* createNode(int x);
void addTail(myList& n, node* p);
void loadFile(myList& l);
void xoaNode(myList& l, int x);
void xoaNode2(myList& l, int x);
int findNode(myList l, int x);
void xoaNhieuNode(myList& l, int x);
void saveFile(myList l);

#endif // !function_h
