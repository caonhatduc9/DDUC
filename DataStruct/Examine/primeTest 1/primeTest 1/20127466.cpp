#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;
struct hour {
	string h, p;
};
struct flight {
	string tenHang, phiCong, diaDiem;
	hour gio;
};
struct NODE {
	flight key;
	NODE* pNext;
};
struct List {
	NODE* pHead;
	NODE* pTail;
};
NODE* createNode(flight data)
{
	NODE* q = new NODE;
	if (q == NULL)
		return NULL;
	q->key.tenHang = data.tenHang;
	q->key.phiCong = data.phiCong;
	q->key.diaDiem = data.diaDiem;
	q->key.gio = data.gio;
	q->pNext = NULL;
	return q;
}
void createList(List*& l)
{
	l = new List;
	l->pHead = l->pTail = NULL;
}
bool addTail(List*& l, flight data)
{
	NODE* q = createNode(data);
	if (q == NULL)
		return false;
	if (l->pHead == NULL)
	{
		l->pHead = l->pTail = q;
	}
	else {
		l->pTail->pNext = q;
		l->pTail = q;
	}
	return true;
}
flight readFlight(string infor) {
	flight f;
	stringstream doc(infor);
	getline(doc, f.tenHang, '|');
	getline(doc, f.phiCong, '|');
	getline(doc, f.diaDiem, '|');
	getline(doc, f.gio.h, ':');
	getline(doc, f.gio.p, ':');
	return f;
}
void readFlightList(string fileName, List* s1,List *s2)
{

	string infor;
	ifstream fin;
	fin.open(fileName);
	while (!fin.eof())
	{
		getline(fin, infor);
		flight f = readFlight(infor);
		if (f.tenHang == "ABC")
		addTail(s1, f);
		else
			addTail(s2, f);
	}
	fin.close();
}
void showInfor(List* s)
{
	for (NODE *i = s->pHead; i != NULL; i = i->pNext)
	{
		cout << i->key.phiCong << " - " << i->key.gio.h << ":" << i->key.gio.p << " - " << i->key.diaDiem << endl;
	}
}
int main()
{
	List *s1, *s2;
	createList(s1);
	createList(s2);
	readFlightList("flight.txt", s1, s2);
	cout << "Hang ABC:\n";
	showInfor(s1);
	cout << "\nHang XYZ:\n";
	showInfor(s2);
	return 0;
}