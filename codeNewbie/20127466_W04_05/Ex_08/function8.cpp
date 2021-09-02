#include"function8.h"
#include<iostream>
using namespace std;

void storeData(int**& a, int& lab, int*& sta)
{
	int temp;
	cout << "Enter Lab number: ";
	cin >> lab;
	a = new int* [lab];
	sta = new int[lab];
	for (int i = 0; i < lab; i++)
	{
		cout << "station number of lab " << i + 1 << ": ";
		cin >> *(sta+i);
		*(a + i) = new int[*(sta + i)];

	}
		
	for (int i = 0; i < lab; i++)

		for (int j = 0; j < sta[i]; j++)
		{
			*(*(a + i) + j) = 0;
		}
}
int findMax(int* a, int n)
{
	int max = 0, k, pos;
	for (int i = 0; i < n; i++)
		if (max < *(a + i))
		{
			pos = *(a + i);
			k = max;
			max = pos;
			pos = k;
		}
	return max;
}
void showData(int** a, int lab, int *sta)
{
	cout << "\n\tLab"<<"\tStation\n\n\t";
	int k = findMax(sta, lab);
	for (int i = 0; i < k; i++)
		cout << "\t" << i + 1;
	cout << "\n\n";
	for (int i = 0; i < lab; i++)
	{
		cout <<"\t"<< i + 1;
		for (int j = 0; j < sta[i]; j++)
		{
			
			cout <<"\t"<< *(*(a + i) + j);
		}
		cout << endl << endl;
	}
}
void logIn(int**& a, int lab, int* sta)
{
	int enterLab, enterSta, id;
	do {

		cout << "\n\t***enter the lab number: ";
		cin >> enterLab;
		cout << "\t***enter the station number: ";
		cin >> enterSta;
	} while (enterLab > lab || enterSta < 0 || enterSta>sta[enterLab]);
	if (a[enterLab - 1][enterSta - 1] != 0)
	{
		cout << "\n\t\t\tlab " << enterLab << " station " << enterSta << " is logged in by another user";
		return;
	}
	cout << "enter ID: ";
	cin >> id;
	a[enterLab - 1][enterSta - 1] = id;
}
void logOut(int**& a, int lab, int* sta)
{
	int id;
		cout << "\n\t\tenter ID: ";
		cin >> id;
		for (int i = 0; i < lab; i++)
			for (int j = 0; j < sta[j]; j++)
			{
				if (a[i][j] == id)
					a[i][j] = 0;
			}
}
void searchID(int**& a, int lab, int* sta)
{
	int sID, check = 0;
	cout << "\n\t\t*enter id: ";
	cin >> sID;
	for (int i = 0; i < lab; i++)
		for (int j = 0; j < sta[j]; j++)
		{
			if (a[i][j] == sID)
			{
				cout << "\n\tuser " << sID << " logged onto lab " << i + 1 << " station " << j;
				check = 1;
			}
		}

	if (check == 0)
		cout << "\n \t\t no user!!!";
}
void del(int** b, int d)
{
	for (int i = 0; i < d; i++)
		delete b[d];
}