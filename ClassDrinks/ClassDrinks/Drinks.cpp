#include "pch.h"
#include "Drinks.h"

Drinks::Drinks()
{
}

double Drinks::getVol() const
{
	return packageVol;
}

char* Drinks::getName() const
{
	return name;
}

void Drinks::setName(const char* nm)
{
	exceptString(nm);

	name = new char[strlen(nm) + 1];
	strcpy(name, nm);
}

void Drinks::setVol(double vol)
{
	if (vol < 0)
		throw exception("Объём не может быть отрицательным!");

	packageVol = vol;
}

ostream& Drinks::print(ostream& os) const
{
	os << getName() << ", объём: " << getVol();
	
	return os;
}

Drinks::~Drinks()
{
	delete[] name;
}
