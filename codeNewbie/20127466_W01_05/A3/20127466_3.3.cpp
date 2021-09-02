#include<iostream>
#include"func.h"
using namespace std;
int main()
{
		date A[100];
	int n;
	loadFile(A, n);
	sort(A, n);
	saveFile(A, n);
	return 0;
} 