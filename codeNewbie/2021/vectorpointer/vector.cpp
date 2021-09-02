#include<iostream>
#include<vector>
using namespace std;
void arrayInput(vector<float>& a)
{
	int n;
	cout << "nhap n  ";
	cin >> n;
	if (n < 1)
		return;
	a.resize(n);
	for (int i = 0; i < a.size(); i++)
		cin >> a[i];
}
void arrayInput2(vector <float>& a)
{
	float x;
	while (cin >> x)
	{	a.push_back(x);
}
	cin.clear();	
}

void arrayOutput(const vector <float>& a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
}
void intArrayCat(vector <float>& a, vector <float>& b)
{
	float s1 = a.size(), s2 = b.size();
	float idx = s1, s = s1 + s2, i = 0;
	a.resize(s);
	while (i < s2)
	{
		a[idx++] = b[i++];
	}
}
void intArrayCut(vector <float>& a, float pos, vector<float>& b)
{
	float s = a.size();
	float j = pos;
	b.resize(0);
	while (j < s)
	{
		b.push_back(a[j]);
		j++;
	}
	a.resize(pos);
}
void intArrayInsert(vector <float>& a, float pos, float e)
{
	if (pos < 0 || pos >= a.size())
		return;
	vector <float> b;
	intArrayCut(a, pos, b);
	a.push_back(e);
	intArrayCat(a, b);
}
void main()
{
	vector<float>a, b;
	//arrayInput(a);
	arrayInput(a);
	float pos;
	//cout << "pos ";
	//cin >> pos;
	//intArrayCut(a, pos, b);
	float  e;

	cout << "\n nhap pos ";
	cin >> pos;
	cout << "\n nhap tem ";
	cin >> e;
	intArrayInsert(a, pos, e);
	arrayOutput(a);
	
}