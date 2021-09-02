#include"func.h"
#include <iostream>
#include<fstream>
using namespace std;
void loadFile(date A[100], int& n)
{
	ifstream inFile;
	inFile.open("input3.txt");
		inFile >> n;
		for (int i = 0; i < n; i++)
		{
			inFile >> A[i].y;
			inFile >> A[i].m;
			inFile >> A[i].d;
		}
	inFile.close();
}
void saveFile(date A[100], int n)
{
	ofstream outFile;
	outFile.open("output3.txt");
	outFile << n << "\n";
	for (int i = 0; i < n; i++)
	{
		outFile << A[i].y << " ";
		outFile << A[i].m << " ";
		outFile << A[i].d << "\n";
	}
	outFile.close();
}
int comPare(date A, date B)
{
	if (A.y > B.y)
		return 1;
	else	if (A.y < B.y)
		return 0;
	else
	{
		if (A.m > B.m)
			return 1;
		else if (A.m = B.m)
		{
			if (A.d > B.d)
				return 1;
		}
	}
}
void swap(int& a, int& b)
{
	int k;
	k = a;
	a = b;
	b = k;
}
void sort(date A[100], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			/*if (A[i].y > A[j].y)
			{
				swap(A[i].y, A[j].y);
				swap(A[i].m, A[j].m);
				swap(A[i].d, A[j].d);
			}
			else if (A[i].y = A[j].y)
			{
				if (A[i].m > A[j].m)
				{
					swap(A[i].y, A[j].y);
					swap(A[i].m, A[j].m);
					swap(A[i].d, A[j].d);
				}
				else if (A[i].m = A[j].m)
				{
					if (A[i].d > A[j].d)
					{
						swap(A[i].y, A[j].y);
						swap(A[i].m, A[j].m);
						swap(A[i].d, A[j].d);
					}
				}

				//swap(a.y, b.y);
				//swap(a.m, b.m);
				//swap(a.d, b.d);*/
			if (comPare(A[i], A[j]) == 1)
				swap(A[i], A[j]);
			
			}
		}

