#include"function.h"
int main()
{
	myList l;
	createList(l);
	//initBook(l);
	while (1)
	{
		cout << "0- exit\n";
		cout << "1 show book \n";
		cout << "2- input book\n";
		cout << "3- sell book\n";
		cout << "4- find a book\n";
		cout << "6- delete book\n";
		int choice;
		cout<<"\n\t\t enter: ";
		cin >> choice;
		if (choice == 0)
			break;
		else if (choice == 1)
			printList(l);
		else if (choice == 2)
		{
			book b = nhapDS();
			node* p = createNode(b);
			addTail(l, p);
		}
		else if (choice == 3)
			sellBook(l);
		else if (choice == 4)
			findBook(l);
		else if (choice == 5)
			removeLessThan(l);
	}
	return 0;
}