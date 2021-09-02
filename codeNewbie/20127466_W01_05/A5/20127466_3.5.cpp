#include<iostream>
#include"func5.h"
using namespace std;
int main()
{
	Std A[100];
	int n, k;
	loadFile(A, n);
	k = findGpa(A, n);
	saveFile(A, k);
	return 0;

}