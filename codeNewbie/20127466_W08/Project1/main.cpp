#include"function.h"
#include<iostream>
#include<fstream>
using namespace std;



int main()
{
	myList l;
	createList(l);
	loadFile(l);
	
	/*int x;
	cout << "\nhap node can xoa ";
	cin >> x;
		xoaNhieuNode(l, x);*/
	removeDup(l);
	cout << endl;
	
	saveFile(l);
	return 0;

}
