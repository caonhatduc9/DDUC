//CAO NHAT DUC
//20127466
//CLC07

// TEST CASE 1
// input: 12345
// output: 1

// TEST CASE 2
// input: 123454321
// output: 2

// TEST CASE 3
// input: 99999
// output:5

#include "myfunction54.h"
#include <iostream>
using namespace std;
int main()
{
	int n, M;
	cout << "nhap n: ";
	cin >> n;
	M = soluong(n);
	cout << M;
	return 0;
}