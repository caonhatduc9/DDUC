#include <stdio.h>
int main()
{
	float phut, gio, giay, pace, speed, km;
	printf("nhap km,gio,phut,giay\n");
	scanf_s("%f%f%f%f", &km, &gio, &phut, &giay);
	phut = gio * 60 + phut + giay / 60 * 1.0;
	gio = phut / 60 * 1.0;
	pace = phut / km * 1.0;
	speed = km / gio * 1.0;
	printf("pace = %0.2f minute/km\n", pace);
	printf("speed = %0.2f km/h", speed);
	




}