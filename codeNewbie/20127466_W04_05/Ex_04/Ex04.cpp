#include"function4.h"
#include<iostream>
using namespace std;
int main()
{
	int* a, n, k;
	inputarray(a, n);
	outputArray(a, n);
	cout << "\n\tMode: " << modeOfArray(a, n);
	return 0;
}
