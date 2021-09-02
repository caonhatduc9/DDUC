// sever.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include"pch.h"
#include "framework.h"
#include "SeverFinal.h"
#include "afxsock.h"
#include"pch.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<ctime>
#include<string>
#include<curl/curl.h>

using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#define SIZE 2
#endif

//int cnt = 1;
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
struct TODAY {
	string d, m, y;
};
struct USER {
	string u, p;
};

 static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
	((string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}
void cleanData(string data, string name, TIENTE& t)
{
	t.ten = name;
	size_t distance1 = data.find(name) + 27;
	size_t pos1 = data.find(">", distance1 - 2);
	size_t pos2 = data.find("<", pos1);
	size_t numberOfDigit = pos2 - pos1 - 1;
	t.tyGiaTT = data.substr(distance1, numberOfDigit);

	distance1 = distance1 + numberOfDigit + 24;
	pos1 = data.find(">", distance1 - 2);
	pos2 = data.find("<", pos1);
	numberOfDigit = pos2 - pos1 - 1;
	t.tyGiaMua.tienMat = data.substr(distance1, numberOfDigit);

	distance1 = distance1 + numberOfDigit + 24;
	pos1 = data.find(">", distance1 - 2);
	pos2 = data.find("<", pos1);
	numberOfDigit = pos2 - pos1 - 1;
	t.tyGiaMua.chuyenKhoan = data.substr(distance1, numberOfDigit);

	distance1 = distance1 + numberOfDigit + 24;
	pos1 = data.find(">", distance1 - 2);
	pos2 = data.find("<", pos1);
	numberOfDigit = pos2 - pos1 - 1;
	t.tyGiaBan = data.substr(distance1, numberOfDigit);

	if (name == "EUR")
	{
		distance1 = distance1 + numberOfDigit + 98;
		pos1 = data.find(">", distance1 - 2);
		pos2 = data.find("<", pos1);
		numberOfDigit = pos2 - pos1 - 1;
		t.note = data.substr(distance1, numberOfDigit);
		distance1 = distance1 + numberOfDigit + 24;
	}
	if (name == "USD")
	{
		distance1 = distance1 + numberOfDigit + 97;
		pos1 = data.find(">", distance1 - 2);
		pos2 = data.find("<", pos1);
		numberOfDigit = pos2 - pos1 - 1;
		t.note = data.substr(distance1, numberOfDigit);
		distance1 = distance1 + numberOfDigit + 24;
	}
}
string processDate(string data)
{
	size_t pos1 = data.find("lúc");
	size_t pos2 = data.find("và chỉ mang");
	string inforDate = data.substr(pos1 + 5, pos2 - pos1 - 1);
	return inforDate;
}
void getData(TIENTE tienTe[17], string url, string& inforDate) {
	CURL* curl;
	CURLcode res;
	string readBuffer;

	curl = curl_easy_init();
	if (curl) {

		curl_easy_setopt(curl, CURLOPT_URL,url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		size_t indexStart = readBuffer.find("AUD");
		size_t indexEnd = readBuffer.find("và chỉ mang", indexStart);
		string data = readBuffer.substr(indexStart, indexEnd - indexStart);
		inforDate = processDate(data);
		cleanData(data, "AUD", tienTe[0]);
		cleanData(data, "CAD", tienTe[1]);
		cleanData(data, "CHF", tienTe[2]);
		cleanData(data, "CNY", tienTe[3]);
		cleanData(data, "DKK", tienTe[4]);
		cleanData(data, "EUR", tienTe[5]);
		cleanData(data, "GBP", tienTe[6]);
		cleanData(data, "HKD", tienTe[7]);
		cleanData(data, "JPY", tienTe[8]);
		cleanData(data, "KRW", tienTe[9]);
		cleanData(data, "LAK", tienTe[10]);
		cleanData(data, "NOK", tienTe[11]);
		cleanData(data, "NZD", tienTe[12]);
		cleanData(data, "SEK", tienTe[13]);
		cleanData(data, "SGD", tienTe[14]);
		cleanData(data, "THB", tienTe[15]);
		cleanData(data, "USD", tienTe[16]);
	}
}
void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int resquest(CSocket& cs, string s) {
	int len = s.length();
	cs.Send(&len, sizeof(int), 0);
	cs.Send(s.c_str(), len, 0);
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
void saveFile(string path, USER user)
{
	ofstream fout;
	fout.open(path, ios::app);
	fout << user.u << " " << user.p << "\n";
	fout.close();
}
bool is_emptyFile(ifstream& pFile)
{
	return pFile.peek() == ifstream::traits_type::eof();
}
int checkUser(string path, USER user, int check)
{
	ifstream fin;
	fin.open(path);

	if (is_emptyFile(fin))
		return 0;
	else
	{
		USER buf;
		while (!fin.eof())
		{
			getline(fin, buf.u, ' ');
			getline(fin, buf.p, '\n');
			if (check == 1)//kierm tra dang ki
			{
				if (user.u == buf.u)
					return 1;
			}
			else

				if (user.u == buf.u && user.p == buf.p)
					return 1;

		}
	}
	return 0;
}

DWORD WINAPI function_cal(LPVOID arg)
{
	SOCKET* hConnected = (SOCKET*)arg;
	CSocket cl1;
	//Chuyen ve lai CSocket
	cl1.Attach(*hConnected);


	string s;
	int len;
	char* r = NULL;
	int check;

	while (1)
	{
		//dau tien seve nhan cac tin hieu signin/up exit tu client
		check = 0;
		r = response(cl1);
		if (strcmp(r, "exit") == 0)
		{
			//bao gioừ làm hoàn chỉnh sẽ ghi thêm ip của client
			cout << "\n\tclient just close";
			break;
		}
		if (strcmp(r, "sign in") == 0)
		{
			USER u1;
			//nhan pass va user
			u1.u = response(cl1);
			u1.p = response(cl1);
			//kiem tra co ton tai trong file chua
			if (checkUser("inforUser.txt", u1, 0) == 1)
			{//phan hoi 1 neu thanh cong, 0 neu that bai
				resquest(cl1, "1");
				cout << "\nUser: " << u1.u << " has been signed in successfully ";
				
				while (1)
				{
					r = response(cl1);
					if (strcmp(r, "1") == 0)
					{
						string inforDate;
						TIENTE tienTe[17];
						string url = "https://www.vietinbank.vn/web/home/vn/ty-gia";
						getData(tienTe, url, inforDate);
						for (int i = 0; i < 17; i++)
						{
							resquest(cl1, tienTe[i].ten);
							resquest(cl1, tienTe[i].tyGiaTT);
							resquest(cl1, tienTe[i].tyGiaMua.tienMat);
							resquest(cl1, tienTe[i].tyGiaMua.chuyenKhoan);
							resquest(cl1, tienTe[i].tyGiaBan);
							resquest(cl1, tienTe[i].note);
						}
						resquest(cl1, inforDate);
					}
					if (strcmp(r, "2") == 0)
					{
						string inforDate;
						TIENTE tienTe[17];
						string day = response(cl1);
						string month = response(cl1);
						string year = response(cl1);
						string  url = "https://www.vietinbank.vn/web/home/vn/ty-gia/?theDate=" + day + "%2F" + month + "%2F" + year;

						getData(tienTe, url, inforDate);
						for (int i = 0; i < 17; i++)
						{
							resquest(cl1, tienTe[i].ten);
							resquest(cl1, tienTe[i].tyGiaTT);
							resquest(cl1, tienTe[i].tyGiaMua.tienMat);
							resquest(cl1, tienTe[i].tyGiaMua.chuyenKhoan);
							resquest(cl1, tienTe[i].tyGiaBan);
							resquest(cl1, tienTe[i].note);
						}
						resquest(cl1, inforDate);
					}
					if (strcmp(r, "0") == 0)
						break;
				
				
				}

			}
			else
				resquest(cl1, "0");
		}
		if (strcmp(r, "sign up") == 0)
		{
			USER u1;
			r = response(cl1);
			if (strcmp(r, "1") == 0)
			{
				u1.u = response(cl1);
				u1.p = response(cl1);
				//cout << u1.u << u1.p;
				cout << u1.u << u1.p;
				//cout << user[0].u << endl << user[0].p;
				if (checkUser("inforUser.txt", u1, 1) == 0) {
					saveFile("inforUser.txt", u1);
					cout << endl << "User: '" << u1.u << "'" << " has already been registered successfully";
					resquest(cl1, "1");
				}
				else resquest(cl1, "0");
			}
			if (strcmp(r, "0") == 0)
				resquest(cl1, "0");
		}
		

	}
	cl1.Close();
	//cnt--;
	delete hConnected;

	return 0;
	//return 0;
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
			// TODO: code your application's behavior here.
			AfxSocketInit(NULL);
			//socket sever va client
			CSocket sv;
			CSocket cl1;
			DWORD threadID;
			HANDLE threadStatus;
			//khoi tao socket voi port
			sv.Create(4567);
			cout << "\n\t\t\t\t\twaiting for client  ";
			do {

				sv.Listen();
				//neu client cuoi cung ngat ket noi thi tu dong sv ngat ket noi 
			/*	if (cnt == 0)
				{
					sv.Close();
					break;
				}*/
				if (sv.Accept(cl1))
					cout << "\n\t\t\t\t\tclient conected";
				//cnt++;
				//Khoi tao con tro Socket
				SOCKET* hConnected = new SOCKET();
				//Chuyển đỏi CSocket thanh Socket
				*hConnected = cl1.Detach();
				//Khoi tao thread tuong ung voi moi client Connect vao server.
				//Nhu vay moi client se doc lap nhau, khong phai cho doi tung client xu ly rieng
				//cout << cnt;
				threadStatus = CreateThread(NULL, 0, function_cal, hConnected, 0, &threadID);

			} while (1);
		}
	}
	else
	{
		// TODO: change error code to suit your needs
		wprintf(L"Fatal Error: GetModuleHandle failed\n");
		nRetCode = 1;
	}

	return nRetCode;
}

