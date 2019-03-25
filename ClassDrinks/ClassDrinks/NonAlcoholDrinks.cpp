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
		throw exception("��� ��������������� ������� ����� ���������� ������ ����� ����������: HOT � COLD");
	type = t;
}

NonAlcoholDrinks::~NonAlcoholDrinks()
{
}
