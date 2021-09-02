#include"function.h"
int main()
{
	stack s;
	int capacity;
	init(s, capacity);
	while (1)
	{
		cout << "\n1-show stack:";
		cout << "\n2-push stack:";
		cout << "\n3-pop stack:";
		cout << "\n4-size:";
		int choice;
		cout << "\n enter choice: ";
		cin >> choice;
		if (choice == 1)
		{
			printList(s);
		}
		else if (choice == 2)
		{
			cout << "\nenter element data:";
			int x;
			cin >> x;
			node* p = createNode(x);
			push(s, p);
		}
		else if (choice == 3)
		{
			int k = pop(s);
			if (k == 0)
				cout << "NULL";
			else
				cout << "\n pop element: " << k;
		}
		else if (choice == 4)
		{
			cout << sizeS(s);
		}
	}
	return 0;
}