/* CAO NHAT DUC
 CLC07
20127466

test case 1
 intput 1 6 6 5 4 3 2 1
  output 6 2 4 3 5 1

test case 2
 intput 2 3 1 2 3 4 4 3 2 1
  output 1 1 2 2 3 3 4

test case 3
 intput 1 4 2 4 6 8 
  output 2 4 6 8

  test case 4
 intput 1 4 2 4 6 8
  output 2 4 6 8

  test case 5
 intput 4 5 1 1 1 3 5 
  output 1 3 5

*/
#include"array.h"
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n = 0, a[100];
	while (10 < 20)
	{
		cout << "\n\n 1 - P258 - Write a program to sort all prime numbers in an integer array in ascending order. All non-prime numbers should keep their original positions.";
		cout << "\n 2 - P264 - Write a program to merge 2 ascendingly sorted arrays a, b to an ascendingly sorted array c.";
		cout << "\n 3 - P269 - Write a program to insert x into an ascending sorted array a so that the new array is also sorted in ascending order.";
		cout << "\n 4 - P274 - Write a program to remove all duplicated numbers out of the array.";
		cout << "\n 5 - P190 - Write all program to extract all local maximum elements in an array a to a new array b.\n\n";

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

		else if (choice == 2)
		{
			int n1 = 0, n2 = 0, n3 = 0, b[100], c[100];
			input(a, n1);
			input(b, n2);
			gopMang(a, n1, b, n2, c, n3);
			output(c, n3);
		}
		else if (choice == 3)
		{
			input(a, n);
			insertX(a, n);
			output(a, n);
		}

		else if (choice == 4)
		{
			input(a, n);
			delDup(a, n);
			output(a, n);
		}

		else if (choice == 5)
		{
			int b[100], n2 = 0;
			input(a, n);
			tachMaxSangMangb(a, n, b, n2);
		}
		else
			cout << "khong hop le";
	}
	return 0;
}

