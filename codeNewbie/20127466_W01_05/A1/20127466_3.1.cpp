#include<iostream>
#include"Header.h"
#include<fstream>
using namespace std;
int main()
{
	 P A[100];
	 int n;
	 docFile(A, n);
	 tangDan(A, n);
	 saveFile(A, n);
	 	return 0;
}