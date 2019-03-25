#include "pch.h"
#include "Cognac.h"


Cognac::Cognac(const char* nm, double vol, float abv, cognacClass cl, const char* sp, const char* reg)
{
	setName(nm);
	setVol(vol);
	setABV(abv);
	setClass(cl);
	setSpecies(sp);
	setRegion(reg);
}

void Cognac::setClass(cognacClass cl)
{
	if (cl < cognacClass::ZEROZERO || cl > cognacClass::XO)
		throw exception("Для поля classCog допустимыми являются только значения: ZEROZERO, ZERO, ONE, VS, SUPERIOR, VSOP, VVSOP, XO.");

	classCog = cl;
}

void Cognac::setSpecies(const char* sp)
{
	exceptString(sp);

	wineSpecies = new char[strlen(sp) + 1];
	strcpy(wineSpecies, sp);
}

void Cognac::setRegion(const char* reg)
{
	exceptString(reg);

	region = new char[strlen(reg) + 1];
	strcpy(region, reg);
}

void Cognac::setABV(float alc)
{
	if (alc < 40 || alc > 50)
		throw exception("Градус коньяка варьируется в диапазоне от 40 до 50 %.");
	AlcoholDrinks::setABV(alc);
}

cognacClass Cognac::getClass() const
{
	return classCog;
}

char* Cognac::getSpecies() const
{
	return wineSpecies;
}

char* Cognac::getRegion() const
{
	return region;
}

ostream& operator << (ostream & os, const Cognac& cogn)
{
	if (&cogn == NULL)
		throw exception("Попытка вывода несуществующего объекта!");

	os << cogn.getName() << ", объём: " << cogn.getVol() << ", крепость: " << cogn.getABV()
		<< ", класс: " << cogn.getClass() << ", сорт винограда: " << cogn.getSpecies() << ", регион: "
		<< cogn.getRegion();

	return os;
}

ostream& Cognac::print(ostream& os) const
{
	return os << *this;
}

Cognac::~Cognac()
{
	delete wineSpecies;
	delete region;
}
