/*
CAOP NHAT DUC
CLC07
20127466

Test case 1
input 2 3
output 37.68

Test case 2
input 2 4
output 50.24

Test case 3
input 2 5
output 62.80

*/

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	float r, h, v, pi = 3.14;
	cout << "nhap r: ";
		cin >> r;
	cout << "nhap h: ";
	cin >> h;
	v = pi * r * r * h;
	cout << fixed << setprecision(2) << v;
}