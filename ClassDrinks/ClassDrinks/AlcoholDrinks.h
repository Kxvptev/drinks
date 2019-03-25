#pragma once
#include "Drinks.h"

class AlcoholDrinks : public Drinks
{
private:
	float abv;

public:
	AlcoholDrinks();

	float getABV() const;
	virtual void setABV(float);

	virtual ~AlcoholDrinks();
};

