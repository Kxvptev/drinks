#pragma once
#include "NonAlcoholDrinks.h"

enum class minWatPurposes { MEDICAL, MEDICALFEEDING, FEEDING };

static const char* prpses[] = { "лечебная", "лечебно-столовая", "столовая" };
inline ostream& operator << (ostream& os, const minWatPurposes& pr)
{
	os << prpses[(int)pr];
	return os;
}

class MineralWater : public NonAlcoholDrinks
{
private:
	int mineralization;
	minWatPurposes purpose;

public:
	MineralWater(const char*, double, nonAlcDrinkType, int, minWatPurposes);

	void setMineral(int);
	void setPurpose(minWatPurposes);

	int getMineral() const;
	minWatPurposes getPurpose() const;

	friend ostream& operator << (ostream &, const MineralWater&);
	ostream& print(ostream&) const;

	virtual ~MineralWater();
};

