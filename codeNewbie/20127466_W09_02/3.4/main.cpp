#include"function.h"
int main()
{
	Queue q;
	int capacity = 10;
	initQueue(q, capacity);
	while (1)
	{
		cout << "\n1-empty:";
		cout << "\n2-enQueue:";
		cout << "\n3-deQueue:";
		cout << "\n4-size:";
		int choice;
		cout << "\n enter choice: ";
		cin >> choice;
		if (choice == 1)
		{
			empTy(q);
		}
		else if (choice == 2)
		{
			cout << "\nenter element data:";
			int x;
			cin >> x;
			enQueue(q, x);
		}
		else if (choice == 3)
		{
			cout << deQueue(q) << " ";
		}
		else if (choice == 4)
		{
			
				cout << sizeQueue(q);
		}
	}
	return 0;
}