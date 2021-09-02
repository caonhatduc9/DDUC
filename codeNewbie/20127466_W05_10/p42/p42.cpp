//CAO NHAT DUC
//20127466
//CLC07

// TEST CASE 1
// input: 20
// output: 5

// TEST CASE 2
// input: 10
// output: 4

// TEST CASE 3
// input: 12345
// output: 156

#include"Myfunction.h"
#include <iostream>
using namespace std;
int main()
{
	int n, s = 0;
	cout << "nhap n: ";
	cin >> n;
	s = timk(n);
	cout << s;
	return 0;
}