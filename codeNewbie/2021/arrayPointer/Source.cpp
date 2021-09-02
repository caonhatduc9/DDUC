#include<iostream>
using namespace std;
struct floatArray {
	int n;
	float* member;
};
void floatArrayInit(floatArray& a, int n) {
	a.n = n;
	a.member = new float[n];
}
void floatArrayInput(floatArray& a) {
	//cout << "nhap item";
	int m;
	cin >> m;
	if (m < 1)
		return;
	floatArrayInit(a, m);
	if (a.member != NULL)

		for (int i = 0; i < m; i++)
			cin >> a.member[i];
}
void floatArrayFree(floatArray& a) {
	if (a.member != NULL)
		delete[]a.member;
}
void floatArrayOutput(floatArray a)
{
	if (a.member == NULL)
		return;
	for (int i = 0; i < a.n; i++)
	{
		cout << a.member[i] << "\t";
	}
}
int main() {
	floatArray a;
	cout << "Number and element: ";
	floatArrayInput(a);
	cout << "out: \n";
	floatArrayOutput(a);
	floatArrayFree(a);
	return 0;
}