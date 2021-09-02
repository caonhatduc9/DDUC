#ifndef funtion_h
#define function_h
#include<fstream>
#include<iostream>
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
void removeDump(myList& l);
void saveFile(myList l);

#endif // !funtion_h
