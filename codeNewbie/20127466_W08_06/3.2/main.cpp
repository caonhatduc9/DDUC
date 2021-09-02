/* TEST CASE

test case 1
input:1 2 3 2 3 1 1 5 0
output: 1 2 3 5 0

test case 2
input: 1 1 1 1 1 2 0
output: 1 2 0

test case 3
input: 1 0
output: 1 0

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
	removeDump(l);
	cout << "\n";
	saveFile(l);
	return 0;

}
