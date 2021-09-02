/*
#include<iostream>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

void FixConsoleWindow()
{

	HWND consoleWindow = GetConsoleWindow();

	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);

	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);

	SetWindowLong(consoleWindow, GWL_STYLE, style);

}

void GotoXY(int x, int y) {

	COORD coord;

	coord.X = x;

	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

#define MAX_SIZE_SNAKE 10

#define MAX_SIZE_FOOD 4

#define MAX_SPEED 3

//Biến toàn cục

POINT snake[10]; //Con rắn

POINT food[4]; // Thức ăn

int CHAR_LOCK;//Biến xác định hướng không thể di chuyển (Ở một thời điểm có một


int MOVING;//Biến xác định hướng di chuyển của snake (Ở một thời điểm có ba
//hướng rắn có thể di chuyển)
int SPEED;// Có thể hiểu như level, level càng cao thì tốc độ càng nhanh
int HEIGH_CONSOLE, WIDTH_CONSOLE;// Độ rộng và độ cao của màn hình console
int FOOD_INDEX; // Chỉ số food hiện hành đang có trên màn hình
int SIZE_SNAKE; // Kích thước của snake, lúc đầu có 6 và tối đa lên tới 10
int STATE; // Trạng thái sống hay chết của rắn


bool IsValid(int x, int y) {

	for (int i = 0; i < SIZE_SNAKE; i++) {

		if (snake[i].x == x && snake[i].y == y) {

			return false;

			return true;

		}
	}
}


void GenerateFood()
{

	int x, y;
	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE_FOOD; i++) {
		do {
			x = rand() % (WIDTH_CONSOLE - 1) + 1;
			y = rand() % (HEIGH_CONSOLE - 1) + 1;

		} while (IsValid(x, y) == false);
		food[i] = { x,y };

	}

}

void ResetData() {
	//Khởi tạo các giá trị toàn cục
	CHAR_LOCK = 'A', MOVING = 'D', SPEED = 1; FOOD_INDEX = 0, WIDTH_CONSOLE = 70,
		HEIGH_CONSOLE = 20, SIZE_SNAKE = 6;
	//Khởi tạo giá trị mặc định cho snake
	snake[0] = { 10, 5 }; snake[1] = { 11, 5 };
	snake[2] = { 12, 5 }; snake[3] = { 13, 5 };
	snake[4] = { 14, 5 }; snake[5] = { 15, 5 };
	GenerateFood();//Tạo mảng thức ăn food

}

void StartGame() {

	system("cls");

	ResetData(); // Khởi tạo dữ liệu gốc

	DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE); // Vẽ màn hình game

	STATE = 1;//Bắt đầu cho Thread chạy

}


void DrawBoard(int x, int y, int width, int height, int curPosX = 0, int curPosY
	= 0) {

	GotoXY(x, y); cout << 'X';

	for (int i = 1; i < width; i++)cout << 'X';
	cout << 'X';
	GotoXY(x, height + y); cout << 'X';
	for (int i = 1; i < width; i++)cout << 'X';
	cout << 'X';
	for (int i = y + 1; i < height + y; i++) {
		GotoXY(x, i); cout << 'X';
		GotoXY(x + width, i); cout << 'X';

	}
	GotoXY(curPosX, curPosY);

}

void ExitGame(HANDLE t) {

	system("cls");

	TerminateThread(t, 0);

}

void PauseGame(HANDLE t) {
	SuspendThread(t);

}
//Hàm dừng game

//Hàm cập nhật dữ liệu toàn cục

void Eat() {

	snake[SIZE_SNAKE] = food[FOOD_INDEX];

	if (FOOD_INDEX == MAX_SIZE_FOOD - 1)

	{

		FOOD_INDEX = 0;

		SIZE_SNAKE = 6;

		if (SPEED == MAX_SPEED) SPEED = 1;

		else SPEED++;
		GenerateFood();
	}
	else {
		FOOD_INDEX++;
		SIZE_SNAKE++;

	}

}

void ProcessDead() {

	STATE = 0;

	GotoXY(0, HEIGH_CONSOLE + 2);

	printf("Dead, type y to continue or anykey to exit");
}
//Hàm vẽ màn hình

void DrawSnakeAndFood(char* str) {

	GotoXY(food[FOOD_INDEX].x, food[FOOD_INDEX].y);

	printf(str);

	for (int i = 0; i < SIZE_SNAKE; i++) {

		GotoXY(snake[i].x, snake[i].y);

		printf(str);

	}

}

void MoveRight() {

	if (snake[SIZE_SNAKE - 1].x + 1 == WIDTH_CONSOLE) {

		ProcessDead();

	}

	else {

		if (snake[SIZE_SNAKE - 1].x + 1 == food[FOOD_INDEX].x && snake[SIZE_SNAKE
			- 1].y == food[FOOD_INDEX].y) {

			Eat();

		}

		for (int i = 0; i < SIZE_SNAKE - 1; i++) {
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;

		}
		snake[SIZE_SNAKE - 1].x++;

	}

}

void MoveLeft() {
	if (snake[SIZE_SNAKE - 1].x - 1 == 0) {
		ProcessDead();

	}
	else {
		if (snake[SIZE_SNAKE - 1].x - 1 == food[FOOD_INDEX].x && snake[SIZE_SNAKE
			- 1].y == food[FOOD_INDEX].y) {
			Eat();

		}
		for (int i = 0; i < SIZE_SNAKE - 1; i++) {
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;

		}
		snake[SIZE_SNAKE - 1].x--;

	}

}

void MoveDown() {
	if (snake[SIZE_SNAKE - 1].y + 1 == HEIGH_CONSOLE) {
		ProcessDead();

	}
	else {
		if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE -
			1].y + 1 == food[FOOD_INDEX].y) {
			Eat();

		}
		for (int i = 0; i < SIZE_SNAKE - 1; i++) {
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;

		}
		snake[SIZE_SNAKE - 1].y++;

	}
}

void MoveUp() {
	if (snake[SIZE_SNAKE - 1].y - 1 == 0) {
		ProcessDead();

	}
	else {
		if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE -
			1].y - 1 == food[FOOD_INDEX].y) {
			Eat();

		}
		for (int i = 0; i < SIZE_SNAKE - 1; i++) {
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;

		}
		snake[SIZE_SNAKE - 1].y--;

	}

}




void ThreadFunc()
{

	while (1) {

		if (STATE == 1) {//Nếu vẫn còn snake vẫn còn sống
			DrawSnakeAndFood(" ");

			switch (MOVING) {

			case 'A':

				MoveLeft();

				break;
			case 'D':
				MoveRight();
				break;
			case 'W':
				MoveUp();
				break;
			case 'S':
				MoveDown();
				break;

			}
			DrawSnakeAndFood("O");
			Sleep(1000 / SPEED);//Hàm ngủ theo tốc độ SPEEED

		}

	}

}

//Hàm main

void main() {

	int temp;

	FixConsoleWindow();

	StartGame();

	thread t1(ThreadFunc); //Tao thread cho snake

	HANDLE handle_t1 = t1.native_handle(); //Lay handle cua thread

	while (1) {

		temp = toupper(getch());
		if (STATE == 1) {
			if (temp == 'P') {
				PauseGame(handle_t1);
			}
			else if (temp == 27) {
				ExitGame(handle_t1);
				return;

			}
			else {
				ResumeThread(handle_t1);
				if ((temp != CHAR_LOCK) && (temp == 'D' || temp == 'A' || temp ==
					'W' || temp == 'S'))
				{
					if (temp == 'D') CHAR_LOCK = 'A';
					else if (temp == 'W') CHAR_LOCK = 'S';
					else if (temp == 'S') CHAR_LOCK = 'W';
					else CHAR_LOCK = 'D';
					MOVING = temp;
				}
			}
		}
		else {
			if (temp == 'Y') StartGame();
			else {
				ExitGame(handle_t1);
				return;

			}

		}

	}

}*/
