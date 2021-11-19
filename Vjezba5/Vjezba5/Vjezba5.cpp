#include <iostream>
#include <vector>
#include "Point.h"
#include "Weapon.h"
#include "Target.h"

using std::cout;
using std::endl;

int main()
{
    srand(time(nullptr));
	
    Point point(2.6, 4.6, 3.3);
    Point point2(2.6, 1.6, 4.3);

    cout << "2D udaljenost: " << point.CalculateDistance2D(point2) << endl;
    cout << "3D udaljenost: " << point.CalculateDistance3D(point2) << endl;

	// 4. zad
    // generating a weapon
    Weapon weapon;
    weapon.SetPositionRandom(1, 5);
    weapon.Reload();
	
    // generating targets
    std::vector<Target> targets;
    targets.reserve(10);
    
	for (auto i = 0; i < 10; i++)
    {
        Target target;
        target.SetBottomLeftRandom(1, 5);
        target.SetTopRightRandom(1, 5);
        targets.emplace_back(target);
    }

    unsigned targetsHit = 0;

    for (auto& target : targets)
    {
        weapon.Shoot(target);
        targetsHit++;
    }

    cout << "Targets hit: " << targetsHit << endl;

}
