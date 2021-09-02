//CAO NHAT DUC
//20127466
//CLC07

// TEST CASE 1
// input: 12345
// output: YES

// TEST CASE 2
// input: 123450
// output: NO

// TEST CASE 3
// input: 90000
// output: NO

#include "myfunction58.h"
#include <iostream>
using namespace std;
int main()
{
	int n, k;
	cout << "nhap n: ";
	cin >> n;
	k = kiemtra(n);
	if (k == 1)
	{
		cout << "YES";
	}
	if (k == 0)
	{
		cout << "NO";
	}
	return 0;
}