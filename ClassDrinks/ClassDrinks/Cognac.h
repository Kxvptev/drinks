#pragma once
#include "AlcoholDrinks.h"

enum class cognacClass { ZEROZERO, ZERO, ONE, VS, SUPERIOR, VSOP, VVSOP, XO };

static const char* cogClass[] = { "00", "0", "1", "VS", "Superior", "VSOP", "VVSOP", "XO" };
inline ostream& operator << (ostream& os, const cognacClass& c)
{
	os << cogClass[(int)c];
	return os;
}

class Cognac : public AlcoholDrinks
{
private:
	cognacClass classCog;
	char* wineSpecies;
	char* region;
public:
	Cognac(const char*, double, float, cognacClass, const char*, const char*);

	void setClass(cognacClass);
	void setSpecies(const char*);
	void setRegion(const char*);
	virtual void setABV(float);

	cognacClass getClass() const;
	char* getSpecies() const;
	char* getRegion() const;

	friend ostream& operator << (ostream &, const Cognac&);
	ostream& print(ostream&) const;

	virtual ~Cognac();
};

