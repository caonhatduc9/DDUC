#ifndef function_h
#define function_h
#include<iostream>
using namespace std;

struct node {
	int data;
	node* pnext;
};
struct Queue {
	node* phead;
	node* ptail;
	int capacity;
};
node* createNode(int x);
void initQueue(Queue& q, int capacity);
int deQueue(Queue& q);
void enQueue(Queue& q, int x);
void empTy(Queue& q);
int sizeQueue(Queue q);

#endif