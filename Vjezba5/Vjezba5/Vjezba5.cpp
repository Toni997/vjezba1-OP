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
    Weapon weapon(point, 8);
    weapon.Reload();
	
    std::vector<Target> targets;
    targets.reserve(10);

	// generiraj mete i izracunaj koliko ih je pogodjeno sa oruzjen :)

}
