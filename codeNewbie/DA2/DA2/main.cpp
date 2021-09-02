///*#include<windows.h>
//#include<time.h>
//#include<conio.h>
//#include<string.h>
//#include<iostream>
//using namespace std;
//enum trangthai { UP, DOWN, LEFT, RIGHT };
//
//
//#define chieudai 80
//#define chieurong 25
//#define maxsnakelength 10
//#define maxspeed 7
//#define TUONG_TREN 0
//#define TUONG_DUOI 25
//#define TUONG_TRAI 0
//#define TUONG_PHAI 80
//POINT FOOD;
//POINT SNAKE[100], cong[7], congOut[7];
//POINT VATCAN[20];
//int snakeLength = 6;
//int speed;
//int score;
//int idxFOOD = 0;
//int k;
//trangthai tt = RIGHT;
//char mssv[] = "3012788020127466201275639032598453498554976";
//void GotoXY(int x, int y)
//{
//	COORD coord;
//	coord.X = x;
//	coord.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}
//void SetTeColor(WORD color)
//{
//	HANDLE hConsoleOutput;
//	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
//	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
//	WORD wAttributes = screen_buffer_info.wAttributes;
//	color &= 0x000f;
//	wAttributes &= 0xfff0; wAttributes |= color;
//	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
//}
//void FixConsoleWindow()
//{
//	HWND consoleWindow = GetConsoleWindow();
//	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
//	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
//	SetWindowLong(consoleWindow, GWL_STYLE, style);
//}
//void noCursorType()
//{
//	CONSOLE_CURSOR_INFO info;
//	info.bVisible = FALSE;
//	info.dwSize = 20;
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
//}
//
//void taoran(char str)
//{
//	
//	if (str == 'x')
//	{
//		for (int i = 0; i < snakeLength; i++)
//		{
//			GotoXY(SNAKE[i].x, SNAKE[i].y);
//			cout << mssv[i];
//		}
//	}
//	else
//	{
//		for (int i = 0; i < snakeLength; i++)
//		{
//			GotoXY(SNAKE[i].x, SNAKE[i].y);
//			cout << str;
//		}
//	}
//}
//bool isValid(POINT F)
//{
//	for (int i = 0; i < snakeLength; i++)
//		if (SNAKE[i].x == F.x && SNAKE[i].y == F.y)
//			return false;
//	for (int i = 0; i < 7; i++)
//		if (cong[i].x == F.x && cong[i].y == F.y)
//			return false;
//	for (int i = 0; i < 10; i++)
//		if (VATCAN[i].x == F.x && VATCAN[i].y == F.y)
//			return false;
//	return true;
//}
//
//void taoVatCan()
//{
//	int idx = 0;
//	int j = rand() % 27 + 4;
//	int j1 = rand() % 30 + 45;
//
//	for (int i = 3; i < 8; i++)
//	{
//		VATCAN[idx++] = { j,i };
//		VATCAN[idx++] = { j1,i };
//
//	}
//	SetTeColor(rand() % 14);
//	int k = rand() % 2 - 1;
//	for (int i=0; i < 10; i++)
//	{
//		GotoXY(VATCAN[i].x, VATCAN[i].y);
//		cout << (char)178;
//		Sleep(50);
//	}
//}
//void xoaVat()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		GotoXY(VATCAN[i].x, VATCAN[i].y);
//		cout << " ";
//		cong[i] = { 900 + i,900 };
//		Sleep(20);
//	}
//}
//void taoCong()
//{
//	int idx = 0;
//	do
//	{
//		FOOD.x = rand() % (TUONG_PHAI - TUONG_TRAI - 3) + TUONG_TRAI + 2;
//		FOOD.y = rand() % (TUONG_DUOI - TUONG_TREN - 9) + TUONG_TREN + 5;
//	} while (isValid(FOOD) == false);
//	SetTeColor(rand() % 14);
//	int k = rand() % 2 - 1;
//	for (int i = FOOD.x - 1; i <= FOOD.x + 1; i++)
//	{
//			cong[idx].x = i;
//			cong[idx].y = FOOD.y;
//			idx++;
//		GotoXY(i, FOOD.y);
//		cout << (char)178;
//	}
//	for (int i = 2 * k + FOOD.y + k + 1; i <= 2 * k + FOOD.y + 2 + k; i++)
//	{
//		cong[idx].x = FOOD.x - 1;
//		cong[idx].y = i;
//		idx++;
//		GotoXY(FOOD.x - 1,i);
//		cout << (char)178;
//		cong[idx].x = FOOD.x + 1;
//		cong[idx].y = i ;
//		idx++;
//		GotoXY(FOOD.x + 1, i);
//	cout << (char)178;
//	}
//}
//void drawGate() {
//	for (int i = 0; i < 7; i++)
//	{
//		GotoXY(cong[i].x, cong[i].y);
//			cout << (char)178;
//	}
//}
//void xoaCong()
//{
//
//	for (int i = 0; i < 7; i++)
//	{
//
//		GotoXY(cong[i].x, cong[i].y);
//		cout << " ";
//		cong[i] = { 500+i,500 };
//		
//		Sleep(40);
//	}
//}
//void xoaCongOut()
//{
//	for (int i = 0; i < 7; i++)
//	{
//		GotoXY(congOut[i].x, congOut[i].y);
//		cout << " ";
//		congOut[i] = { 1000 + i,1000 + i };
//		Sleep(40);
//	}
//}
//void taofood()
//{
//	srand(time(NULL));
//	do
//	{
//		FOOD.x = rand() % (chieudai - 2) + 1;
//		FOOD.y = rand() % (chieurong - 2) + 1;
//	} while (isValid(FOOD) == false);
//	idxFOOD++;
//	if (idxFOOD == 5) {
//		taoCong();
//	}
//	else
//	{
//		GotoXY(FOOD.x, FOOD.y);
//		cout << "x";
//	}
//}
//void taoCongRa()
//
//{
//	POINT out;
//	do
//	{
//		out.x = rand() % (TUONG_PHAI - TUONG_TRAI - 1) + TUONG_TRAI + 1;
//		out.y = rand() % (TUONG_DUOI - TUONG_TREN - 9) + TUONG_TREN + 5;
//	} while (isValid(out) == false);
//	SetTeColor(rand() % 14);
//	int idx = 0;
//	for (int i = out.x - 1; i <= out.x + 1; i++)
//	{
//		congOut[idx].x = i, congOut[idx].y = out.y;
//		idx++;
//		GotoXY(i, out.y);
//		cout << (char)178;
//	}
//	for (int i = out.y - 2; i <= out.y -1; i++)
//	{
//		congOut[idx].x = out.x - 1, congOut[idx].y = i;
//		idx++;
//		GotoXY(out.x - 1, i);
//		cout << (char)178;
//		congOut[idx].x = out.x + 1;
//		congOut[idx].y = i;
//		idx++;
//		GotoXY(out.x + 1, i);
//		cout << (char)178;
//	}
//	SNAKE[0] = { out.x,out.y-1 };
//}
//void funny()
//{
//	cout << "\n........../''')Chi........\n";
//	cout << "........,/-../Tay.........\n";
//	cout << "......../.../Len..........\n";
//	cout << "......./.../Troi..........\n";
//	cout << "....../'-/'..'/'--',...Han\n";
//	cout << "..../'/.../..../.../..-Doi\n";
//	cout << "...('(...`...`..-~/'.')Vo.\n";
//	cout << "...\\...*SHOCK*.../.....Doi\n";
//	cout << "....\\'..\\......_/.........\n";
//	cout << ".....\\.........(..........\n";
//	cout << "......\\.........\\.........\n";
//}
//void huongdansudung()
//{
//	
//		
//		GotoXY(90, 15);
//		cout << "Nhan A qua trai ";
//		GotoXY(90, 16);
//		cout << "Nhan D qua phai ";
//		GotoXY(90, 17);
//		cout << "Nhan W len tren ";
//		GotoXY(90, 18);
//		cout << "Nhan S xuong duoi ";
//	
//}
//void Score()
//{
//	SetTeColor(3);
//	for (int i = 90; i < 110; i++)
//	{
//		GotoXY(i, 9);
//		cout << "*";
//		GotoXY(i, 11);
//		cout << "*";
//	}
//	for (int i = 10; i < 12; i++)
//	{
//		GotoXY(90, i);
//		cout << "*";
//		GotoXY(109, i);
//		cout << "*";
//	}
//	GotoXY(95, 10);
//	SetTeColor(4);
//	cout << "score : " << score * 10;
//}
//void DrawBoard()
//{
//	for (int i = TUONG_TRAI; i <= TUONG_PHAI; i++)
//	{
//		Sleep(0); GotoXY(i, TUONG_TREN); cout << (char)220;
//	}
//	for (int i = TUONG_TREN + 1; i <= TUONG_DUOI; i++)
//	{
//		Sleep(0); GotoXY(TUONG_PHAI, i); cout << (char)219;
//	}
//	for (int i = TUONG_TRAI; i <= TUONG_PHAI; i++)
//	{
//		GotoXY(i, TUONG_DUOI); cout << (char)223;Sleep(0);
//	}
//	for (int i = TUONG_TREN + 1; i < TUONG_DUOI; i++)
//	{
//		GotoXY(TUONG_TRAI, i); cout << (char)219; Sleep(0);
//	}
//}
//
//void resetdata()
//{
//	idxFOOD = 0;
//	speed = 0;
//	score = 0;
//	tt = RIGHT;
//	SNAKE[0] = { 26,10 };
//	SNAKE[1] = { 25,10 };
//	SNAKE[2] = { 24,10 };
//	SNAKE[3] = { 23,10 };
//	SNAKE[4] = { 22,10 };
//	SNAKE[5] = { 21,10 };
//	snakeLength = 6;
//	xoaCong();
//	xoaCongOut();
//	taofood();
//}
//void startgame()
//{
//	srand(time(NULL));
//	system("cls");
//	resetdata();
//	SetTeColor(rand() % 14);
//	DrawBoard();
//	taoVatCan();
//	Score();
//}
//void taorankhonglo()
//{
//
//	//  ####  #    #   ##   #    # ###### 
//	// #      ##   #  #  #  #   #  # 
//	//  ####  # #  # #    # ####   #####  
//	//     #  #  # # ###### #  #   #   
//	//#    #  #   ## #    # #   #  #  
//	// ####   #    # #    # #    # ###### 
//}
//void Title()
//{
//	GotoXY(40, 5);
//	SetTeColor(rand() % 14);
//	//Sleep(700);
//	cout << "   ####  #    #   ##   #    # ######" << endl;
//	GotoXY(40, 6);
//	cout << "  #      ##   #  #  #  #   #  #" << endl;
//	GotoXY(40, 7);
//	cout << "   ####  # #  # #    # ####   #####" << endl;
//	GotoXY(40, 8);
//	cout << "      #  #  # # ###### #  #   #" << endl;
//	GotoXY(40, 9);
//	cout << " #    #  #   ## #    # #   #  #" << endl;
//	GotoXY(40, 10);
//	cout << "  ####   #    # #    # #    # ######" << endl;
//	SetTeColor(0);
//
//}
//bool menu()
//{
//	int x = 0;
//	while (1)
//	{
//		Title();
//		Sleep(0.1);
//		GotoXY(55, 15);
//		cout << "start game";
//		GotoXY(55, 16);
//		cout << "exit";
//		if (x == 0)
//		{
//			GotoXY(55, 15);
//			SetTeColor(rand() % 14);
//			cout << "start game" << endl;
//			SetTeColor(0);
//		}
//		else if (x == 1)
//		{
//			GotoXY(55, 16);
//			SetTeColor(rand() % 14);
//			cout << "exit";
//			SetTeColor(0);
//		}
//		char temp;
//
//		if (_kbhit())
//		{
//			temp = _getch();
//			if ((temp == 13) && x == 0)
//			{
//				startgame();
//				return true;
//			}
//			if ((temp == 13) && x == 1)
//			{
//				return false;
//			}
//			else if ((temp == 'W' || temp == 'w') && x != 0)
//			{
//				x--;
//			}
//			else if ((temp == 'S' || temp == 's') && x != 1)
//			{
//				x++;
//			}
//		}
//		Sleep(100);
//	}
//}
//void dichuyen()
//{
//	if (tt == RIGHT)
//	{
//		for (int i = snakeLength - 1; i > 0; i--)
//		{
//			SNAKE[i] = SNAKE[i - 1];
//		}
//		SNAKE[0].x++;
//	}
//	else if (tt == LEFT)
//	{
//		for (int i = snakeLength - 1; i > 0; i--)
//		{
//			SNAKE[i] = SNAKE[i - 1];
//		}
//		SNAKE[0].x--;
//	}
//	else if (tt == UP)
//	{
//		for (int i = snakeLength - 1; i > 0; i--)
//		{
//			SNAKE[i] = SNAKE[i - 1];
//		}
//		SNAKE[0].y--;
//	}
//	else if (tt == DOWN)
//	{
//		for (int i = snakeLength - 1; i > 0; i--)
//		{
//			SNAKE[i] = SNAKE[i - 1];
//		}
//		SNAKE[0].y++;
//	}
//}
//void hieuUngChet()
//{
//	for (int i = 0; i < 3; i++)
//	{
//		Sleep(150);
//		for (int j = 0; j < snakeLength - 1; j++)
//			if (j % 3 == 0)
//			{
//				GotoXY(SNAKE[j].x + i, SNAKE[j].y);
//				cout << (char)001;
//				GotoXY(SNAKE[j].x - i, SNAKE[j].y);
//				cout << (char)001;
//				GotoXY(SNAKE[j].x, SNAKE[j].y + i);
//				cout << (char)001;
//				GotoXY(SNAKE[j].x, SNAKE[j].y - i);
//				cout << (char)001;
//				if (i == 2)
//				{
//					GotoXY(SNAKE[j].x - 1, SNAKE[j].y - 1);
//					cout << (char)001;
//					GotoXY(SNAKE[j].x + 1, SNAKE[j].y + 1);
//					cout << (char)001;
//					GotoXY(SNAKE[j].x + 1, SNAKE[j].y - 1);
//					cout << (char)001;
//					GotoXY(SNAKE[j].x - 1, SNAKE[j].y + 1);
//					cout << (char)001;
//				}
//			}
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		Sleep(150);
//		for (int j = 0; j < snakeLength - 1; j++)
//			if (j % 3 == 0)
//			{
//				GotoXY(SNAKE[j].x + i, SNAKE[j].y);
//				cout << " ";
//				GotoXY(SNAKE[j].x - i, SNAKE[j].y);
//				cout << " ";
//				GotoXY(SNAKE[j].x, SNAKE[j].y + i);
//				cout << " ";
//				GotoXY(SNAKE[j].x, SNAKE[j].y - i);
//				cout << " ";
//				if (i == 2)
//				{
//					GotoXY(SNAKE[j].x - 1, SNAKE[j].y - 1);
//					cout << " ";
//					GotoXY(SNAKE[j].x + 1, SNAKE[j].y + 1);
//					cout << " ";
//					GotoXY(SNAKE[j].x + 1, SNAKE[j].y - 1);
//					cout << " ";
//					GotoXY(SNAKE[j].x - 1, SNAKE[j].y + 1);
//					cout << " ";
//				}
//			}
//	}
//}
//void gameOver()
//{
//	hieuUngChet();
//	GotoXY(33, 10);
//	cout << "GAME OVER!!!";
//	xoaCong();
//	xoaCongOut();
//	_getch(); 
//	startgame();
//}
//
//void dead()
//{
//	if (SNAKE[0].x == TUONG_TRAI || SNAKE[0].x == TUONG_PHAI || SNAKE[0].y == TUONG_TREN || SNAKE[0].y == TUONG_DUOI)
//	{
//		gameOver();
//	}
//
//	for (int i = 1; i < snakeLength - 1; i++)
//	{
//		if (SNAKE[0].x == SNAKE[i].x && SNAKE[0].y == SNAKE[i].y)
//		{
//			gameOver();
//		}
//	}if (idxFOOD == 5)
//	{
//		for (int i = 0; i < 7; i++)
//		{
//			if (i != 1)
//			{
//				if (SNAKE[0].x == cong[i].x && SNAKE[0].y == cong[i].y)
//				{
//
//					gameOver();
//				}
//			}
//			else
//			{
//				if (cong[5].y < cong[0].y)
//				{
//					if (SNAKE[0].x == cong[1].x && SNAKE[0].y == cong[1].y + 1 && SNAKE[0].y < SNAKE[1].y)
//						gameOver();
//				}
//				else if (cong[5].y > cong[0].y)
//					if (SNAKE[0].x == cong[1].x && SNAKE[0].y == cong[1].y - 1 && SNAKE[0].y > SNAKE[1].y)
//						gameOver();
//			}
//
//		}
//	}
//	
//	for (int i = 0; i < 7; i++)
//	if (SNAKE[0].x == congOut[i].x && SNAKE[0].y == congOut[i].y)
//		gameOver(); 
//	for (int i = 0; i < 10; i++)
//		if (SNAKE[0].x == VATCAN[i].x && SNAKE[0].y == VATCAN[i].y)
//			gameOver();
//}
//
//
//void tangchieudairan()
//{
//	
//	if (SNAKE[0].x == FOOD.x && SNAKE[0].y == FOOD.y)
//	{
//		taofood();	
//		if (snakeLength == maxsnakelength)
//		{
//			xoaVat();
//			idxFOOD = 1;
//			xoaCong();
//			snakeLength = 6;
//			tt = UP;
//			taoCongRa();
//			taoVatCan();
//		}
//		
//		else
//		{
//			snakeLength++;
//			SNAKE[snakeLength - 1] = SNAKE[snakeLength - 2];
//		}
//		
//		score++;
//		Score();
//	}
//	if (SNAKE[snakeLength-1].x == congOut[1].x && SNAKE[snakeLength - 1].y == congOut[1].y-3)
//		xoaCongOut();
//}
//
//
//void PAUSE()
//{
//	GotoXY(20, 10);
//	cout << "press enter to continue";
//	cin.get();
//	system("cls");
//	DrawBoard();
//	GotoXY(FOOD.x, FOOD.y);
//	cout << "x";
//}
//void exitgame()
//{
//	GotoXY(45, 13);
//	cout << "thanks for your playing game";
//	cin.get();
//}
//void Key(char& temp)
//{
//	
//}
//void main()
//{
//	noCursorType();
//	FixConsoleWindow();
//	char temp;
//	if (menu())
//		while (1)
//		{
//			huongdansudung();
//			taoran(' ');
//			
//			if (_kbhit())
//			{
//				temp = _getch();
//				if ((temp == 'A' || temp == 'a') && tt != RIGHT)
//					tt = LEFT;
//				else if ((temp == 'D' || temp == 'd') && tt != LEFT)
//					tt = RIGHT;
//				else if ((temp == 'W' || temp == 'w') && tt != DOWN)
//					tt = UP;
//				else if ((temp == 'S' || temp == 's') && tt != UP)
//					tt = DOWN;
//				else if (temp == 'P' || temp == 'p')
//					PAUSE();
//				else if (temp == 27)
//				{
//					system("cls");
//					break;
//				}
//			}
//
//			dichuyen();
//			tangchieudairan();
//			dead();
//			SetTeColor(16);
//			taoran('x');
//			Sleep(100);
//		}
//	//funny();
//	
//	exitgame();
//	_getch();
//}
//*/
//#include<windows.h>
//#include<time.h>
//#include<conio.h>
//#include<string.h>
//#include<string>
//#include<iostream>
//#include<fstream>
//#include<mmsystem.h>
//using namespace std;
//enum trangthai { UP, DOWN, LEFT, RIGHT };
//
//#define chieudai 70
//#define chieurong 25
//#define maxsnakelength 10
//#define maxspeed 7
//
//int level = 1;
//POINT FOOD;
//POINT SNAKE[100], cong[7], congOut[7], VATCAN[10];
//char temp;
//int snakeLength = 6;
//int speed;
//int score;
//int idxFOOD = 0;
//int k;
//trangthai tt = RIGHT;
//char mssv[] = "fuckyoubitch12345";
//void GotoXY(int x, int y)
//{
//	COORD coord;
//	coord.X = x;
//	coord.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}
//void SetTeColor(WORD color)
//{
//	HANDLE hConsoleOutput;
//	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
//	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
//	WORD wAttributes = screen_buffer_info.wAttributes;
//	color &= 0x000f;
//	wAttributes &= 0xfff0; wAttributes |= color;
//	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
//}
//void FixConsoleWindow()
//{
//	HWND consoleWindow = GetConsoleWindow();
//	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
//	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
//	SetWindowLong(consoleWindow, GWL_STYLE, style);
//}
//void noCursorType()
//{
//	CONSOLE_CURSOR_INFO info;
//	info.bVisible = FALSE;
//	info.dwSize = 20;
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
//}
//
//void LevelAndScore()
//{
//	//lv
//	SetTeColor(3);
//	for (int i = 83; i <= 103; i++)
//	{
//		GotoXY(i, 2);
//		cout << "*";
//		GotoXY(i, 2);
//		cout << "*";
//	}
//	for (int i = 3; i < 5; i++)
//	{
//		GotoXY(83, i);
//		cout << "*";
//		GotoXY(103, i);
//		cout << "*";
//	}
//	for (int i = 83; i <= 103; i++)
//	{
//		GotoXY(i, 5);
//		cout << "*";
//		GotoXY(i, 5);
//		cout << "*";
//	}
//	GotoXY(89, 3);
//	SetTeColor(4);
//	cout << "Level : " << level;
//
//	//score
//	GotoXY(89, 4);
//	SetTeColor(4);
//	cout << "score : " << score * 10;
//}
//
//void howToPlay()
//{
//	GotoXY(85, 8);
//	cout << "How to play snake";
//	GotoXY(83, 10);
//	cout << "Options : Press Esc ";
//	GotoXY(89, 11);
//	cout << char(17) << " : Press A left";
//	GotoXY(89, 12);
//	cout << char(16) << " : Press D right";
//	GotoXY(89, 13);
//	cout << char(30) << " : Press W up";
//	GotoXY(89, 14);
//	cout << char(31) << " : Press S down";
//}
//
//void taoran(char str)
//{
//	if (str == 'x')
//	{
//		for (int i = 0; i < snakeLength; i++)
//		{
//			GotoXY(SNAKE[i].x, SNAKE[i].y);
//			cout << mssv[i];
//		}
//	}
//	else
//	{
//		for (int i = 0; i < snakeLength; i++)
//		{
//			GotoXY(SNAKE[i].x, SNAKE[i].y);
//			cout << str;
//		}
//	}
//}
//bool isValid(POINT F)
//{
//	for (int i = 0; i < snakeLength; i++)
//		if (SNAKE[i].x == F.x && SNAKE[i].y == F.y)
//			return false;
//	for (int i = 0; i < 7; i++)
//		if (cong[i].x == F.x && cong[i].y == F.y)
//			return false;
//	for (int i = 0; i < 10; i++)
//		if ((VATCAN[i].x == F.x && VATCAN[i].y == F.y) || (VATCAN[i].x + 1 == F.x && VATCAN[i].y == F.y) || (VATCAN[i].x - 1 == F.x && VATCAN[i].y == F.y))
//			return false;
//	return true;
//}
//
//void taoVatCan()
//{
//	int idx = 0;
//	int j = rand() % 30 + 1;
//	int j1 = rand() % 34 + 35;
//
//	for (int i = 3; i < 8; i++)
//	{
//		VATCAN[idx++] = { j,i };
//		VATCAN[idx++] = { j1,i };
//
//	}
//	SetTeColor(rand() % 14);
//	int k = rand() % 2 - 1;
//	for (int i = 0; i < 10; i++)
//	{
//		GotoXY(VATCAN[i].x, VATCAN[i].y);
//		cout << (char)178;
//		Sleep(50);
//	}
//}
//void xoaVat()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		GotoXY(VATCAN[i].x, VATCAN[i].y);
//		cout << " ";
//		VATCAN[i] = { 900 + i,900 };
//		Sleep(20);
//	}
//}
//
//void drawGate()
//{
//	for (int i = 0; i < 7; i++)
//	{
//		GotoXY(cong[i].x, cong[i].y);
//		cout << (char)178;
//	}
//}
//void taoCong()
//{
//	int idx = 0;
//	do
//	{
//		FOOD.x = rand() % (chieudai - 3) + 2;
//		FOOD.y = rand() % (chieurong - 9) + 5;
//	} while (isValid(FOOD) == false);
//	SetTeColor(rand() % 14);
//	int k = rand() % 2 - 1;
//	for (int i = FOOD.x - 1; i <= FOOD.x + 1; i++)
//	{
//		cong[idx].x = i;
//		cong[idx].y = FOOD.y;
//		idx++;
//		GotoXY(i, FOOD.y);
//		cout << (char)178;
//	}
//	for (int i = 2 * k + FOOD.y + k + 1; i <= 2 * k + FOOD.y + 2 + k; i++)
//	{
//		cong[idx].x = FOOD.x - 1;
//		cong[idx].y = i;
//		idx++;
//		GotoXY(FOOD.x - 1, i);
//		cout << (char)178;
//		cong[idx].x = FOOD.x + 1;
//		cong[idx].y = i;
//		idx++;
//		GotoXY(FOOD.x + 1, i);
//		cout << (char)178;
//	}
//}
//void xoaCong()
//{
//
//	for (int i = 0; i < 7; i++)
//	{
//		GotoXY(cong[i].x, cong[i].y);
//		cout << " ";
//		cong[i] = { 500 + i,500 };
//		Sleep(40);
//	}
//}
//void xoaCongOut()
//{
//	for (int i = 0; i < 7; i++)
//	{
//		GotoXY(congOut[i].x, congOut[i].y);
//		cout << " ";
//		congOut[i] = { 1000 + i,1000 + i };
//		Sleep(0);
//	}
//}
//
//void taoCongRa()
//{
//	POINT out;
//	do
//	{
//		out.x = rand() % (chieudai - 3) + 2;
//		out.y = rand() % (chieurong - 9) + 5;
//	} while (isValid(out) == false);
//	SetTeColor(rand() % 14);
//	int idx = 0;
//	for (int i = out.x - 1; i <= out.x + 1; i++)
//	{
//		congOut[idx].x = i, congOut[idx].y = out.y;
//		idx++;
//		GotoXY(i, out.y);
//		cout << (char)178;
//	}
//	for (int i = out.y - 2; i <= out.y - 1; i++)
//	{
//		congOut[idx].x = out.x - 1, congOut[idx].y = i;
//		idx++;
//		GotoXY(out.x - 1, i);
//		cout << (char)178;
//		congOut[idx].x = out.x + 1;
//		congOut[idx].y = i;
//		idx++;
//		GotoXY(out.x + 1, i);
//		cout << (char)178;
//	}
//	SNAKE[0] = { out.x,out.y - 1 };
//}
//void taofood()
//{
//	srand(time(NULL));
//	do
//	{
//		FOOD.x = rand() % (chieudai - 2) + 1;
//		FOOD.y = rand() % (chieurong - 2) + 1;
//	} while (isValid(FOOD) == false);
//	idxFOOD++;
//	if (idxFOOD == 5) {
//		taoCong();
//	}
//	else
//	{
//		GotoXY(FOOD.x, FOOD.y);
//		cout << "x";
//	}
//}
//
///*  ##### #    #   ##   #    # #    #    #   #  ####  #    #
//	#   #    #  #  #  ##   # #   #      # #  #    # #    #
//	#   ###### #    # # #  # ####        #   #    # #    #
//	#   #    # ###### #  # # #  #        #   #    # #    #
//	#   #    # #    # #   ## #   #       #   #    # #    #
//	#   #    # #    # #    # #    #      #    ####   ####*/
//void funny()
//{
//	system("cls");
//	SetTeColor(rand() % 14);
//	GotoXY(37, 8);
//	cout << "##### #    #   ##   #    # #    #    #   #  ####  #    #\n";
//	GotoXY(37, 9);
//	cout << "  #   #    #  #  #  ##   # #   #      # #  #    # #    #\n";
//	GotoXY(37, 10);
//	cout << "  #   ###### #    # # #  # ####        #   #    # #    #\n";
//	GotoXY(37, 11);
//	cout << "  #   #    # ###### #  # # #  #        #   #    # #    #\n";
//	GotoXY(37, 12);
//	cout << "  #   #    # #    # #   ## #   #       #   #    # #    #\n";
//	GotoXY(37, 13);
//	cout << "  #   #    # #    # #    # #    #      #    ####   ####\n";
//	GotoXY(37, 14);
//	SetTeColor(0);
//	GotoXY(37, 15);
//	cout << "    Press and key to close....";
//}
//void DrawBoard()
//{
//	GotoXY(0, 0);
//	for (int i = 1; i <= chieudai + 1; i++)
//		cout << char(220);
//	for (int i = 1; i < chieurong; i++)
//	{
//		GotoXY(0, i);
//		cout << char(219);
//	}
//	GotoXY(0, chieurong);
//	for (int i = 0; i < chieudai + 1; i++)
//	{
//		cout << char(223);
//	}
//	for (int i = 1; i < chieurong; i++)
//	{
//		GotoXY(chieudai, i);
//		cout << char(219);
//	}
//
//	GotoXY(chieudai + 3, 0);
//	for (int i = 1; i <= 41; i++)
//		cout << char(220);
//	for (int i = 1; i < chieurong; i++)
//	{
//		GotoXY(chieudai + 3, i);
//		cout << char(219);
//	}
//	GotoXY(chieudai + 3, chieurong);
//	for (int i = 0; i < 41; i++)
//	{
//		cout << char(223);
//	}
//	for (int i = 1; i < chieurong; i++)
//	{
//		GotoXY(chieudai + 3 + 40, i);
//		cout << char(219);
//	}
//}
//
//void resetdata()
//{
//	idxFOOD = 0;
//	speed = 0;
//	score = 0;
//	tt = RIGHT;
//	SNAKE[0] = { 26,10 };
//	SNAKE[1] = { 25,10 };
//	SNAKE[2] = { 24,10 };
//	SNAKE[3] = { 23,10 };
//	SNAKE[4] = { 22,10 };
//	SNAKE[5] = { 21,10 };
//	snakeLength = 6;
//	xoaCong();
//	xoaCongOut();
//	xoaVat();
//	taofood();
//}
//void startgame()
//{
//
//	srand(time(NULL));
//	system("cls");
//	resetdata();
//	SetTeColor(rand() % 14);
//	DrawBoard();
//	taoVatCan();
//	LevelAndScore();
//	howToPlay();
//}
//void Save()
//{
//	ofstream fp;
//	fp.open("SaveLoad.txt");
//	if (tt == RIGHT)
//		fp << "right" << endl;
//	else if (tt == LEFT)
//		fp << "left\n";
//	else if (tt == UP)
//		fp << "up\n";
//	else if (tt == DOWN)
//		fp << "down\n";
//	fp << snakeLength << endl;
//	fp << score << endl;
//	fp << speed << endl;
//	fp << idxFOOD << endl;
//	fp << FOOD.x << " " << FOOD.y << endl;
//	for (int i = 0; i < 7; i++)
//	{
//		fp << cong[i].x << " " << cong[i].y << endl;
//	}
//	for (int i = 0; i < snakeLength; i++)
//	{
//		fp << SNAKE[i].x << " " << SNAKE[i].y << endl;
//	}
//	fp.close();
//	cout << "ban da save successfully" << endl;
//	cin.get();
//
//}
//void Load()
//{
//	ifstream fp;
//	string x;
//	fp.open("SaveLoad.txt");
//	getline(fp, x);
//	if (x == "right")
//		tt = RIGHT;
//	else if (x == "left")
//		tt = LEFT;
//	else if (x == "up")
//		tt = UP;
//	else if (x == "down")
//		tt = DOWN;
//	fp >> snakeLength;
//	fp >> score;
//	fp >> speed;
//	fp >> idxFOOD;
//	fp >> FOOD.x >> FOOD.y;
//	for (int i = 0; i < 7; i++)
//	{
//		fp >> cong[i].x >> cong[i].y;
//	}
//	for (int i = 0; i < snakeLength; i++)
//	{
//		fp >> SNAKE[i].x >> SNAKE[i].y;
//	}
//	fp.close();
//}
//void taorankhonglo()
//{
//
//	//  ####  #    #   ##   #    # ###### 
//	// #      ##   #  #  #  #   #  # 
//	//  ####  # #  # #    # ####   #####  
//	//     #  #  # # ###### #  #   #   
//	//#    #  #   ## #    # #   #  #  
//	// ####   #    # #    # #    # ###### 
//}
//void Title()
//{
//	GotoXY(40, 5);
//	SetTeColor(rand() % 14);
//	//Sleep(700);
//	cout << "   ####  #    #   ##   #    # ######" << endl;
//	GotoXY(40, 6);
//	cout << "  #      ##   #  #  #  #   #  #" << endl;
//	GotoXY(40, 7);
//	cout << "   ####  # #  # #    # ####   #####" << endl;
//	GotoXY(40, 8);
//	cout << "      #  #  # # ###### #  #   #" << endl;
//	GotoXY(40, 9);
//	cout << " #    #  #   ## #    # #   #  #" << endl;
//	GotoXY(40, 10);
//	cout << "  ####   #    # #    # #    # ######" << endl;
//	SetTeColor(0);
//}
//void aboutUs()
//{
//	system("cls");
//	GotoXY(40, 8);
//	cout << "20127466_Cao Nhat Duc\n";
//	GotoXY(40, 9);
//	cout << "20127614_Huynh Ngoc Son\n";
//	GotoXY(40, 10);
//	cout << "20127272_Tran Thinh Phat\n";
//	GotoXY(40, 11);
//	cout << "20127657_Nguyen Dang Manh Tu\n";
//	GotoXY(40, 12);
//	cout << "20127550_Doan Huu LOc\n";
//
//}
//void startGameByLoad()
//{
//	srand(time(NULL));
//	system("cls");
//	SetTeColor(rand() % 14);
//	DrawBoard();
//	LevelAndScore();
//	howToPlay();
//	if (idxFOOD == 5)
//	{
//		drawGate();
//	}
//	else
//	{
//		GotoXY(FOOD.x, FOOD.y);
//		cout << "x";
//	}
//}
//bool menu()
//{
//	int x = 0;
//	while (1)
//	{
//
//		Title();
//		Sleep(0.1);
//		GotoXY(55, 15);
//		cout << "start game";
//		GotoXY(55, 16);
//		cout << "load game";
//		GotoXY(55, 17);
//		cout << "about us";
//		GotoXY(55, 18);
//		cout << "exit";
//		if (x == 0)
//		{
//			GotoXY(55, 15);
//			SetTeColor(rand() % 14);
//			cout << "start game" << endl;
//			SetTeColor(0);
//		}
//		else if (x == 1)
//		{
//			GotoXY(55, 16);
//			SetTeColor(rand() % 14);
//			cout << "load game" << endl;
//			SetTeColor(0);
//		}
//		else if (x == 2)
//		{
//			GotoXY(55, 17);
//			SetTeColor(rand() % 14);
//			cout << "about us";
//			SetTeColor(0);
//		}
//		else if (x == 3)
//		{
//			GotoXY(55, 18);
//			SetTeColor(rand() % 14);
//			cout << "exit" << endl;
//			SetTeColor(0);
//		}
//		char temp;
//
//		if (_kbhit())
//		{
//			temp = _getch();
//			if ((temp == 13) && x == 0)
//			{
//				startgame();
//				return true;
//			}
//			if ((temp == 13) && x == 1)
//			{
//				Load();
//				startGameByLoad();
//				return true;
//			}
//			if ((temp == 13) && x == 2)
//			{
//				aboutUs();
//				temp = _getch();
//				system("cls");
//			}
//			if ((temp == 13) && x == 3)
//			{
//				return false;
//			}
//			else if ((temp == 'W' || temp == 'w') && x != 0)
//			{
//				x--;
//			}
//			else if ((temp == 'S' || temp == 's') && x != 3)
//			{
//				x++;
//			}
//		}
//		Sleep(100);
//	}
//	return 0;
//}
//void dichuyen()
//{
//	if (tt == RIGHT)
//	{
//		for (int i = snakeLength - 1; i > 0; i--)
//		{
//			SNAKE[i] = SNAKE[i - 1];
//		}
//		SNAKE[0].x++;
//	}
//	else if (tt == LEFT)
//	{
//		for (int i = snakeLength - 1; i > 0; i--)
//		{
//			SNAKE[i] = SNAKE[i - 1];
//		}
//		SNAKE[0].x--;
//	}
//	else if (tt == UP)
//	{
//		for (int i = snakeLength - 1; i > 0; i--)
//		{
//			SNAKE[i] = SNAKE[i - 1];
//		}
//		SNAKE[0].y--;
//	}
//	else if (tt == DOWN)
//	{
//		for (int i = snakeLength - 1; i > 0; i--)
//		{
//			SNAKE[i] = SNAKE[i - 1];
//		}
//		SNAKE[0].y++;
//	}
//}
//
////  ####    ##   #    #   #### #####
////	#  #   #  #  #    #  #     #
////  ####  #    # #    #   #### #####
////  #     ###### #    #      # #
////  #     #    # #    # #    # #
//// ####   #    #  ####   ####  ######
//void PAUSE()
//{
//	GotoXY(chieudai + 3 + 3, 6);
//	cout << "  ####    ##   #    #   #### #####";
//	GotoXY(chieudai + 3 + 3, 7);
//	cout << "  #  #   #  #  #    #  #     #";
//	GotoXY(chieudai + 3 + 3, 8);
//	cout << "  ####  #    # #    #   #### #####";
//	GotoXY(chieudai + 3 + 3, 9);
//	cout << "  #     ###### #    #      # #";
//	GotoXY(chieudai + 3 + 3, 10);
//	cout << "  #     #    # #    # #    # #";
//	GotoXY(chieudai + 3 + 3, 11);
//	cout << " ####   #    #  ####   ####  ######";
//}
//
//void deleteHowToPlay()
//{
//	int x = chieudai + 4;
//	int y = 6;
//	while (y != chieurong)
//	{
//		while (x != chieudai + 43)
//		{
//			GotoXY(x, y);
//			cout << " ";
//			x++;
//		}
//		x = chieudai + 4;
//		y++;
//	}
//}
//bool options()
//{
//	int x = 0;
//	deleteHowToPlay();
//	PAUSE();
//	while (1)
//	{
//		Sleep(0.1);
//		GotoXY(chieudai + 3 + 15, 14);
//		cout << "resume";
//		GotoXY(chieudai + 3 + 15, 15);
//		cout << "save game";
//		GotoXY(chieudai + 3 + 15, 16);
//		cout << "show 5 high score";
//		GotoXY(chieudai + 3 + 15, 17);
//		cout << "exit";
//		if (x == 0)
//		{
//			GotoXY(chieudai + 3 + 15, 14);
//			SetTeColor(rand() % 14);
//			cout << "resume" << endl;
//			SetTeColor(0);
//		}
//		else if (x == 1)
//		{
//			GotoXY(chieudai + 3 + 15, 15);
//			SetTeColor(rand() % 14);
//			cout << "save game" << endl;
//			SetTeColor(0);
//		}
//		else if (x == 2)
//		{
//			GotoXY(chieudai + 3 + 15, 16);
//			SetTeColor(rand() % 14);
//			cout << "show 5 high score";
//			SetTeColor(0);
//		}
//		else if (x == 3)
//		{
//			GotoXY(chieudai + 3 + 15, 17);
//			SetTeColor(rand() % 14);
//			cout << "exit" << endl;
//			SetTeColor(0);
//		}
//		char temp;
//
//		if (_kbhit())
//		{
//			temp = _getch();
//			if ((temp == 13) && x == 0)
//			{
//				deleteHowToPlay();
//				howToPlay();
//				return true;
//			}
//			else if ((temp == 13) && x == 1)
//			{
//				Save();
//				deleteHowToPlay();
//				howToPlay();
//				return true;
//			}
//			else if ((temp == 13) && x == 2)
//			{
//				//show5HighScore();
//				deleteHowToPlay();
//				howToPlay();
//				return true;
//			}
//			else if ((temp == 13) && x == 3)
//			{
//				system("cls");
//				return false;
//			}
//			else if ((temp == 'W' || temp == 'w') && x != 0)
//			{
//				x--;
//			}
//			else if ((temp == 'S' || temp == 's') && x != 3)
//			{
//				x++;
//			}
//		}
//		Sleep(100);
//	}
//}
//
//struct HighScore
//{
//	int Score;
//	string name;
//};
//int nPeople;
//HighScore peopleHighScore[3];
//
//void LoadScore()
//{
//	ifstream fp;
//	fp.open("Show5HIghScore.txt");
//	fp >> nPeople;
//	for (int i = 0; i < nPeople; i++)
//	{
//		fp.ignore();
//		getline(fp, peopleHighScore[i].name);
//		fp >> peopleHighScore[i].Score;
//	}
//	fp.close();
//}
//void show5HighScore()
//{
//	system("cls");
//	LoadScore();
//	for (int i = 0; i < nPeople; i++)
//	{
//		cout << peopleHighScore[i].name << endl;
//		cout << peopleHighScore[i].Score << endl;
//	}
//	cin.get();
//}
//void saveScore()
//{
//	string name;
//	GotoXY(33, 18);
//	cout << "Hay nhap ten cua ban:";
//	cin >> name;
//	LoadScore();
//	for (int i = 0; i < nPeople; i++)
//	{
//		if (score * 10 > peopleHighScore[i].Score)
//		{
//			for (int j = nPeople - 1; j > i; j--)
//			{
//				peopleHighScore[j].name = peopleHighScore[j - 1].name;
//				peopleHighScore[j].Score = peopleHighScore[j - 1].Score;
//			}
//			peopleHighScore[i].name = name;
//			peopleHighScore[i].Score = score * 10;
//			break;
//		}
//		else if (score * 10 == peopleHighScore[i].Score && i != (nPeople - 1))
//		{
//			for (int j = nPeople - 1; j > i + 1; j--)
//			{
//				peopleHighScore[j].name = peopleHighScore[j - 1].name;
//				peopleHighScore[j].Score = peopleHighScore[j - 1].Score;
//			}
//			peopleHighScore[i + 1].name = name;
//			peopleHighScore[i + 1].Score = score * 10;
//			break;
//		}
//	}
//	ofstream fp;
//	fp.open("Show5HIghScore.txt");
//	fp << nPeople << endl;
//	for (int i = 0; i < nPeople; i++)
//	{
//		fp << peopleHighScore[i].name << endl;
//		fp << peopleHighScore[i].Score << endl;
//	}
//	fp.close();
//}
//
//void hieuUngChet()
//{
//	for (int i = 0; i < 3; i++)
//	{
//		Sleep(150);
//		for (int j = 0; j < snakeLength - 1; j++)
//			if (j % 3 == 0)
//			{
//				GotoXY(SNAKE[j].x + i, SNAKE[j].y);
//				cout << (char)001;
//				GotoXY(SNAKE[j].x - i, SNAKE[j].y);
//				cout << (char)001;
//				GotoXY(SNAKE[j].x, SNAKE[j].y + i);
//				cout << (char)001;
//				GotoXY(SNAKE[j].x, SNAKE[j].y - i);
//				cout << (char)001;
//				if (i == 2)
//				{
//					GotoXY(SNAKE[j].x - 1, SNAKE[j].y - 1);
//					cout << (char)001;
//					GotoXY(SNAKE[j].x + 1, SNAKE[j].y + 1);
//					cout << (char)001;
//					GotoXY(SNAKE[j].x + 1, SNAKE[j].y - 1);
//					cout << (char)001;
//					GotoXY(SNAKE[j].x - 1, SNAKE[j].y + 1);
//					cout << (char)001;
//				}
//			}
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		Sleep(150);
//		for (int j = 0; j < snakeLength - 1; j++)
//			if (j % 3 == 0)
//			{
//				GotoXY(SNAKE[j].x + i, SNAKE[j].y);
//				cout << " ";
//				GotoXY(SNAKE[j].x - i, SNAKE[j].y);
//				cout << " ";
//				GotoXY(SNAKE[j].x, SNAKE[j].y + i);
//				cout << " ";
//				GotoXY(SNAKE[j].x, SNAKE[j].y - i);
//				cout << " ";
//				if (i == 2)
//				{
//					GotoXY(SNAKE[j].x - 1, SNAKE[j].y - 1);
//					cout << " ";
//					GotoXY(SNAKE[j].x + 1, SNAKE[j].y + 1);
//					cout << " ";
//					GotoXY(SNAKE[j].x + 1, SNAKE[j].y - 1);
//					cout << " ";
//					GotoXY(SNAKE[j].x - 1, SNAKE[j].y + 1);
//					cout << " ";
//				}
//			}
//	}
//}
//void gameOver()
//{
//	//PlaySound(TEXT("chet1.wav"), NULL, SND_FILENAME | SND_ASYNC);
//	hieuUngChet();
//	xoaCong();
//	xoaCongOut();
//	system("cls");
//	for (int i = 0; i < 18; i++)
//	{
//		SetTeColor(rand() % 14);
//		GotoXY(33, 10);
//		cout << " ####    ##   #    # ######     ####  #    # ###### #####";
//		GotoXY(33, 11);
//		cout << "#    #  #  #  ##  ## #         #    # #    # #      #    #";
//		GotoXY(33, 12);
//		cout << "#      #    # # ## # #####     #    # #    # #####  #    #";
//		GotoXY(33, 13);
//		cout << "#  ### ###### #    # #         #    # #    # #      #####";
//		GotoXY(33, 14);
//		cout << "#  ### ###### #    # #         #    # #    # #      #####";
//		GotoXY(33, 15);
//		cout << " ####  #    # #    # ######     ####    ##   ###### #    #";
//		SetTeColor(0);
//		Sleep(40);
//	}
//	saveScore();
//	cout << "press enter to continue";
//	//cin.get();
//	_getch();
//	startgame();
//}
//void dead()
//{
//	if (SNAKE[0].x == 0 || SNAKE[0].y == 0 || SNAKE[0].x == chieudai || SNAKE[0].y == chieurong)
//	{
//		gameOver();
//	}
//	for (int i = 1; i < snakeLength - 1; i++)
//	{
//		if (SNAKE[0].x == SNAKE[i].x && SNAKE[0].y == SNAKE[i].y)
//		{
//			gameOver();
//		}
//	}if (idxFOOD == 5)
//	{
//		for (int i = 0; i < 7; i++)
//		{
//			if (i != 1)
//			{
//				if (SNAKE[0].x == cong[i].x && SNAKE[0].y == cong[i].y)
//				{
//
//					gameOver();
//				}
//			}
//			else
//			{
//				if (cong[5].y < cong[0].y)
//				{
//					if (SNAKE[0].x == cong[1].x && SNAKE[0].y == cong[1].y + 1 && SNAKE[0].y < SNAKE[1].y)
//						gameOver();
//				}
//				else if (cong[5].y > cong[0].y)
//					if (SNAKE[0].x == cong[1].x && SNAKE[0].y == cong[1].y - 1 && SNAKE[0].y > SNAKE[1].y)
//						gameOver();
//			}
//		}
//	}
//	for (int i = 0; i < 7; i++)
//		if (SNAKE[0].x == congOut[i].x && SNAKE[0].y == congOut[i].y)
//			gameOver();
//	for (int i = 0; i < 10; i++)
//		if (SNAKE[0].x == VATCAN[i].x && SNAKE[0].y == VATCAN[i].y)
//			gameOver();
//}
//
//void tangchieudairan()
//{
//	if (SNAKE[0].x == FOOD.x && SNAKE[0].y == FOOD.y)
//	{
//		cout << "\a";
//		//PlaySound(TEXT("soundanmoi.wav"), NULL, SND_FILENAME | SND_ASYNC);
//		taofood();
//		if (snakeLength == maxsnakelength)
//		{
//			xoaVat();
//			idxFOOD = 1;
//			xoaCong();
//			snakeLength = 6;
//			tt = UP;
//			taoCongRa();
//			taoVatCan();
//			
//		//	PlaySound(TEXT("soundquaman.wav"), NULL, SND_FILENAME | SND_ASYNC);
//			level++;
//		}
//		else
//		{
//			snakeLength++;
//			SNAKE[snakeLength - 1] = SNAKE[snakeLength - 2];
//		}
//		score++;
//		LevelAndScore();
//		howToPlay();
//	}
//	if (SNAKE[snakeLength - 1].x == congOut[1].x && SNAKE[snakeLength - 1].y == congOut[1].y - 3)
//		xoaCongOut();
//}
//void exitgame()
//{
//	GotoXY(30, 10);
//	cin.get();
//}
//
//void main()
//{
//	noCursorType();
//	FixConsoleWindow();
//	if (menu())
//		while (1)
//		{
//			if (_kbhit())
//			{
//				temp = _getch();
//				if ((temp == 'A' || temp == 'a') && tt != RIGHT)
//					tt = LEFT;
//				else if ((temp == 'D' || temp == 'd') && tt != LEFT)
//					tt = RIGHT;
//				else if ((temp == 'W' || temp == 'w') && tt != DOWN)
//					tt = UP;
//				else if ((temp == 'S' || temp == 's') && tt != UP)
//					tt = DOWN;
//				else if (temp == 27)
//				{
//					if (options() == false)
//						break;
//				}
//			}
//			taoran(' ');
//			dichuyen();
//			tangchieudairan();
//			dead();
//			SetTeColor(16);
//			taoran('x');
//			Sleep(100);
//		}
//	funny();
//	exitgame();
//}


