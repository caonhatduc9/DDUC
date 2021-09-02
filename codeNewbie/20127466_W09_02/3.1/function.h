#ifndef function_h
#define function_h
#include<iostream>
using namespace std;
struct Stack 
{
	int* data; // dynamic array
	int head; // index of top element
	int capacity; // size of stack
};

void initStack(Stack*& s, int capacity);
int isEmpty(Stack* s);
bool isFull(Stack* s);
void push(Stack*& s, int x);
int Pop(Stack*& s);
void empTy(Stack*& s);
int sizeStack(Stack* s);
#endif // !function_h
