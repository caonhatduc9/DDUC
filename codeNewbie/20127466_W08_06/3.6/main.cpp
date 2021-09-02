
#include"function.h"
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	myList l, l1;
	createList(l);
	loadFile(l);
	createList(l1);
	sumNode(l, l1);
	saveFile(l1);
	return 0;

}