#include<windows.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<fstream>
#include<mmsystem.h>
using namespace std;
enum trangthai { UP, DOWN, LEFT, RIGHT };

#define chieudai 70
#define chieurong 25
#define maxsnakelength 10
#define maxspeed 7

struct HighScore
{
	int Score;
	char name[50];
};
int nPeople;
HighScore peopleHighScore[3];

POINT FOOD;
POINT SNAKE[100], cong[7], congOut[7], MAP[200];
int SLVatCan;
int map;
char temp;
int snakeLength = 6;
int speed;
int score;
int level;
int idxFOOD = 0;
int k;
trangthai tt = RIGHT;
char mssv[] = "2012755020127466201272722012765720127614";
//fucntion window.h
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
void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void noCursorType()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = FALSE;
	info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

//draw
void LevelAndScore()
{
	//lv
	SetTColor(3);
	for (int i = 83; i <= 103; i++)
	{
		GotoXY(i, 2);
		cout << "*";
		GotoXY(i, 2);
		cout << "*";
	}
	for (int i = 3; i < 5; i++)
	{
		GotoXY(83, i);
		cout << "*";
		GotoXY(103, i);
		cout << "*";
	}
	for (int i = 83; i <= 103; i++)
	{
		GotoXY(i, 5);
		cout << "*";
		GotoXY(i, 5);
		cout << "*";
	}
	GotoXY(89, 3);
	SetTColor(4);
	cout << "Level : " << level;

	//score
	GotoXY(89, 4);
	SetTColor(4);
	cout << "score : " << score * 10;
}
void howToPlay()
{
	GotoXY(85, 8);
	cout << "How to play snake";
	GotoXY(83, 10);
	cout << "Options : Press Esc ";
	GotoXY(89, 11);
	cout << char(17) << " : Press A left";
	GotoXY(89, 12);
	cout << char(16) << " : Press D right";
	GotoXY(89, 13);
	cout << char(30) << " : Press W up";
	GotoXY(89, 14);
	cout << char(31) << " : Press S down";
}
void deleteHowToPlay()
{
	int x = chieudai + 4;
	int y = 6;
	while (y != chieurong)
	{
		while (x != chieudai + 43)
		{
			GotoXY(x, y);
			cout << " ";
			x++;
		}
		x = chieudai + 4;
		y++;
	}
}
void BYE()
{
	system("cls");
	SetTColor(rand() % 14);
	GotoXY(37, 8);
	cout << "##### #    #   ##   #    # #    #    #   #  ####  #    #\n";
	GotoXY(37, 9);
	cout << "  #   #    #  #  #  ##   # #   #      # #  #    # #    #\n";
	GotoXY(37, 10);
	cout << "  #   ###### #    # # #  # ####        #   #    # #    #\n";
	GotoXY(37, 11);
	cout << "  #   #    # ###### #  # # #  #        #   #    # #    #\n";
	GotoXY(37, 12);
	cout << "  #   #    # #    # #   ## #   #       #   #    # #    #\n";
	GotoXY(37, 13);
	cout << "  #   #    # #    # #    # #    #      #    ####   ####\n";
	GotoXY(37, 14);
	SetTColor(0);
	GotoXY(37, 15);
	cout << "    Press and key to close....";
}
void DrawBoard()
{
	GotoXY(0, 0);
	for (int i = 1; i <= chieudai + 1; i++)
		cout << char(220);
	for (int i = 1; i < chieurong; i++)
	{
		GotoXY(0, i);
		cout << char(219);
	}
	GotoXY(0, chieurong);
	for (int i = 0; i < chieudai + 1; i++)
	{
		cout << char(223);
	}
	for (int i = 1; i < chieurong; i++)
	{
		GotoXY(chieudai, i);
		cout << char(219);
	}

	GotoXY(chieudai + 3, 0);
	for (int i = 1; i <= 41; i++)
		cout << char(220);
	for (int i = 1; i < chieurong; i++)
	{
		GotoXY(chieudai + 3, i);
		cout << char(219);
	}
	GotoXY(chieudai + 3, chieurong);
	for (int i = 0; i < 41; i++)
	{
		cout << char(223);
	}
	for (int i = 1; i < chieurong; i++)
	{
		GotoXY(chieudai + 3 + 40, i);
		cout << char(219);
	}
}
void Title()
{
	GotoXY(40, 5);
	SetTColor(rand() % 14);
	//Sleep(700);
	cout << "   ####  #    #   ##   #    # ######" << endl;
	GotoXY(40, 6);
	cout << "  #      ##   #  #  #  #   #  #" << endl;
	GotoXY(40, 7);
	cout << "   ####  # #  # #    # ####   #####" << endl;
	GotoXY(40, 8);
	cout << "      #  #  # # ###### #  #   #" << endl;
	GotoXY(40, 9);
	cout << " #    #  #   ## #    # #   #  #" << endl;
	GotoXY(40, 10);
	cout << "  ####   #    # #    # #    # ######" << endl;
	SetTColor(0);
}
void aboutUs()
{
	system("cls");
	GotoXY(40, 8);
	cout << "20127466_Cao Nhat Duc\n";
	GotoXY(40, 9);
	cout << "20127614_Huynh Ngoc Son\n";
	GotoXY(40, 10);
	cout << "20127272_Tran Thinh Phat\n";
	GotoXY(40, 11);
	cout << "20127657_Nguyen Dang Manh Tu\n";
	GotoXY(40, 12);
	cout << "20127550_Doan Huu LOc\n";

}
void PAUSE()
{
	GotoXY(chieudai + 3 + 3, 6);
	cout << "  ####    ##   #    #   #### #####";
	GotoXY(chieudai + 3 + 3, 7);
	cout << "  #  #   #  #  #    #  #     #";
	GotoXY(chieudai + 3 + 3, 8);
	cout << "  ####  #    # #    #   #### #####";
	GotoXY(chieudai + 3 + 3, 9);
	cout << "  #     ###### #    #      # #";
	GotoXY(chieudai + 3 + 3, 10);
	cout << "  #     #    # #    # #    # #";
	GotoXY(chieudai + 3 + 3, 11);
	cout << " ####   #    #  ####   ####  ######";
}

