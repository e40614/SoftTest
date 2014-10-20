#include <iostream>
#include <sstream>
#include <string>
#include "NextDate.h"

using namespace std;

bool Leap(int year)
{
	if( (year%400==0) || ( year%4==0&&year%100!=0 ) ) return true;
	else return false;
}

string DateToStr(int year, int month, int day) 
{
	string tomorrow="";
	stringstream temp;
	string buffer;
	temp << year;
	temp >> buffer;
	tomorrow+=buffer;
	temp.str("");
	temp.clear();
	tomorrow+="/";
	temp << month;
	temp >> buffer;
	tomorrow+=buffer;
	temp.str("");
	temp.clear();
	tomorrow+="/";
	temp << day;
	temp >> buffer;
	tomorrow+=buffer;
	return tomorrow;
}

string NextDate(int y, int m, int d) 
{
	string tomorrow = "";
	int year = y,month = m,day = d;
	if(y<1993 || y>2014 || m<1 || m>12 || d<1 || d>31) return tomorrow;
	switch(m)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			if(d < 31) day++;
			else if(d == 31) {
				day = 1;
				month++;
			
			}
			else return tomorrow;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(d < 30) day++;
			else if(d == 30) {
				day = 1;
				month++;
			}
			else return tomorrow;
			break;
		case 12:
			if(d < 31) day++;
			else if(d == 31){
				day = 1;
				month = 1;
				year++;
			
			}
			else return tomorrow;
			break;
		case 2:
			if(d < 28) day++;
			else if(d == 28) {
				if(Leap(y)) day = 29;
				else {
					day = 1;
					month = 3;
				}
			}
			else if(d == 29) {
				if(Leap(y)) {
					day = 1;
					month = 3;
				}
				else return tomorrow;
			}
			else return tomorrow;
			break;
	}
	
	tomorrow+=DateToStr(year, month, day);
	return tomorrow;
	
}
