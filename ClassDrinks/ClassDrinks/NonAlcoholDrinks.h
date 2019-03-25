#pragma once
#include "Drinks.h"

enum class nonAlcDrinkType {COLD, HOT};

static const char* types[] = { "холодный напиток", "горячий напиток" };
inline ostream& operator << (ostream& os, const nonAlcDrinkType& tp)
{
	os << types[(int)tp];
	return os;
}

class NonAlcoholDrinks : public Drinks
{
private:
	nonAlcDrinkType type;

public:
	NonAlcoholDrinks();

	nonAlcDrinkType getType() const;
	void setType(nonAlcDrinkType);

	virtual ~NonAlcoholDrinks();
};
