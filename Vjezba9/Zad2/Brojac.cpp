#include "Brojac.h"

Brojac::Brojac(const std::vector<Zivotinja*>& zivotinje)
{
	for (auto* zivotinja : zivotinje)
	{
		Dodaj(zivotinja);
	}
}

void Brojac::Dodaj(Zivotinja* zivotinja)
{
	if (zivotinja == nullptr) return;
	
	m_zivotinje.push_back(zivotinja);
	std::cout << "dodana: " << zivotinja->Vrsta() << std::endl;
}

int Brojac::UkupanBrojNogu()
{
	int ukupnoNogu = 0;
	for (auto* zivotinja : m_zivotinje)
	{
		ukupnoNogu += zivotinja->BrojNogu();
	}

	return ukupnoNogu;
}
