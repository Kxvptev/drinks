#include "pch.h"
#include "NonAlcoholDrinks.h"


NonAlcoholDrinks::NonAlcoholDrinks()
{
}

nonAlcDrinkType NonAlcoholDrinks::getType() const
{
	return type;
}

void NonAlcoholDrinks::setType(nonAlcDrinkType t)
{
	if (t != nonAlcDrinkType::COLD && t != nonAlcDrinkType::HOT)
		throw exception("Тип безалкогольного напитка может задаваться только двумя значениями: HOT и COLD");
	type = t;
}

NonAlcoholDrinks::~NonAlcoholDrinks()
{
}
