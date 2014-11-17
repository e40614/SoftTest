//#include <iostream>
//#include <sstream>
#include <string.h>
#include "NextDate.h"
#include <stdio.h>

extern char date[11];

bool Leap(int year)
{
	if( (year%400==0) || ( year%4==0&&year%100!=0 ) ) return true;
	else return false;
}

void DateToStr(int year, int month, int day) 
{
	char tmp[5];
	char* slash = "/";
	sprintf(tmp,"%d",year);
	strcat(date,tmp);
	strcat(date,slash);
	sprintf(tmp,"%d",month);
	strcat(date,tmp);
	strcat(date,slash);
	sprintf(tmp,"%d",day);
	strcat(date,tmp);
/*
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
*/
}

char* NextDate(int y, int m, int d) 
{	
	date[0] = '\0';
	int year = y,month = m,day = d;
	if(y<1993 || y>2014 || m<1 || m>12 || d<1 || d>31) return date;
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
			else return date;
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
			else return date;
			break;
		case 12:
			if(d < 31) day++;
			else if(d == 31){
				day = 1;
				month = 1;
				year++;
			
			}
			else return date;
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
				else return date;
			}
			else return date;
			break;
	}
	
	DateToStr(year, month, day);
	return date;
	
}
