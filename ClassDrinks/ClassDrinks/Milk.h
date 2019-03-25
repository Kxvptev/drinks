#pragma once
#include "NonAlcoholDrinks.h"

enum class milkSpecies { COW, MOOSE, GOAT, DEER, CAMEL, SHEEP };

static const char* spec[] = { "коровье", "лосиное", "козлиное", "оленье", "верблюжье", "овечье" };
inline ostream& operator << (ostream& os, const milkSpecies& sp)
{
	os << spec[(int)sp];
	return os;
}

class Milk : public NonAlcoholDrinks
{
private:
	milkSpecies species;
	float fatness;

public:
	Milk(const char*, double, nonAlcDrinkType, milkSpecies, float);

	void setSpecies(milkSpecies);
	void setFat(float);

	milkSpecies getSpecies() const;
	float getFat() const;

	friend ostream& operator << (ostream &, const Milk&);
	ostream& print(ostream&) const;
	
	virtual ~Milk();
};

