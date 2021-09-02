#ifndef array_h
#define array_h
#include<iostream>
using namespace std;

void input(int a[], int &n);
void output(int a[], int n);
int kiemTraPrime(int a);
void hoanDoi(int &a, int &b);
void sapXepPrime(int a[], int n);
void gopMang(int a[], int n1, int b[], int n2, int c[], int &c3);
void sapXepMangGop(int c[], int n3);
void insertX(int a[], int &n);
void del(int a[], int &n, int k);
void delDup(int a[], int &n);
void tachMaxSangMangb(int a[], int n, int b[], int &n2);
#endif