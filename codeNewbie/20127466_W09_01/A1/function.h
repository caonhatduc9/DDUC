#ifndef  function_h
#define function_h
#include<iostream>
using namespace std;
struct node{
	int data;
	node* pNext;
};
struct	stack {
	node* pHead;
	int capacity;
};
bool isEmpty(stack s);
void init(stack& s, int &capacity);
node* createNode(int x);
void push(stack& s, node* p);
int pop(stack& s);
void printList(stack s);
int sizeS(stack s);

#endif // ! function_h
