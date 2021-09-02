#include"function8.h"
#include<iostream>
using namespace std;
int main()
{
	int** a = NULL;
	int lab, *sta = NULL;
	storeData(a, lab, sta);
	showData(a, lab, sta);
	while (1)
	{
		cout << "\n\n\n\t\t\t\t\tMENU\n";
		cout << "\t1 - Login\n";
		cout << "\t2 - logout\n";
		cout << "\t3 - search user\n";
		cout << "\t0 - exit\n";
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			cout << "\t\tLogin\n";
			logIn(a, lab, sta);
			showData(a, lab, sta);
		}
		else if (choice == 2)
		{
			cout << "\t\tLogout\n";
			logOut(a, lab, sta);
			showData(a, lab, sta);
		}
		else if (choice == 3)
		{
			searchID(a, lab, sta);
		}
		else if (choice == 0)
			break;
	}
	del(a, lab);
	delete sta;
	delete a;
	return 0;
}

