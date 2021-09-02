//CAO NHAT DUC
// CLC07
//20127466

//test case 1
//intput 1 3 1 2 3 2 1 

//test case 2
//intput 4 3 1 2 3 2 3 


#include"array.h"
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n = 0, a[100];
	while (10 < 20)
	{

		cout << "\n 2 - P02 - tinh trung binh cong\n";
		cout << " 4 - P04 - tim so nguyen to\n";
		cout << " 6 - P06 - kiem tra thu tu cua cac phan tu\n";
		cout << " 12- P12 - tim phan tu lon thu hai\n";
		cout << " 23 - P23 - dem so nguyen to\n";
		cout << " 28 - P28 - tim tong bang 0 tren hai mang\n";
		cout << " 9 - P09 - dem cac phan tu khac nhau\n";
		cout << " 26 - P26 - cac phan tu cung xuat hien tren hai mang\n";
		cout << " 38 - P38 - tich lon nhat cua hai phan tu trong mang\n";
		cout << " 1 - P01 - tim so chan lon nhat va so le nho nhat\n";
		cout << "0-ket thuc chuong trinh\n";
		int choice;
		cout << "thay chon bai nao a?";
		cin >> choice;
		if (choice == 0)
		{
			break;
		}
		if (choice == 1)
		{
			cout << "nhap mang :\n";
			input(a, n);
			int ans1 = evenmax(a, n);
			int ans2 = oddmin(a, n);
			cout << ans1 << " " << ans2 << endl;
		}
		if (choice == 2)
		{
			cout << "nhap mang a:\n";
			input(a, n);
			double ans = TBC(a, n);
			cout << fixed << setprecision(2) << ans << endl;
		}

		else if (choice == 4)
		{
			cout << "nhap mang: \n";
			input(a, n);
			inprime(a, n);
		}

		else if (choice == 6)
		{

			input(a, n);
			kiemtratanggiam(a, n);
		}

		else if (choice == 9)
		{
			input(a, n);
			demsokhacnhau(a, n);
		}

		else if (choice == 12)
		{
			input(a, n);
			secondmax(a, n);
		}

		else if (choice == 23)
		{
			input(a, n);
			demprime(a, n);
		}

		else if (choice == 26)
		{
			int b[100];
			input(a, n);
			input(b, n);
			kiemtraphantumangacotrongmangb(a, b, n);
		}

		else if (choice == 28)
		{
			int b[100];
			input(b, n);
			sumequalo(a, b, n);
		}

		else if (choice == 38)
		{
			input(a, n);
			tichmax(a, n);

		}
	}
	
	cout << "bye bye\n";
	return 0;
	}
