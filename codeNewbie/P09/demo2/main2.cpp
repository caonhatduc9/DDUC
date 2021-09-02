#include"function.h"
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int a[100];
	char str[10] = "123456789";
	char str1[10];
	a[0] = atoi(str);
			cout << str << endl;
			cout << a[0];
			a[1] = 98976543;
			str1 = itoa(a[1]);
			cout << str1;

	return 0;
}