/* TEST CASE

test case 1
input: 1 2 2 4 2 6 0
output: 2 1 4 2 6 2 8 4 10 2 12 6 0

test case 2
input: 4 2 3 1 5 0
output: 2 4 4 2 6 3 8 1 10 5 0

test case 3
input: 1 0
output: 2 1 0

*/



#include"function.h"
int main()
{
	myList l;
	createList(l);
	loadFile(l);
	insertNode(l);
	saveFile(l);
	return 0;
}

