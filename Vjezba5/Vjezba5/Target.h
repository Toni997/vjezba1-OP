#pragma once
#include "Point.h"

class Target
{
	Point _bottomLeftPoint{};
	Point _topRightPoint{};
	bool _isHit{};

public:
	Target(const Point& bottomLeftPoint, const Point& topRightPoint) :
		_bottomLeftPoint(bottomLeftPoint), _topRightPoint(topRightPoint) {}
	
	Point GetBottomLeftPoint() const { return _bottomLeftPoint; }
	Point GetTopRightPoint() const { return _topRightPoint; }
	bool GetIsHit() const { return _isHit; }
};
