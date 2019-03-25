#pragma once
#include "AlcoholDrinks.h"

enum class wineColors { GRAY, ORANGE, RED, ROSE, TAWNY, WHITE, YELLOW, BURGUNDY };

static const char* wineClrs[] = { "серый", "оранжевый", "красный", "розовый", "тёмно-жёлтый", "белый", "жёлтый", "бордовый" };
inline ostream& operator << (ostream& os, const wineColors& clr)
{
	os << wineClrs[(int)clr];
	return os;
}

class Wine : public AlcoholDrinks
{
private:
	wineColors color;
	char* countryOfOrigin;
	char* kind;
	int age;

public:
	Wine(const char*, double, float, wineColors, const char*, const char*, int);

	void setColor(wineColors);
	void setCountry(const char*);
	void setKind(const char*);
	void setAge(int);
	virtual void setABV(float alc);

	wineColors getColor() const;
	char* getCountry() const;
	char* getKind() const;
	int getAge() const;
	
	friend ostream& operator << (ostream&, const Wine&);
	ostream& print(ostream&) const;

	virtual ~Wine();
};