//LoadSave
void LoadMap()
{
	ifstream fp;
	fp.open("map.txt");
	int count = 0;
	int temp;
	if (map == 0)
		return;
	while (1)
	{
		fp >> temp;
		if (temp == 0)
		{
			count++;
		}
		if (count == map)
			break;
	}
	fp >> SLVatCan;
	for (int i = 0; i < SLVatCan; i++)
	{
		fp >> MAP[i].x >> MAP[i].y;
	}
}
void SaveGame()
{
	ofstream fp;
	fp.open("SaveLoad.txt");
	if (tt == RIGHT)
		fp << "right" << endl;
	else if (tt == LEFT)
		fp << "left\n";
	else if (tt == UP)
		fp << "up\n";
	else if (tt == DOWN)
		fp << "down\n";
	fp << snakeLength << endl;
	fp << map << endl;
	fp << level << endl;
	fp << score << endl;
	fp << speed << endl;
	fp << idxFOOD << endl;
	fp << FOOD.x << " " << FOOD.y << endl;
	for (int i = 0; i < 7; i++)
	{
		fp << cong[i].x << " " << cong[i].y << endl;
	}
	for (int i = 0; i < snakeLength; i++)
	{
		fp << SNAKE[i].x << " " << SNAKE[i].y << endl;
	}
	fp.close();
	GotoXY(84, 18);
	cout << "Ban da save thanh cong" << endl;
	cin.get();

}
void LoadGame()
{
	ifstream fp;
	string x;
	fp.open("SaveLoad.txt");
	getline(fp, x);
	if (x == "right")
		tt = RIGHT;
	else if (x == "left")
		tt = LEFT;
	else if (x == "up")
		tt = UP;
	else if (x == "down")
		tt = DOWN;
	fp >> snakeLength;
	fp >> map;
	fp >> level;
	fp >> score;
	fp >> speed;
	fp >> idxFOOD;
	fp >> FOOD.x >> FOOD.y;
	for (int i = 0; i < 7; i++)
	{
		fp >> cong[i].x >> cong[i].y;
	}
	for (int i = 0; i < snakeLength; i++)
	{
		fp >> SNAKE[i].x >> SNAKE[i].y;
	}
	fp.close();
}
void LoadScore()
{
	ifstream fp;
	fp.open("Show5HIghScore.txt");
	fp >> nPeople;
	for (int i = 0; i < nPeople; i++)
	{
		fp.ignore();
		fp.getline(peopleHighScore[i].name, 50);
		fp >> peopleHighScore[i].Score;
	}
	fp.close();
}
void saveScore()
{
	char name[50];
	GotoXY(33, 18);
	cout << "Hay nhap ten cua ban:";
	cin.getline(name, 50);
	LoadScore();
	for (int i = 0; i < nPeople; i++)
	{
		if (score * 10 > peopleHighScore[i].Score)
		{
			for (int j = nPeople - 1; j > i; j--)
			{
				strcpy_s(peopleHighScore[j].name, peopleHighScore[j - 1].name);
				peopleHighScore[j].Score = peopleHighScore[j - 1].Score;
			}
			strcpy_s(peopleHighScore[i].name, name);
			peopleHighScore[i].Score = score * 10;
			break;
		}
		else if (score * 10 == peopleHighScore[i].Score && i != (nPeople - 1))
		{
			for (int j = nPeople - 1; j > i + 1; j--)
			{
				strcpy_s(peopleHighScore[j].name, peopleHighScore[j - 1].name);
				peopleHighScore[j].Score = peopleHighScore[j - 1].Score;
			}
			strcpy_s(peopleHighScore[i + 1].name, name);
			peopleHighScore[i + 1].Score = score * 10;
			break;
		}
	}
	ofstream fp;
	fp.open("Show5HIghScore.txt");
	fp << nPeople << endl;
	for (int i = 0; i < nPeople; i++)
	{
		fp << peopleHighScore[i].name << endl;
		fp << peopleHighScore[i].Score << endl;
	}
	fp.close();
}

