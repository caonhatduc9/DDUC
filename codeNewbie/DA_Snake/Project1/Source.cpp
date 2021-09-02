#include<iostream>
using namespace std;
#include <stdio.h>
#include <conio.h>
#include<ctime> /* thư viện hỗ trợ về thời gian thực */
#include "windows.h" // thư viện này bá đạo lắm nhé - chứa nhiều đồ chơi nek - cứ tìm hiểu dần dần s
//======= lấy tọa độ x của con trỏ hiện tại =============

int SPEED = 2;
#define MAXFOOD 10
struct point {
	int x, y;
};
int U = 1, D = 28, L = 1, R = 82, idxFood = 0, maxFood = 6;
int amount = 6;
point snake[100];
point f;
int food[40] = { 2,0,1,2,7,4,6,6,2,0,1,2,7,5,5,0,2,0,1,2,7,3,5,0 };
point checkDoor1, checkDoor2, checkdoor3, checkdoor4;


void hiddenp();
void gotoXY(point p);
void SetColor(WORD color);

void control(int &check,point &p);

void FixConsoleWindow();
void  create_Wall();
void createSnake();
void generateSnake();
void clearSnake(point s[]);
void add(point p);
void delt( int pos);
void processSnake( point p);
bool touchBody(point c[]);
bool touch(point c[]);
void isGameOver(bool& gameover);
bool isValid(point f);
void generateFood();
bool  checkEat(point a, point b);
void door();
int main()
{
	hiddenp();
	bool gameover = false;
	int c;
	SetColor(1);
	
	cout << "1 new game\n2 exit";
	cin >> c;
	if (c == 1)
	{
		system("cls");
		
		FixConsoleWindow();

		create_Wall();
		SetColor(5);
		createSnake();
		generateSnake();

		SetColor(6);
		generateFood();
		point p = { 40,15 };
		int check = 2;//cho ran chay qua phai
	while (gameover == false)
		{
		clearSnake(snake);
		
		gotoXY({ 100,3 });
		cout << idxFood;
		control(check, p);
		processSnake(p);
		isGameOver(gameover);
		Sleep(500/SPEED);
				
		}
	gotoXY({ 100,5 });
	cout << "NGU VL!!!";
	
		_getch();
		
	}
}



void gotoXY(point p) {

	COORD coord;

	coord.X = p.x;

	coord.Y = p.y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//============= đặt màu cho chữ =========
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
//============== làm ẩn trỏ chuột ===========

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

void  create_Wall()
{
	SetColor(4);
	point p;
	p.x = L, p.y = U;
	while (p.x <= R)
	{
		gotoXY(p);
		cout << (char)219;
		p.x++;
		Sleep(0);
	}
	p.x = R, p.y = U;
	while (p.y <= D)
	{
		gotoXY(p);
		cout << (char)219;
		p.y++;
		Sleep(0);
	}
	p.x = R , p.y = D;
	while (p.x >= L)
	{
		gotoXY(p);
		cout << (char)219;
		p.x--;
		Sleep(0);
	}
	p.x = L, p.y = D;
	while (p.y >= U)
	{
		gotoXY(p);
		cout << (char)219;
		p.y--;
		Sleep(0);
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
		//for (int i = 0; i < amount; i++);
		cout << food[i];
	}
	
}

void add( point p)
{
	for (int i = amount-1; i >= 0; i--)
	{
		snake[i+1] = snake[i];
	}
	snake[0] = p;
	amount++;
}
void delt( int pos)
{
	for (int i = pos; i < amount; i++)
	{
		snake[i] = snake[i + 1];
	}
	amount--;
}
void processSnake(point p)
{
	add(p);
	
		if (checkEat(f, snake[0]) == false)
		{
		
				delt(amount - 1);
		}
		else
		{
			point temp;
			temp.x = f.x + 1;
			temp.y = f.y;
			gotoXY(temp);
			cout << " ";
			temp.x = f.x - 1;
			temp.y = f.y;
			gotoXY(temp);
			cout << " ";
			generateFood();
			idxFood++;
			if (idxFood == 2)
			{
				door();
				SPEED+=2;
				idxFood = 0;
			}

		}
	
			generateSnake();
}
void clearSnake(point s[])
{
	for (int i = 0; i < amount; i++)
	{
		gotoXY(s[i]);
		cout << " ";
	}
}
bool touchBody(point c[])
{
	for (int i = 1; i < amount; i++)
	{
		if (c[0].x == c[i].x && c[0].y == c[i].y)
			return true;
	}
	return false;
}
bool touch(point c[])
{
	if (c[0].x == L || c[0].x == R || c[0].y == D || c[0].y == U)
		return true;
	if ((c[0].x == checkDoor1.x && c[0].y == checkDoor1.y) || (c[0].x == checkDoor2.x && c[0].y == checkDoor2.y))
		return true;
		return false;
}
x
void generateFood()
{
	srand(time(NULL));
		do
		{
			f.x = (L + 1) + rand() % (R - L - 1);
			f.y = (U + 1) + rand() % (D - U - 1);
		} while (isValid(f) == false);
		gotoXY(f);
		cout << "0";
}
bool checkEat(point a, point b)
{
	
	if (a.x == b.x && a.y == b.y)
		return true;
	return false;

}
void control(int &check, point &p)
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
void isGameOver(bool& gameover)
{
	bool check1 = touchBody(snake);
	bool check2 = touch(snake);
	if (check1 == true || check2 == true)
		gameover = true;
}
void door()
{
	point d = f;
	d.x++;
	gotoXY(d);
	cout << (char)219;
	checkDoor2 = d;
	d.x -= 2;
	gotoXY(d);
	cout << (char)219;
	checkDoor1 = d;

}