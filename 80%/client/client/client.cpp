// client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "framework.h"
#include "client.h"
#include"afxsock.h"
#include"string.h"
#include <string>
#include<vector>
#include<conio.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// The one and only application object

CWinApp theApp;

using namespace std;

struct MUA {
	string tienMat, chuyenKhoan;
};
struct TIENTE {
	string ten, tyGiaTT, tyGiaBan, note;
	MUA tyGiaMua;
};
void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int resquest(CSocket& c, string s) {
	int len = s.length();
	c.Send(&len, sizeof(int), 0);
	c.Send(s.c_str(), len, 0);
	return len;
}
char* response(CSocket& c)
{
	char* r;
	int len;
	c.Receive(&len, sizeof(int), 0);
	r = new char[len];
	c.Receive(r, len, 0);
	r[len] = 0;
	return r;
}
string toSTRING(char* str)
{
	string s;
	for (int i = 0; i < strlen(str); i++)
	{
		s.push_back(str[i]);
	}
	return s;
}
string hidePass()
{

	char ch, s[50];
	int i = 0;
	while (1)
	{
		ch = _getch();
		if (ch == 13)
		{
			cout << endl;
			break;
		}
		else
		{
			cout << "*";
			s[i++] = ch;
		}
	}
	s[i] = '\0';
	return toSTRING(s);
}
void showData(TIENTE t[17],string inforDate)
{
	system("cls");
	GotoXY(10, 10);
	cout << "Ten";
	GotoXY(18, 10);
	cout << "Ty gia trung tam";
	GotoXY(39, 10);
	cout << "Ty gia mua";
	GotoXY(70, 10);
	cout << "Ty gia ban";
	GotoXY(39, 12);
	cout << "tien mat";
	GotoXY(52, 12);
	cout << "Chuyen khoan";
	for (int i = 0; i < 17; i++)	
	{
		GotoXY(10, 13 + i);
		cout << t[i].ten;
		GotoXY(18, 13 + i);
		cout << t[i].tyGiaTT;
		GotoXY(39, 13 + i);
		cout << t[i].tyGiaMua.tienMat;
		GotoXY(52, 13 + i);
		cout << t[i].tyGiaMua.chuyenKhoan;
		GotoXY(70, 13 + i);
		cout << t[i].tyGiaBan;
		GotoXY(39, 13 + 1 + i);
		cout << t[i].note;
	}
	GotoXY(39, 32);
	cout <<"ty gia duoc cap nhat luc "<< inforDate;
	GotoXY(10, 33);
	cout << "# : Áp dụng cho EUR, USD có mệnh giá 50, 100";
	GotoXY(10, 34);
	cout << "& : Áp dụng cho EUR, USD có mệnh giá nhỏ hơn 50";
}
void waiting()
{
	system("cls");
	GotoXY(50, 13);
	cout << "Waiting";
	Sleep(700);
	GotoXY(57, 13);
	cout << ".";
	Sleep(700);
	GotoXY(58, 13);
	cout << ".";
	Sleep(700);
	GotoXY(59, 13);
	cout << ".";
}
int main()
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(nullptr);

	if (hModule != nullptr)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
		{
			// TODO: code your application's behavior here.
			wprintf(L"Fatal Error: MFC initialization failed\n");
			nRetCode = 1;
		}
		else
		{
			system("color 71");
			// TODO: code your application's behavior here.
			//khai bao su dung socket trong window
			AfxSocketInit(NULL);
			// socket client;
			CSocket client;
			//khoi tao socket
			//client.Create();//cho nay khong can port cung k sao
			if (!client.Create())
			{
				cout << "error, can't create socket" << endl;
				return 1;
			}

			if (!client.Connect(_T("127.0.0.1"), 4567))
			{
				cout << "error, can't connect to server" << endl;
				return 1;
			}
			TIENTE t[17];
			cout << "connect success:";
			string s;
			char* r;
			int len;
			int choice;
		
			while (1) {
				cout << "\n\t\t\t\t1-sign in\n\t\t\t\t2-sign up\n\t\t\t\t0-exit";
				cout << "\n \t\t\tchoice: ";
				cin >> choice;
				
				if (choice == 1)
				{
					s = "sign in";
					resquest(client, s);
					cout << "\t\t\tUser: ";
					cin.ignore();
					getline(cin, s);
					resquest(client, s);
					cout << "\t\t\tPassword: ";
					//cai an pass hới cùi xíu nếu nhập sai pass thì phait nhập lại từ đầu không xóa đc
					s = hidePass();
					resquest(client, s);
					r = response(client);
					system("cls");
					if (strcmp(r, "1") == 0)
					{
						while (1) {
							
							cout << "\n\t\t\t\t1-Tra cuu hom nay";
							cout << "\n\t\t\t\t2-Tra cuu theo ngay";
							cout << "\n\t\t\t\t0-Exit";
							int choice;
							cout << "\n\nenter choice: ";
							cin >> choice;
							if (choice == 1)
							{
								
								waiting();
								resquest(client, "1");
								for (int i = 0; i < 17; i++)
								{
									t[i].ten = response(client);
									t[i].tyGiaTT = response(client);
									t[i].tyGiaMua.tienMat = response(client);
									t[i].tyGiaMua.chuyenKhoan = response(client);
									t[i].tyGiaBan = response(client);
									t[i].note = response(client);
								}
								string inforDate = response(client);
								showData(t, inforDate);
							}
							else if (choice == 2)
							{
								resquest(client, "2");
								string date[3];
								cout << "\n\t\t\t\tNhap ngay thang nam(dd/mm/yyyy)";
								cout << "\n\t\t\tnhap ngay: ";
								cin >> date[0];
								cout << "\n\t\t\tnhap thang: ";
								cin >> date[1];
								cout << "\n\t\t\tnhap nam: ";
								cin >> date[2];
								waiting();
								resquest(client, "1");
								resquest(client, date[0]);
								resquest(client, date[1]);
								resquest(client, date[2]);
								for (int i = 0; i < 17; i++)
								{
									t[i].ten = response(client);
									t[i].tyGiaTT = response(client);
									t[i].tyGiaMua.tienMat = response(client);
									t[i].tyGiaMua.chuyenKhoan = response(client);
									t[i].tyGiaBan = response(client);
									t[i].note = response(client);
								}
								string inforDate = response(client);
								showData(t, inforDate);
							}
							else if (choice == 0)
							{
								resquest(client, "0");
								break;
							}
						}
					}
					if (strcmp(r, "0") == 0)
						cout << "\n\t\tAccount does not exist or Incorrect password  ";

				}

				else if (choice == 2)
				{
					s = "sign up";
					resquest(client, s);
					string signUp[3];
					cout << "\n\t\t\t User: ";
					cin.ignore();
					getline(cin, signUp[0]);
					cout << "\t\t\tPassword: ";
					signUp[1] = hidePass();

					cout << "\t\t\tPassword again: ";
					signUp[2] = hidePass();
					if (signUp[2] == signUp[1])
					{
						resquest(client, "1");
						resquest(client, signUp[0]);
						resquest(client, signUp[1]);
						r = response(client);
						if (strcmp(r, "1") == 0)
							cout << "\n\t\t\t*****registered successfully\n\n";
						if (strcmp(r, "0") == 0) cout << "\n\t\t\t*****xxxFailed: Account already exists\n\n";
					}
					else {
						cout << "\t\t\t*****pass and repass must be the same\n\n";
						resquest(client, "0");
						r = response(client);
					}
				}
				else if (choice == 0)
				{
					resquest(client, "exit");
					break;
				}
			}
			client.Close();
		}
		system("cls");
		GotoXY(50, 15);
		system("color 70");
		cout << "BYE BYE";
		_getch();
		
	}




	else
	{
		// TODO: change error code to suit your needs
		wprintf(L"Fatal Error: GetModuleHandle failed\n");
		nRetCode = 1;
	}

	return nRetCode;
}