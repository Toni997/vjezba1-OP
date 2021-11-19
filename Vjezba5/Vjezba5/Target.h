#pragma once
#include "Point.h"
#include "Weapon.h"

class Target
{
	Point _bottomLeftPoint{};
	Point _topRightPoint{};
	bool _isHit{};

public:
	Target(const Point& bottomLeftPoint, const Point& topRightPoint) :
		_bottomLeftPoint(bottomLeftPoint), _topRightPoint(topRightPoint) {}

	Target() : _bottomLeft(0, 0, 0), _topRight(1, 1, 1) {}

	void SetBottomLeft(const Point& point) { _bottomLeftPoint = point; }
	void SetTopRight(const Point& point) { _topRightPoint = point; }
	
	void SetBottomLeftRandom(double min, double max) { _bottomLeftPoint.SetXYZRandom(min, max); }
	void SetTopRightRandom(double min, double max) { _topRightPoint.SetXYZRandom(min, max); }

	Point& GetBottomLeftPoint() const { return _bottomLeftPoint; }
	Point& GetTopRightPoint() const { return _topRightPoint; }

	bool GetIsHit() const { return _isHit; }
	void GotHit() { _isHit = true; }
};
