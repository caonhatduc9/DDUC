#include <iostream>
using namespace std;

void partition(int*& a, int n)
{

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            for (int j = n - 1; j >= i; j--)
            {
                if (a[j] % 2 == 0)
                {
                    swap(a[i], a[j]);
                    break;
                }
            }
        }
    }
}
int main()
{
    int* a = { new int[6]{6, 4, 6, 8, 2, 6} };
    partition(a, 6);
    for (int i = 0; i < 6; i++)
        cout << a[i] << " ";
    return 0;
}