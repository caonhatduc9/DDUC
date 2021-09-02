//CAO NHAT DUC
//20127466
//CLC07

// TEST CASE 1
// input: 5
// output: 0.80

// TEST CASE 2
// input: 7
// output: 0.79

// TEST CASE 3
// input: 10
// output: 0.76
#include "myfunction66.h"
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	float s;
	cout << "nhap n: ";
	cin >> n;
	s = sum(n);
	cout << setprecision(2) << fixed << s;
	return 0;
}