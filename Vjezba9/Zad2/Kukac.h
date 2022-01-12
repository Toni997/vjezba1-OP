#pragma once
#include "Zivotinja.h"

class Kukac : public Zivotinja

{
public:
	~Kukac() override;
	int BrojNogu() override;
	std::string Vrsta() override;
};

