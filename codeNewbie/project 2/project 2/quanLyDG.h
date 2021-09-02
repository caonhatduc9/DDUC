
#ifndef docgia_h
#define docgia_h


struct DG
{
	int maSoDG;
	char hoTenDG[70];
	char CMNDDG[10];
	char ngaySinhDG[15];
	int gioiTinhDG;
	char emailDG[100];
	char diaChiDG[300];
	int ngayLap;
	int thangLap;
	int namLap;
};

void nhapDG(DG& d);
void nhapDSDG(DG listDG[], int n1, int &n);
void saveFileDG(DG listDG[], int n);
void docFileDG(DG listDG[], int &n);
void xuatListDG(DG listDG[], int n);
void editDG(DG listDG[], int n);
void delDG(DG listDG[], int& n);
void searchCMND(DG listDG[], int n, char search[]);
void searchName(DG listDG[], int n, char search[]);
#endif