#include "Math.h"
#include "Point.h"

double Point::getRandom(const double min, const double max) const
{
	const auto f = static_cast<double>(rand()) / RAND_MAX;
	return min + f * (max - min);
}

void Point::SetXYZRandom(const double min, const double max)
{
	double randomX = getRandom(min, max);
	double randomY = getRandom(min, max);
	double randomZ = getRandom(min, max);
	
	SetXYZ(randomX, randomY, randomZ);
}

double Point::CalculateDistance2D(const Point& other) const
{
	return sqrt((other._x - _x) * (other._x - _x) +
		(other._y - _y) * (other._y - _y));
}

double Point::CalculateDistance3D(const Point& other) const
{
	return sqrt((other._x - _x) * (other._x - _x) +
		(other._y - _y) * (other._y - _y) +
		(other._z - _z) * (other._z - _z));
}
