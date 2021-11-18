#pragma once
#include <iostream>

using std::cout;
using std::endl;

class Point
{
	double _x{}, _y{}, _z{};
	double getRandom(double min, double max) const;

public:
	Point(double x = 0, double y = 0, double z = 0) :
		_x(x), _y(y), _z(z) {}
	
	void SetXYZ(double x = 0, double y = 0, double z = 0) { _x = x; _y = y, _z = z; }
	void SetXYZRandom(double min, double max);
	
	void SetX(double x = 0) { _x = x; }
	void SetY(double y = 0) { _y = y; }
	void SetZ(double z = 0) { _z = z; }

	double GetX() const { return _x; }
	double GetY() const { return _y; }
	double GetZ() const { return _z; }
	
	double CalculateDistance2D(const Point& other) const;
	double CalculateDistance3D(const Point& other) const;
};
