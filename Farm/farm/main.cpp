#include<windows.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<fstream>
#include<mmsystem.h>
using namespace std;
int a[10] = { 160,90,105,37,35 };
void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void SetTColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0; wAttributes |= color;
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void noCursorType()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = FALSE;
	info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void title()
{
	GotoXY(37, 5);
	SetTColor(rand() % 14);
	//Sleep(700);
	cout << "  ######    ###      #########  ##      ##"<< endl;
	GotoXY(37, 6);
	cout << "  ##       ## ##     ##      #  ## #  # ##" << endl;
	GotoXY(37, 7);
	cout << "  ######  #######    #########  ##  #   ##" << endl;
	GotoXY(37, 8);	
	cout << "  ##     ##      ##  ## ##      ##      ##" << endl;
	GotoXY(37, 9);
	cout << "  ##    ##        ## ##   ##    ##      ##" << endl;
	GotoXY(37, 10);
	cout << "  ##   ##          ####     ##  ##      ##" << endl;
	//cout << "  ##   ##    # #    # #    # ######" << endl;
	SetTColor(4);
}
void food()
{
	GotoXY(37, 3);
	cout << "Ga ta:"; GotoXY(58, 3); cout << "160.000d / kg";
	GotoXY(37, 4);
	cout << "vit trang:"; GotoXY(58, 4); cout << "90.000d / kg";
	GotoXY(37, 5);
	cout << "Ga ta:"; GotoXY(58, 5); cout << "105.000d / kg";
	GotoXY(37, 6);
	cout << "Ga ta:"; GotoXY(58, 6); cout << "160.000d / kg";
	GotoXY(37, 7);
	cout << "Ga ta:"; GotoXY(58, 7); cout << "160.000d / kg";
	GotoXY(37, 8);
	cout << "Ga ta:"; GotoXY(58, 8); cout << "160.000d / kg";
	GotoXY(37, 9);
	cout << "Ga ta:"; GotoXY(58, 9); cout << "160.000d / kg";
	GotoXY(37, 10);
	cout << "Ga ta:"; GotoXY(58, 10); cout << "160.000d / kg";

}
int main()
{
	noCursorType();
	int choice;
	while (1)
	{

		title();
	//	Sleep(150);
		GotoXY(47, 12);
		cout << "MENU";
		GotoXY(47, 14);
		cout << "tinh tien";
		cin >> choice;
		if (choice == 1)
		{
			system("cls");
			food();
			
			//_getch();
			break;
		}
		else if(choice == 2)
		{
			system("cls");
			food();
			cout << "\n\n\t\t\t\t\tnhap san pham can ban:   ";
			int x;
			cin >> x;
			if (x == 1)
			{
				cout << "\n\t\t\t\tnhap so luong:   ";
				int cnt;
				cin >> cnt;
				cout << "\t\t\t\tgia: " << a[x - 1] * cnt << "k";
			}
		}
		//}
	}
	return 0;
}