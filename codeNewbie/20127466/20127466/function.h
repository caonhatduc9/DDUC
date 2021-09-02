#ifndef function_h
#define function_h
#include<iostream>
#include<time.h>
using namespace std;

struct date {
	int d, m, y;
};
struct flight {
	int id;
	char name[50];
	date day;
	unsigned int capacity;
};
struct Node {
	flight  data;
	Node* pnext;
};
struct mylist 
{
	Node* phead;
};
void initlist(mylist& l);


bool checkEmpty(mylist l);
void addTail(mylist& l, Node* p);
void inputflight(mylist& l);
int sumCapacity(mylist l);
void removeUnder(mylist& l);
void printList(mylist l);
void printfIndex6(mylist l,int k);
int findMaxCapacity(mylist l);
#endif // !function_h
