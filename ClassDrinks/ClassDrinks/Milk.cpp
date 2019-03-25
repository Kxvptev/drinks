#include "pch.h"
#include "Milk.h"

Milk::Milk(const char* nm, double vol, nonAlcDrinkType tp, milkSpecies sp, float fat)
{
	setName(nm);
	setVol(vol);
	setType(tp);
	setSpecies(sp);
	setFat(fat);
}

void Milk::setSpecies(milkSpecies sp)
{
	if (sp < milkSpecies::COW || sp > milkSpecies::SHEEP)
		throw exception("Поле species может принимать только: COW, MOOSE, GOAT, DEER, CAMEL, SHEEP.");

	species = sp;
}

void Milk::setFat(float fat)
{
	if (fat < 0 || fat > 6)
		throw exception("Жирность молоко варьируется от 0 до 6 %.");

	fatness = fat;
}

milkSpecies Milk::getSpecies() const
{
	return species;
}

float Milk::getFat() const
{
	return fatness;
}

ostream& operator << (ostream & os, const Milk& mlk)
{
	if (&mlk == NULL)
		throw exception("Попытка вывода несуществующего объекта!");

	os << mlk.getName() << ", " << mlk.getType() << ", объём: " << mlk.getVol() << ", "
		<< mlk.getSpecies() << ", жирность: " << mlk.getFat() << "%";

	return os;
}

ostream& Milk::print(ostream& os) const
{
	return os << *this;
}

Milk::~Milk()
{
}
