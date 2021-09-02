#include<iostream>
#include"function.h"
using namespace std;
int main()
{
	PS* a, * b;
	int n, m = 0;
	input(a, n);
	output(a, n);
	cout << endl;
	
		cout << " mang am\n";
		extractN(a, n, b, m);
		if (m > 0)
		{
			output(b, m);
		}
	delete[] a;
	if (b != NULL)
		delete[]b;
	return 0;
}