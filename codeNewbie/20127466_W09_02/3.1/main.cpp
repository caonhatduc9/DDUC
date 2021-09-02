#include"function.h"
int main()
{
	Stack *s;
	int capacity = 10;
	initStack(s, capacity);
	while (1)
	{
		cout << "\n1-empty:";
		cout << "\n2-push stack:";
		cout << "\n3-pop stack:";
		cout << "\n4-size:";
		int choice;
		cout << "\n enter choice: ";
		cin >> choice;
		if (choice == 1)
		{
			empTy(s);
		}
		else if (choice == 2)
		{
			cout << "\nenter element data:";
			int x;
			cin >> x;
			push(s, x);
		}
		else if (choice == 3)
		{
			cout << Pop(s) << " ";
		}
		else if (choice == 4)
		{
			if (sizeStack(s) == -1)
				cout << "NULL";
			else
			cout << sizeStack(s);
		}
	}
	return 0;
}