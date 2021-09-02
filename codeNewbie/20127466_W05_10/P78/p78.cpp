//CAO NHAT DUC
//20127466
//CLC07

// TEST CASE 1
// input: 14
// output: 2 7

// TEST CASE 2
// input: 20
// output: 2 2 5

// TEST CASE 3
// input: 31 
// output: 31

#include "myfunction78.h"
#include <iostream>
using namespace std;
int main()
{
	int n, i;
	cout << "nhap n: ";
	cin >> n;
	for ( i = 2; i <= n; i++)
		while (n % i == 0 && sont(i) == 1)
		{
			cout << i << " ";
			n = n / i;
		}
	return 0;
}