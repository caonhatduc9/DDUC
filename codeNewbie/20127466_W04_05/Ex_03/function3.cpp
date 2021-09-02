#include"function3.h"
#include<string>
bool isPalindrome(char* cstr)
{
	char* front = cstr;
	char* back = cstr + strlen(cstr) - 1;
	while (front < back)
	{
		if (*front != *back)
			return false;
		++front;
		--back;
	}
	return true;
}
