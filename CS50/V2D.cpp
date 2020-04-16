#include "V2D.h"

vec2D vec2D::operator+(const vec2D b)
{
	vec2D c;
	c.setx(this->x + b.x);
	c.sety(this->y + b.y);
	return c;
}

vec2D vec2D::operator-(const vec2D b)
{

	vec2D c;
	c.setx(this->x - b.x);
	c.sety(this->y - b.y);
	return c;
}

vec2D vec2D::operator*(const double a)
{
	x = x * a;
	y = y * a;
	return *this;
}

vec2D vec2D::operator/(const double a)
{
	x = x / a;
	y = y / a;
	return *this;
}
