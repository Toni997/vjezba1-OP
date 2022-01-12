#pragma once
#include "Zivotinja.h"

class Pauk : public Zivotinja
{
public:
	~Pauk() override;
	int BrojNogu() override;
	std::string Vrsta() override;
};

