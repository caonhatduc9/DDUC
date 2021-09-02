#include <stdio.h>
#include<iostream>
using namespace std;
void XuatHe2(long n) {
    if (n <= 1)
        printf_s("%d", n);
    else {
        XuatHe2(n / 2);
        printf_s("%d", n % 2);
    }
}

int main() {
    long n;
    scanf_s("%ld", &n);
    XuatHe2(n);
    cout << 1;
    cout << 2;

}