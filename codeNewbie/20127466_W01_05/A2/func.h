#ifndef func_h
#define func_h
struct cir
{
	float x, y, r;
};
void loadFile(cir A[100], int& n);
int area(cir A[100], int n);
void saveFile(float s);

#endif // !func_h
