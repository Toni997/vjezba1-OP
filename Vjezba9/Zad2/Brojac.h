#pragma once
#include <iostream>
#include <vector>

#include "Zivotinja.h"

class Brojac
{
public:
	Brojac() = default;
	Brojac(const std::vector<Zivotinja*>& zivotinje);
	

	void Dodaj(Zivotinja* zivotinja);
	int UkupanBrojNogu();
private:
	std::vector<Zivotinja*> m_zivotinje;
};

