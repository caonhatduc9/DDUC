/* TEST CASE

test case 1
input: 1
output: 3 2 2 3 4 5

test case 2
input: 2
output: 3 1 1 3 4 5

test case 3
input: 5
output: 3 1 1 2 2 3 4

*/

#include"function.h"
#include<iostream>
#include<fstream>
using namespace std;



int main()
{
	myList l;
	createList(l);
	loadFile(l);
	int x;
	cout << "\nhap node can xoa ";
	cin >> x;
	//xoaNhieuNode(l, x);
	xoaNode2(l, x);
	cout << endl;
	saveFile(l);
	return 0;

}
