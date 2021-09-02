#include<iostream>
#include"func4.h"
using namespace std;
int main()
{
	DT A[100];
	int n, p;
	loadFile(A, n);
	p = totalPrice(A, n);
	saveFile(p);
	return 0;
}