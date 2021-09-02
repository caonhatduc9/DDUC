//CAO NHAT DUC
//20127466
//CLC07

// TEST CASE 1
// input: 12345
// output: 3

// TEST CASE 2
// input: 13579
// output: 5

// TEST CASE 3
// input: 123456710
// output: 5


#include "myfunction.h"
#include <iostream>
using namespace std;
int main()
{
	int n, k = 0;
	cout << "nhap n: ";
	cin >> n;
	k = demso(n);
	cout << k;
	return 0;
}