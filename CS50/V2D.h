#ifndef __V2D__
#define __V2D

#include<iostream>
#include<cmath>
using namespace std;

class vec2D
{
private:
	double x;
	double y;
public:
	vec2D()
	{
		x = 0; y = 0;
	}
	vec2D(double a, double b)
	{
		x = a;
		y = b;
	}
	double getx()
	{
		return x;
	}
	double gety()
	{
		return y;
	}
	void setx(double xx)
	{
		x = xx;
	}
	void sety(double yy)
	{
		y = yy;
	}
	double length()
	{
		return(sqrt(pow(x, 2) + pow(y, 2)));
	}
	vec2D operator+(const vec2D b);
	vec2D operator-(const vec2D b);
	vec2D operator*(const double a);
	vec2D operator/(const double a);
	void nomalize()
	{
		double l = this->length();
		if (l > 0)
		{
			*this = *this / l;
		}
	}
};

#endif // !__V2D__
