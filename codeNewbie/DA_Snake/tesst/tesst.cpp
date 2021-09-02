#include<iostream>
using namespace std;
#include <stdio.h>
#include <conio.h>
#include<ctime> /* thư viện hỗ trợ về thời gian thực */
#include "windows.h" // thư viện này bá đạo lắm nhé - chứa nhiều đồ chơi nek - cứ tìm hiểu dần dần s
//======= lấy tọa độ x của con trỏ hiện tại =============
struct point {
	int x, y;
};
int amount = 4;
point snake[10];
int U = 3, L = 15, R = 80, D = 22;
void hiddenp()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = FALSE;
	info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}
void FixConsoleWindow()
{

	HWND consoleWindow = GetConsoleWindow();

	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);

	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);

	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void gotoXY(point p) {

	COORD coord;

	coord.X = p.x;

	coord.Y = p.y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void  create_Wall()
{
	SetColor(4);
	point p;
	p.x = L, p.y = U;
	while (p.x <= R)
	{
		gotoXY(p);
		cout << (char)3;
		p.x++;
		Sleep(1);
	}
	p.x = R, p.y = U;
	while (p.y <= D)
	{
		gotoXY(p);
		cout << (char)3;
		p.y++;
		Sleep(2);
	}
	p.x = R, p.y = D;
	while (p.x >= L)
	{
		gotoXY(p);
		cout << (char)3;
		p.x--;
		Sleep(1);
	}
	p.x = L, p.y = D;
	while (p.y >= U)
	{
		gotoXY(p);
		cout << (char)3;
		p.y--;
		Sleep(2);
	}
}

void createSnake()
{
	point p = { 40,15 };
	for (int i = 0; i < amount; i++)
	{
		snake[i] = p;
		p.x--;
	}
}
void generateSnake()
{

	for (int i = 0; i < amount; i++)
	{
		gotoXY(snake[i]);
		cout << (char)239;
	}

}
void clearSnake(point s[])
{
	for (int i = 0; i < amount; i++)
	{
		gotoXY(s[i]);
		cout << "  ";
	}
}
void control(int& check, point& p)
{
	if (_kbhit())
	{
		char k = _getch();
		if (k == 'w' && check != 1)
			check = 0;
		else if (k == 's' && check != 0)
			check = 1;
		else if (k == 'a' && check != 2)
			check = 3;
		else if (k == 'd' && check != 3)
			check = 2;
	}

	if (check == 1)//up
		p.y++;
	else if (check == 0)//dow
		p.y--;
	else if (check == 2)//left
		p.x++;
	else if (check == 3)//right
		p.x--;

}
int main() { 
	create_Wall();
	createSnake();
	generateSnake();
	int check = 2;
	while (2)
	{
		clearSnake(snake);
		control(check, p);
	}

	return 0;
}