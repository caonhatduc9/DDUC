//#include<iostream>
//using namespace std;
//struct node {
//	int data;
//	node* pnext;
//};
//struct list {
//	node* head;
//};
//void initList(list& l) {
//	l.head = NULL;
//}
//node* createNode(int x)
//{
//	node* q = new node;
//	q->data = x;
//	q->pnext = NULL;
//	return q;
//}
//void addHead(list &l, node* p)
//{
//	if (l.head == NULL)
//		l.head = p;
//	else
//	{
//		p->pnext = l.head;
//		l.head = p;
//	}
//
//}
//void showList(list l)
//{
//	for (node* i = l.head; i != NULL; i = i->pnext)
//	{
//		cout << i->data << " ";
//	}
//}
//int countCurrencences(list l, int num)
//{
//	int cnt = 0;
//	for (node* i = l.head; i!= NULL; i = i->pnext)
//	{
//		if (i->data == num)
//			cnt++;
//	}
//	return cnt;
//}
//bool isPermutation(list l, list l1)
//{
//	for (node* i = l.head; i!=NULL; i = i->pnext)
//	{
//		if (countCurrencences(l, i->data) != countCurrencences(l1, i->data))
//			return false;
//	}
//	return true;
//}
//int main()
//{
//	list l;
//	initList(l);
//	list l1;
//	initList(l1);
//	node* p;
//	p = createNode(2); addHead(l, p);
//	p = createNode(3); addHead(l, p);
//	p = createNode(3); addHead(l, p);
//	p = createNode(5); addHead(l, p);
//	p = createNode(1); addHead(l, p);
//	p = createNode(1); addHead(l1, p);
//	p = createNode(2); addHead(l1, p);
//	p = createNode(3); addHead(l1, p);
//	p = createNode(4); addHead(l1, p);
//	p = createNode(5); addHead(l1, p);
//	
//	showList( l);
//	cout <<"\n	count: "<<countCurrencences(l, 0);
//	if (isPermutation(l, l1))
//		cout << "\nyes";
//	else
//		cout << "\n no";
//	return 0;
//}
//#include<iostream>
//using namespace std;
//void swap(int& a, int& b)
//{
//	int k = a;
//	a = b; b = k;
//}
////int findmax(int a[], int n,  int x)
////{
////	int max = a[0], idx;
////		for (int i = 1; i < n; i++)
////		{
////			if (a[i] > max && a[i] != x)
////			{
////				max = a[i];
////				idx = i;
////			}
////		}
////}
//void sortarray(int a[], int n)
//{
//	int* b = new int[n];
//	for (int i = 0; i < n; i++)
//		b[i] = a[i];
//
//	for (int i = 0; i < n-1; i++) 
//	{
//		for (int j = i+1; j < n;j++)
//			if (b[i] > b[j])
//				swap(b[i], b[j]);
//	}
//	
//	int j = 0, k = n - 1;
//	for (int i= 0; i < n; i++)
//	{
//		if (i % 2 !=0) {
//			a[i] = b[j]; j++;
//		}
//		else
//		{
//			a[i] = b[k];
//			k--;
//		}
//	}
//
//	delete[]b;
//}
//void P(int a[], int n, int k, int m = 0)
//{
//	for (int i = m; i < n; i++)
//	{
//		swap(a[i], a[m]);
//		if (m == k)
//		{
//			for (int t = 0; t < k; t++)
//			{
//				cout << a[t] << " ";
//			}
//			cout << endl;
//		}
//		else
//			P(a, n, k, m+1);
//		swap(a[m], a[i]);
//	}
//}
//int main()
//{
//	int n = 4;
//	int a[] = { 50,60,70,20 };
//	sortarray(a, n);
//	/*for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		
//
//		cout << a[i] << " ";
//	}*/
//
//	P(a, n, 2, 0);
//	return 0;
//}


//

#include<iostream>

#include<fstream>
using namespace std;
struct staff {
	short id;
	char name[30];
	double sale;
};

void saveFile(const char* f, staff s[])
{
	ofstream fin;
	fin.open(f, ios::binary);

	if (!fin)
	{
		cout << "khong mo dc";
		return;
	}
	for (int i = 0; i < 2; i++)
	{
		staff s1 = s[i];
		fin.write((char*)&s1, sizeof(staff));
	}
	fin.close();
}
void loadfile(const char* f,staff s0[]){
	int size;
	ifstream fout;
	fout.open(f, ios::binary);
	fout.seekg(0, fout.end);
	size = fout.tellg ();
	fout.seekg(0);
	int n = size / sizeof(staff);
	
	for (int i = 0; i < n; i++)
	{
		staff a;
		fout.read((char*)&a, sizeof(staff));
		s0[i] = a;
	}
	fout.close();
}
int main()
{
	//cout << sizeof(staff);
	staff s[2], s0[2];
	cin >> s[0].id;
	cin.ignore();
	cin.getline(s[0].name, 30);
	cin >> s[0].sale;

	cin >> s[1].id;
	cin.ignore();
	cin.getline(s[1].name, 30);
	cin >> s[1].sale;
	for (int i = 0; i < 2; i++)
	{
		cout << s[i].id << endl;
		cout << s[i].name << endl;
		cout << s[i].sale << endl;
		cout << endl;
	}
	saveFile("staff.dat", s);

	loadfile("staff.dat", s0);
	for (int i = 0; i < 2; i++)
	{
		cout << s0[i].id << endl;
		cout << s0[i].name << endl;
		cout << s0[i].sale << endl;
		cout << endl;
	}
	cout << sizeof(s0);
	return 0;
}