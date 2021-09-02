#include"function3.h"
#include<iostream>
#include<string>
using namespace std;
int main()
{
	char a[100];
	gets_s(a, 100);
	char* cstr = a;
	
	if (isPalindrome(cstr))
	{
		cout << "YES";
	}
	else
		cout << "NO" << endl;
	return 0;
}