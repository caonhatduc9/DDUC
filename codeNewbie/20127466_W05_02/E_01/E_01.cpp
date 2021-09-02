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

	cout << " mang am:\n";
	extractN(a, n, b, m);
	if (m > 0)
		output(b, m);
	else	if (m == 0)
			cout << "\t no item";
	PS sum = sumPos(a, n);
	cout << "\n\t SUM: " << sum.tu << "/" << sum.mau << endl;
	delete[] a;
	if (b != NULL)
		delete[] b;
	return 0;
}