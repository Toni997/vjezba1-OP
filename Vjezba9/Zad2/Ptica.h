#pragma once
#include "Zivotinja.h"

class Ptica : public Zivotinja
{
public:
	~Ptica() override;
	int BrojNogu() override;
	std::string Vrsta() override;
};

