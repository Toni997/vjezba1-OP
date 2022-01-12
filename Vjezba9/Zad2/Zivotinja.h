#pragma once
#include <string>

class Zivotinja
{
public:
	virtual ~Zivotinja() = 0;
	virtual int BrojNogu() = 0;
	virtual std::string Vrsta() = 0;
};

