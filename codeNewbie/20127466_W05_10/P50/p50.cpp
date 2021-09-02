//CAO NHAT DUC
//20127466
//CLC07

// TEST CASE 1
// input: 12345
// output: 54321

// TEST CASE 2
// input: 123450
// output: 54321

// TEST CASE 3
// input: 90000
// output: 9

#include "myfunction50.h"
#include <iostream>
using namespace std;
int main()
{
	int n, kq;
	cout << "nhap n: ";
	cin >> n;
	kq = daoso(n);
	cout << kq;
	return 0;
}