bool isValid(POINT F)
{
	for (int i = 0; i < snakeLength; i++)
		if (SNAKE[i].x == F.x && SNAKE[i].y == F.y)
			return false;
	for (int i = 0; i < 7; i++)
		if (cong[i].x == F.x && cong[i].y == F.y)
			return false;
	for (int i = 0; i < SLVatCan; i++)
		if ((MAP[i].x == F.x && MAP[i].y == F.y) || (MAP[i].x + 1 == F.x && MAP[i].y == F.y) || (MAP[i].x - 1 == F.x && MAP[i].y == F.y))
			return false;
	return true;
}

//fucntion Generate
void GenerateSnake(char str)
{
	if (str == 'x')
	{
		for (int i = 0; i < snakeLength; i++)
		{
			GotoXY(SNAKE[i].x, SNAKE[i].y);
			cout << mssv[i];
		}
	}
	else
	{
		for (int i = 0; i < snakeLength; i++)
		{
			GotoXY(SNAKE[i].x, SNAKE[i].y);
			cout << str;
		}
	}
}
void GenerateMap()
{
	if (map == 0)
		return;
	else if (map == 1)
	{
		for (int i = 1; i < 18; i++)
		{
			GotoXY(17, i);
			cout << char(219);
		}
		for (int i = 21; i < 25; i++)
		{
			GotoXY(17, i);
			cout << char(219);
		}

		for (int i = 1; i < 5; i++)
		{
			GotoXY(35, i);
			cout << char(219);
		}
		for (int i = 8; i < 25; i++)
		{
			GotoXY(35, i);
			cout << char(219);
		}

		for (int i = 1; i < 18; i++)
		{
			GotoXY(53, i);
			cout << char(219);
		}
		for (int i = 21; i < 25; i++)
		{
			GotoXY(53, i);
			cout << char(219);
		}
	}
	else if (map == 2)
	{
		for (int i = 5; i < 21; i++)
		{
			GotoXY(10, i);
			cout << char(219);
		}
		for (int i = 5; i < 21; i++)
		{
			GotoXY(60, i);
			cout << char(219);
		}
		for (int i = 10; i <= 60; i++)
		{
			GotoXY(i, 20);
			cout << char(223);
		}

		for (int i = 8; i < 16; i++)
		{
			GotoXY(20, i);
			cout << char(219);
		}
		for (int i = 8; i < 16; i++)
		{
			GotoXY(50, i);
			cout << char(219);
		}
		for (int i = 20; i <= 50; i++)
		{
			GotoXY(i, 8);
			cout << char(220);
		}
	}
	else if (map == 3)
	{
		for (int i = 4; i < 14; i++)
		{
			GotoXY(i, 3);
			cout << char(223);
		}
		for (int i = 3; i < 8; i++)
		{
			GotoXY(4, i);
			cout << char(219);
		}
		for (int i = 14; i < 54; i++)
		{
			GotoXY(i, 12);
			cout << char(219);
		}
		for (int i = 4; i < 14; i++)
		{
			GotoXY(i, 22);
			cout << char(220);
		}
		for (int i = 18; i < 23; i++)
		{
			GotoXY(4, i);
			cout << char(219);
		}

		for (int i = 56; i < 66; i++)
		{
			GotoXY(i, 3);
			cout << char(223);
		}
		for (int i = 3; i < 8; i++)
		{
			GotoXY(66, i);
			cout << char(219);
		}

		for (int i = 56; i < 66; i++)
		{
			GotoXY(i, 22);
			cout << char(220);
		}
		for (int i = 18; i < 23; i++)
		{
			GotoXY(66, i);
			cout << char(219);
		}
	}
	else map = 1;
}
void DeleteMap()
{
	for (int i = 0; i < SLVatCan; i++)
	{
		GotoXY(MAP[i].x, MAP[i].y);
		cout << " ";
	}
}
void drawGate()
{
	for (int i = 0; i < 7; i++)
	{
		GotoXY(cong[i].x, cong[i].y);
		cout << (char)178;
	}
}
void taoCong()
{
	int idx = 0;
	do
	{
		FOOD.x = rand() % (chieudai - 3) + 2;
		FOOD.y = rand() % (chieurong - 9) + 5;
	} while (isValid(FOOD) == false);
	SetTColor(rand() % 14);
	int k = rand() % 2 - 1;
	for (int i = FOOD.x - 1; i <= FOOD.x + 1; i++)
	{
		cong[idx].x = i;
		cong[idx].y = FOOD.y;
		idx++;
		GotoXY(i, FOOD.y);
		cout << (char)178;
	}
	for (int i = 2 * k + FOOD.y + k + 1; i <= 2 * k + FOOD.y + 2 + k; i++)
	{
		cong[idx].x = FOOD.x - 1;
		cong[idx].y = i;
		idx++;
		GotoXY(FOOD.x - 1, i);
		cout << (char)178;
		cong[idx].x = FOOD.x + 1;
		cong[idx].y = i;
		idx++;
		GotoXY(FOOD.x + 1, i);
		cout << (char)178;
	}
}
void xoaCong()
{
	for (int i = 0; i < 7; i++)
	{
		GotoXY(cong[i].x, cong[i].y);
		cout << " ";
		cong[i].x = NULL;
		cong[i].y = NULL;
	}
}
void xoaCongOut()
{
	for (int i = 0; i < 7; i++)
	{
		GotoXY(congOut[i].x, congOut[i].y);
		cout << " ";
		congOut[i].x = NULL;
		congOut[i].y = NULL;
	}
}
void taoCongRa()
{
	POINT out;
	do
	{
		out.x = rand() % (chieudai - 3) + 2;
		out.y = rand() % (chieurong - 9) + 5;
	} while (isValid(out) == false);
	SetTColor(rand() % 14);
	int idx = 0;
	for (int i = out.x - 1; i <= out.x + 1; i++)
	{
		congOut[idx].x = i, congOut[idx].y = out.y;
		idx++;
		GotoXY(i, out.y);
		cout << (char)178;
	}
	for (int i = out.y - 2; i <= out.y - 1; i++)
	{
		congOut[idx].x = out.x - 1, congOut[idx].y = i;
		idx++;
		GotoXY(out.x - 1, i);
		cout << (char)178;
		congOut[idx].x = out.x + 1;
		congOut[idx].y = i;
		idx++;
		GotoXY(out.x + 1, i);
		cout << (char)178;
	}
	SNAKE[0] = { out.x,out.y - 1 };
}
void GenerateFood()
{
	srand(time(NULL));
	do
	{
		FOOD.x = rand() % (chieudai - 2) + 1;
		FOOD.y = rand() % (chieurong - 2) + 1;
	} while (isValid(FOOD) == false);
	idxFOOD++;
	if (idxFOOD == 5)
	{
		taoCong();
	}
	else
	{
		GotoXY(FOOD.x, FOOD.y);
		cout << "x";
	}
}

