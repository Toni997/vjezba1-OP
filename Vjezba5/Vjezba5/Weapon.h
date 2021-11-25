#pragma once
#include "Point.h"

class Weapon
{
	Point _position{};
	unsigned _capacity{};
	unsigned _ammo{};

public:
	Weapon(const Point& position, const unsigned capacity) :
		_position(position), _capacity(capacity) {}
	
	void Shoot();
	void Reload() {	_ammo = _capacity; }
	unsigned GetCapacity() { return _capacity; }
	Point& GetPosition() { return _position; }
	void SetPositionRandom() { _position.SetXYZRandom(1, 5); };
};
