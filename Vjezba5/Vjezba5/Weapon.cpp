#include "Weapon.h"

void Weapon::Shoot(Target target) {
    if (_ammo < 1) return;
    
    _ammo--;
    if (_z >= target.GetBottomLeftPoint().GetZ() && _z <= target.GetTopRightPoint().GetZ())
		target.GotHit();
}