#include"struct.h"
#include<fstream>
#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	date d, d1, d2;
	student st;
	while (1)
	{
		cout << "\n1-Define a struct Date (day, month, year) and the following functions.\n";
		cout << "2-Define a struct Student (id, full name, gpa, address, date of birth) and the following functions.\n";
		cout << "3-Define a struct Course course) and the following functions.\n";
		cout << "0- ket thuc\n";
		int choice;
		cout << " chon bai\t";
		cin >> choice;
		if (choice == 0)
			break;
		else if (choice == 1)
		{
			while (1)
			{
				cout << "\n1- Input a date.\n";
				cout << "2-Output a date (yyyy-MM-dd)\n";
				cout << "3-Load a date from a text file.\n";
				cout << "4-Save a date to another text file.\n";
				cout << "5-Compare 2 date.\n";
				cout << "6-Find tomorrow: increase a date by 1 day.\n";
				cout << "7-Find yesterday: increase a date by 1 day.\n";
				cout << "8- Compute the distance between input date vs 1/1/same year.\n";
				cout << "9- Compute the distance between 2 input dates.\n";
				cout << "10-Compute the distance between input date vs 1/1/1970.\n";
				cout << "0- ket thuc\n";
				int choice1;
				cout << "chon bai\t";
				cin >> choice1;

				if (choice1 == 0)
				{
					break;
				}
				else if (choice1 == 1)
				{
					inputDate(d);
					break;
				}
				else if (choice1 == 2)
				{
					outputDate(d);
					break;
				}
				else if (choice1 == 3)
				{
					docFiledate(d);
					break;
				}
				else if (choice1 == 4)
				{
					saveFileDate(d);
					break;
				}
				else if (choice1 == 5)
				{
					int cmp = CMPDay(d1, d2);
					cout << cmp;
					break;
				}
				else if (choice1 == 6)
				{
					inputDate(d);
					findTomorrow(d);
					break;
				}
				else if (choice1 == 7)
				{
					inputDate(d);
					findYesterday(d);
					break;
				}
				else if (choice1 == 8)
				{
					inputDate(d);
					distance(d);
					break;
				}
				else if (choice1 == 9)
				{
					int dis = distance2();
					cout << dis << endl;
					break;
				}
				else if (choice1 == 10)
				{
					int dis = distance3();
					cout << dis << endl;
					break;
				}
			}
		}
		else if (choice == 2)
		{
			while (1)
			{
				cout << "1-  Input a student.\n";
				cout << " 2- Output a student: id, full name, gpa, address, dob.\n";
				cout << "3- Load file student\n";
				cout << "4- save file\n";
				int choice2;
				cout << "chon chuc nang\t";
				cin >> choice2;
				if (choice2 == 0)
					break;
				else if (choice2 == 1)
				{
					inputStudent(st);
				}
				else if (choice2 == 2)
				{
					outputStudent(st);
					break;
				}
				else if (choice2 == 3)
				{
					loadStudent(st);
					outputStudent(st);
				}
				else if (choice2 == 4)
				{
					saveStudent(st);
					break;
				}
			}
		}
	}
	return 0;
}