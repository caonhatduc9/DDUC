#include"function2.h"
#include<iostream>
using namespace std;
int main()
{
	int x, y;
	cout << "input x: ";
	cin >> x;
	cout << "input y: ";
	cin >> y;
	cout << dosomething(&x, &y);
	return 0;
}