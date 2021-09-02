#include"function.h"
int main() 
{

	mylist l;
    initlist(l);
	inputflight(l);
	cout << endl;


	cout << "\n\n sum capacity in 2021: " << sumCapacity(l) << endl;

	cout << "\nprintf flight in 6:";
	printfIndex6( l,2);

	cout << "\nmax capacity is: " << findMaxCapacity(l);

	cout << "\nafter remover flght have capacity under 100 :" << endl << endl;
	removeUnder(l);
	printList(l);
	
	
	return 0;
}