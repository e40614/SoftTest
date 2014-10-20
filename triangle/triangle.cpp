#include "triangle.h"
//input range is 1~200
triangle_t triangle(int a, int b, int c) 
{
	if( a<1 || a>200 || b<1 || b>200 || c<1 || c>200 ) return Error;
	if( (a < b+c) && (b < a+c) && (c < a+b) ) {
		if( (a==b) && (b==c) ) return Equilateral;
		else if( (a!=b) && (a!=c) && (b!=c) ) return Scalene;
		else return Isosceles;
	}
	else return Error;
}
