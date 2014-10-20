#include <iostream>

using namespace std;

float Comission(int lock , int stock, int barrel) 
{
	if(lock < 1 || lock > 70 || stock < 1 || stock > 80 || barrel < 1 || barrel > 90) return -1;
	float comission = 0;
	float lockPrice = 45,stockPrice = 30,barrelPrice = 25;
	float sales = 0;
	sales = lock*lockPrice + stock*stockPrice + barrel*barrelPrice;
	if(sales > 1800) 
		comission = 0.1*1000 + 0.15*800 + 0.2*(sales-1800);
	else if(sales > 1000)
		comission = 0.1*1000 + 0.15*(sales-1000);
	else
		comission = 0.1*sales;
	return comission;
}
