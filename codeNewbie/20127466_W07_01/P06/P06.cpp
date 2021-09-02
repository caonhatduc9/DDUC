// CAO NHAT DUC
// CLC07
//20127466

//test case 1
//intput 1  5 7 6 5 4 3 
// output 3 6 5 4 7

//test case 2
//intput 1 3 5 4 3 
//output 3 4 5 

//test case 3
//intput 1 4 2 4 6 8 
//output 2 4 6 8


#include"array.h"
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n = 0, a[100];
	while (10 < 20)
	{

		cout << "\n 1 - P258 - sap xep so nguyen to tang dan\n";

		int choice;
		cout << "thay chon bai nao a? ";
		cin >> choice;
		if (choice == 0)
		{
			break;
		}
		if (choice == 1)
		{
			input(a, n);
			sapXepPrime(a, n);
			output(a, n);
		}
		if (choice != 1)
			cout << "khong hop le";
	}
	return 0;
}