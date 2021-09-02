#include"function.h"
void initStack(Stack *&s, int capacity)
{
	s = new Stack;
	s->capacity = capacity;
	s->head = -1;
	s->data = NULL;
}
int isEmpty(Stack *s) {
	if (s->capacity==10)
		return NULL;
}
bool isFull(Stack* s)
{
	if (s->capacity == 0)
		return true;
	return false;
}
void push(Stack*& s,int x)
{
	if (isFull(s))
	{
		cout << "full";
		return;
	}
	else {
		int* temp = new int[s->head + 2];
		s->head++;
		s->capacity--;
		for (int i = 0; i < s->head; i++)
			temp[i] = s->data[i];
		temp[s->head] = x;
		delete[] s->data;
		s->data = temp;
	}
}

int Pop(Stack*& s)
{
	if (isEmpty(s)==NULL)
		return NULL;
    int k = s->data[s->head];
    int* temp = new int[s->head]; 
    for (int i = 0; i < s->head; i++)
        temp[i] = s->data[i]; 
 s->head--;                 

 delete[] s->data;  

 s->data = temp;     


    return k;   
}
void empTy(Stack*& s)
{
	delete[] s->data;
	s->head = -1;
	s->data = NULL;
	s->capacity = 0;
}
int sizeStack(Stack *s)
{
	return s->head;
}

