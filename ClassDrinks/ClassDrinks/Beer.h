#pragma once
#include "AlcoholDrinks.h"

enum class rawMaterial {BARLEY, WHEAT, RYE, RICE, MAIZE};
enum class beerColors {LIGHT, DARK, RED, WHITE, COPPER, BROWN, BLACK};
enum class fermentationTypes {LOWER, UPPER};

static const char* rawM[] = { "������", "�������", "����", "���", "��������" };
inline ostream& operator << (ostream& os, const rawMaterial& rm)
{
	os << rawM[(int)rm];
	return os;
}

static const char* colors[] = { "�������", "�����", "�������", "�����", "������", "����������", "������" };
inline ostream& operator << (ostream& os, const beerColors& clr)
{
	os << colors[(int)clr];
	return os;
}

static const char* fermTypes[] = { "������� ��������", "�������� ��������" };
inline ostream& operator << (ostream& os, const fermentationTypes& f)
{
	os << fermTypes[(int)f];
	return os;
}

class Beer : public AlcoholDrinks
{
private:
	rawMaterial material;
	beerColors color;
	fermentationTypes fermentation;

public:
	Beer();
	Beer(const char*, double, float, rawMaterial, beerColors, fermentationTypes);

	void setRawMat(rawMaterial);
	void setColor(beerColors);
	void setFermentation(fermentationTypes);
	virtual void setABV(float alc);

	rawMaterial getRawMat() const;
	beerColors getColor() const;
	fermentationTypes getFermentation() const;

	friend ostream& operator << (ostream&, const Beer&);
	ostream& print(ostream&) const;

	virtual ~Beer();
};

