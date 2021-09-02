/* TEST CASE

test case 1
input: 15
output: 10 15 20 30 40 50 0

test case 2
input: 1
output: 1 10 20 30 40 50 0

test case 3
input: 90
output: 10 20 30 40 50 90 0

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
	cout << "enter node p: ";
	cin >> x;
	node* p = createNode(x);
	insertAscending(l, p);
	cout << "\n";
	saveFile(l);
	return 0;

}