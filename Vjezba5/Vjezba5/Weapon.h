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
	
	void Shoot() { if(_ammo > 0) _ammo--; }
	void Reload() {	_ammo = _capacity; }
};