//some fucntion important
void resetdata()
{
	map = 0;
	idxFOOD = 0;
	speed = 0;
	score = 0;
	level = 1;
	tt = RIGHT;
	SNAKE[0] = { 26,10 };
	SNAKE[1] = { 25,10 };
	SNAKE[2] = { 24,10 };
	SNAKE[3] = { 23,10 };
	SNAKE[4] = { 22,10 };
	SNAKE[5] = { 21,10 };
	snakeLength = 6;
	xoaCong();
	xoaCongOut();
	GenerateFood();
}
void startgame()
{
	srand(time(NULL));
	system("cls");
	resetdata();
	SetTColor(rand() % 14);
	DrawBoard();
	LevelAndScore();
	howToPlay();
}
void startGameByLoad()
{
	srand(time(NULL));
	system("cls");
	SetTColor(rand() % 14);
	DrawBoard();
	LevelAndScore();
	howToPlay();
	LoadMap();
	GenerateMap();
	if (idxFOOD == 5)
	{
		drawGate();
	}
	else
	{
		GotoXY(FOOD.x, FOOD.y);
		cout << "x";
	}
}

void show3HighScore()
{
	srand(time(NULL));
	system("cls");
	LoadScore();
	SetTColor(rand() % 14);
	GotoXY(38, 6);
	cout << "Top 3 highscore";
	GotoXY(40, 7);
	cout << "Name";
	GotoXY(60, 7);
	cout << "Score";
	int j = 8;
	for (int i = 0; i < nPeople; i++)
	{
		SetTColor(rand() % 14);
		GotoXY(37, j);
		cout << i + 1;
		GotoXY(40, j);
		cout << peopleHighScore[i].name;
		GotoXY(60, j);
		cout << peopleHighScore[i].Score;
		j++;
	}
	cin.get();
}
void move()
{
	if (tt == RIGHT)
	{
		for (int i = snakeLength - 1; i > 0; i--)
		{
			SNAKE[i] = SNAKE[i - 1];
		}
		SNAKE[0].x++;
	}
	else if (tt == LEFT)
	{
		for (int i = snakeLength - 1; i > 0; i--)
		{
			SNAKE[i] = SNAKE[i - 1];
		}
		SNAKE[0].x--;
	}
	else if (tt == UP)
	{
		for (int i = snakeLength - 1; i > 0; i--)
		{
			SNAKE[i] = SNAKE[i - 1];
		}
		SNAKE[0].y--;
	}
	else if (tt == DOWN)
	{
		for (int i = snakeLength - 1; i > 0; i--)
		{
			SNAKE[i] = SNAKE[i - 1];
		}
		SNAKE[0].y++;
	}
}
bool menu()
{
	int x = 0;
	while (1)
	{

		Title();
		Sleep(0.1);
		GotoXY(55, 15);
		cout << "start game";
		GotoXY(55, 16);
		cout << "load game";
		GotoXY(55, 17);
		cout << "about us";
		GotoXY(55, 18);
		cout << "top 3 highscore";
		GotoXY(55, 19);
		cout << "exit";
		if (x == 0)
		{
			GotoXY(55, 15);
			SetTColor(rand() % 14);
			cout << "start game" << endl;
			SetTColor(0);
		}
		else if (x == 1)
		{
			GotoXY(55, 16);
			SetTColor(rand() % 14);
			cout << "load game" << endl;
			SetTColor(0);
		}
		else if (x == 2)
		{
			GotoXY(55, 17);
			SetTColor(rand() % 14);
			cout << "about us";
			SetTColor(0);
		}
		else if (x == 3)
		{
			GotoXY(55, 18);
			SetTColor(rand() % 14);
			cout << "top 3 highscore" << endl;
			SetTColor(0);
		}
		else if (x == 4)
		{
			GotoXY(55, 19);
			SetTColor(rand() % 14);
			cout << "exit" << endl;
			SetTColor(0);
		}
		char temp;

		if (_kbhit())
		{
			temp = _getch();
			if ((temp == 13) && x == 0)
			{
				startgame();
				return true;
			}
			else if ((temp == 13) && x == 1)
			{
				LoadGame();
				startGameByLoad();
				return true;
			}
			else if ((temp == 13) && x == 2)
			{
				aboutUs();
				temp = _getch();
				system("cls");
			}
			else if ((temp == 13) && x == 3)
			{
				show3HighScore();
				system("cls");
			}
			else if ((temp == 13) && x == 4)
			{
				return false;
			}
			else if ((temp == 'W' || temp == 'w') && x != 0)
			{
				x--;
			}
			else if ((temp == 'S' || temp == 's') && x != 4)
			{
				x++;
			}
		}
		Sleep(100);
	}
	return 0;
}
bool options()
{
	int x = 0;
	deleteHowToPlay();
	PAUSE();
	while (1)
	{
		Sleep(0.1);
		GotoXY(chieudai + 3 + 15, 14);
		cout << "resume";
		GotoXY(chieudai + 3 + 15, 15);
		cout << "save game";
		GotoXY(chieudai + 3 + 15, 16);
		cout << "load game";
		GotoXY(chieudai + 3 + 15, 17);
		cout << "exit";
		if (x == 0)
		{
			GotoXY(chieudai + 3 + 15, 14);
			SetTColor(rand() % 14);
			cout << "resume" << endl;
			SetTColor(0);
		}
		else if (x == 1)
		{
			GotoXY(chieudai + 3 + 15, 15);
			SetTColor(rand() % 14);
			cout << "save game" << endl;
			SetTColor(0);
		}
		else if (x == 2)
		{
			GotoXY(chieudai + 3 + 15, 16);
			SetTColor(rand() % 14);
			cout << "load game" << endl;
			SetTColor(0);
		}
		else if (x == 3)
		{
			GotoXY(chieudai + 3 + 15, 17);
			SetTColor(rand() % 14);
			cout << "exit" << endl;
			SetTColor(0);
		}
		char temp;

		if (_kbhit())
		{
			temp = _getch();
			if ((temp == 13) && x == 0)
			{
				deleteHowToPlay();
				howToPlay();
				return true;
			}
			else if ((temp == 13) && x == 1)
			{
				SaveGame();
				deleteHowToPlay();
				howToPlay();
				return true;
			}
			else if ((temp == 13) && x == 2)
			{
				LoadGame();
				startGameByLoad();
				return true;
			}
			else if ((temp == 13) && x == 3)
			{
				system("cls");
				return false;
			}
			else if ((temp == 'W' || temp == 'w') && x != 0)
			{
				x--;
			}
			else if ((temp == 'S' || temp == 's') && x != 3)
			{
				x++;
			}
		}
		Sleep(100);
	}
}
void EatFood()
{
	if (SNAKE[0].x == FOOD.x && SNAKE[0].y == FOOD.y)
	{
		//PlaySound(TEXT("soundanmoi.wav"), NULL, SND_FILENAME | SND_ASYNC);
		GenerateFood();
		if (snakeLength == maxsnakelength)
		{

			DeleteMap();
			map++;
			if (map > 3)
				map = 1;
			LoadMap();
			GenerateMap();
			idxFOOD = 1;
			snakeLength = 6;
			tt = UP;
			taoCongRa();
			//	PlaySound(TEXT("soundquaman.wav"), NULL, SND_FILENAME | SND_ASYNC);
			level++;
			if (speed != maxspeed)
				speed++;
		}
		else
		{
			snakeLength++;
			SNAKE[snakeLength - 1] = SNAKE[snakeLength - 2];
		}
		score++;
		LevelAndScore();
		howToPlay();
	}
	if (SNAKE[snakeLength - 1].x == congOut[1].x && SNAKE[snakeLength - 1].y == congOut[1].y - 3)
	{
		xoaCong();
		xoaCongOut();
		GenerateMap();
	}
}

