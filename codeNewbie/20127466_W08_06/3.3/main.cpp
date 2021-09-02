/* TEST CASE

test case 1
input: 1 2 2 4 2 6 0
output: 6 2 4 2 2 1 0

test case 2
input: 1 1 1 1 0
output: 1 1 1 1 0

test case 3
input: 1 0
output: 1 0

*/

#include"function.h"

int main()
{
	myList l;
	createList(l);
	loadFile(l);
	reverseList(l);
	saveFile(l);
	return 0;
}