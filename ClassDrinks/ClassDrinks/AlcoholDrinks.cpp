#include "pch.h"
#include "AlcoholDrinks.h"


AlcoholDrinks::AlcoholDrinks()
{
}

float AlcoholDrinks::getABV() const
{
	return abv;
}

void AlcoholDrinks::setABV(float alc)
{
	if (alc < 0 || alc > 100)
		throw exception("������ ������� ��������������� ������ � ��������� �� 0 �� 100 %.");
	abv = alc;
}


AlcoholDrinks::~AlcoholDrinks()
{
}
