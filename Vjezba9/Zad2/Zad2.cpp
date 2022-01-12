#include <iostream>



#include "Brojac.h"
#include "Tarantula.h"
#include "Vrabac.h"
#include "Zohar.h"

int main()
{
	Brojac brojac;
	Tarantula tarantula;
	Vrabac vrabac;
	Zohar zohar;
	brojac.Dodaj(&tarantula);
	brojac.Dodaj(&vrabac);
	brojac.Dodaj(&zohar);

	std::cout << "ukupno nogu: " << brojac.UkupanBrojNogu();
}
