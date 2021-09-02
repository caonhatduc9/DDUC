//CAO NHAT DUC
//20127466
//CLC07

// TEST CASE 1
// input: 2,3
// output: 0.09

// TEST CASE 2
// input: 7,3
// output: 74.51

// TEST CASE 3
// input: 10,3
// output: 1308.46

#include "myfunction70.h"
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	float  x, n, s = 0;
	cout << "nhap x: ";
	cin >> x;
	cout << "nhap n: ";
	cin >> n;
	s = sum(n, x);
	cout << fixed << setprecision(2) << s;
	return 0;
}