//dead
void hieuUngChet()
{
	for (int i = 0; i < 3; i++)
	{
		Sleep(150);
		for (int j = 0; j < snakeLength - 1; j++)
			if (j % 3 == 0)
			{
				GotoXY(SNAKE[j].x + i, SNAKE[j].y);
				cout << (char)001;
				GotoXY(SNAKE[j].x - i, SNAKE[j].y);
				cout << (char)001;
				GotoXY(SNAKE[j].x, SNAKE[j].y + i);
				cout << (char)001;
				GotoXY(SNAKE[j].x, SNAKE[j].y - i);
				cout << (char)001;
				if (i == 2)
				{
					GotoXY(SNAKE[j].x - 1, SNAKE[j].y - 1);
					cout << (char)001;
					GotoXY(SNAKE[j].x + 1, SNAKE[j].y + 1);
					cout << (char)001;
					GotoXY(SNAKE[j].x + 1, SNAKE[j].y - 1);
					cout << (char)001;
					GotoXY(SNAKE[j].x - 1, SNAKE[j].y + 1);
					cout << (char)001;
				}
			}
	}
	for (int i = 0; i < 3; i++)
	{
		Sleep(150);
		for (int j = 0; j < snakeLength - 1; j++)
			if (j % 3 == 0)
			{
				GotoXY(SNAKE[j].x + i, SNAKE[j].y);
				cout << " ";
				GotoXY(SNAKE[j].x - i, SNAKE[j].y);
				cout << " ";
				GotoXY(SNAKE[j].x, SNAKE[j].y + i);
				cout << " ";
				GotoXY(SNAKE[j].x, SNAKE[j].y - i);
				cout << " ";
				if (i == 2)
				{
					GotoXY(SNAKE[j].x - 1, SNAKE[j].y - 1);
					cout << " ";
					GotoXY(SNAKE[j].x + 1, SNAKE[j].y + 1);
					cout << " ";
					GotoXY(SNAKE[j].x + 1, SNAKE[j].y - 1);
					cout << " ";
					GotoXY(SNAKE[j].x - 1, SNAKE[j].y + 1);
					cout << " ";
				}
			}
	}
}
void gameOver()
{
	//PlaySound(TEXT("chet1.wav"), NULL, SND_FILENAME | SND_ASYNC);
	hieuUngChet();
	for (int i = 0; i < SLVatCan; i++)
	{
		MAP[i].x = NULL;
		MAP[i].y = NULL;
	}
	xoaCong();
	xoaCongOut();
	system("cls");
	for (int i = 0; i < 18; i++)
	{
		SetTColor(rand() % 14);
		GotoXY(33, 10);
		cout << " ####    ##   #    # ######     ####  #    # ###### #####";
		GotoXY(33, 11);
		cout << "#    #  #  #  ##  ## #         #    # #    # #      #    #";
		GotoXY(33, 12);
		cout << "#      #    # # ## # #####     #    # #    # #####  #    #";
		GotoXY(33, 13);
		cout << "#  ### ###### #    # #         #    # #    # #      #####";
		GotoXY(33, 14);
		cout << "#  ### ###### #    # #         #    # #    # #      #####";
		GotoXY(33, 15);
		cout << " ####  #    # #    # ######     ####    ##   ###### #    #";
		SetTColor(0);
		Sleep(40);
	}
	saveScore();
	GotoXY(33, 19);
	cout << "press enter to continue";
	//cin.get();
	_getch();
	startgame();
}
bool dead()
{
	if (SNAKE[0].x == 0 || SNAKE[0].y == 0 || SNAKE[0].x == chieudai || SNAKE[0].y == chieurong)
	{
		gameOver();
		return true;
	}
	for (int i = 1; i < snakeLength - 1; i++)
	{
		if (SNAKE[0].x == SNAKE[i].x && SNAKE[0].y == SNAKE[i].y)
		{
			gameOver();
			return true;
		}
	}if (idxFOOD == 5)
	{
		for (int i = 0; i < 7; i++)
		{
			if (i != 1)
			{
				if (SNAKE[0].x == cong[i].x && SNAKE[0].y == cong[i].y)
				{

					gameOver();
					return true;
				}
			}
			else
			{
				if (cong[5].y < cong[0].y)
				{
					if (SNAKE[0].x == cong[1].x && SNAKE[0].y == cong[1].y + 1 && SNAKE[0].y < SNAKE[1].y)
					{
						gameOver();
						return true;
					}

				}
				else if (cong[5].y > cong[0].y)
					if (SNAKE[0].x == cong[1].x && SNAKE[0].y == cong[1].y - 1 && SNAKE[0].y > SNAKE[1].y)
					{
						gameOver();
						return true;
					}
			}
		}
	}
	for (int i = 0; i < 7; i++)
		if (SNAKE[0].x == congOut[i].x && SNAKE[0].y == congOut[i].y)
		{
			gameOver();
			return true;
		}
	for (int i = 0; i < SLVatCan; i++)
		if (SNAKE[0].x == MAP[i].x && SNAKE[0].y == MAP[i].y)
		{
			gameOver();
			return true;
		}
	return false;
}

void main()
{
	noCursorType();
	FixConsoleWindow();
	if (menu())
		while (1)
		{
			if (_kbhit())
			{
				temp = _getch();
				if ((temp == 'A' || temp == 'a') && tt != RIGHT)
					tt = LEFT;
				else if ((temp == 'D' || temp == 'd') && tt != LEFT)
					tt = RIGHT;
				else if ((temp == 'W' || temp == 'w') && tt != DOWN)
					tt = UP;
				else if ((temp == 'S' || temp == 's') && tt != UP)
					tt = DOWN;
				else if (temp == 27)
				{
					if (options() == false)
						break;
				}
			}
			GenerateSnake(' ');
			move();
			EatFood();
			if (dead())
			{
				system("cls");
				if (menu() == false)
					break;
			}
			SetTColor(16);
			GenerateSnake('x');
			Sleep(130 - speed * 8);
		}
	BYE();
	_getch();
}