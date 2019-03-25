#include "pch.h"
#include "Wine.h"


Wine::Wine(const char* nm, double vol, float abv, wineColors clr, const char* country, const char* knd, int a)
{
	setName(nm);
	setVol(vol);
	setABV(abv);
	setColor(clr);
	setCountry(country);
	setKind(knd);
	setAge(a);
}

void Wine::setColor(wineColors clr)
{
	if (clr < wineColors::GRAY || clr > wineColors::BURGUNDY)
		throw exception("��� ���� color ����������� �������� ������ ��������: GRAY, ORANGE, RED, ROSE, TAWNY, WHITE, YELLOW, BURGUNDY.");
	color = clr;
}

void Wine::setCountry(const char* country)
{
	exceptString(country);

	countryOfOrigin = new char[strlen(country) + 1];
	strcpy(countryOfOrigin, country);
}

void Wine::setKind(const char* knd)
{
	exceptString(knd);

	kind = new char[strlen(knd) + 1];
	strcpy(kind, knd);
}

void Wine::setAge(int a)
{
	if (a < 0)
		throw exception("������� �� ����� ���� �������������!");
	if (a > 100)
		throw exception("����� ���� �� ����� ���������������� �������� ��� �� ����� ������������.");

	age = a;
}

void Wine::setABV(float alc)
{
	if (alc < 8|| alc > 20)
		throw exception("������ ���� ����������� � ��������� �� 8 �� 20 %.");
	AlcoholDrinks::setABV(alc);
}

wineColors Wine::getColor() const
{
	return color;
}

char* Wine::getCountry() const
{
	return countryOfOrigin;
}

char* Wine::getKind() const
{
	return kind;
}

int Wine::getAge() const
{
	return age;
}

ostream& operator << (ostream & os, const Wine& wine)
{
	if (&wine == NULL)
		throw exception("������� ������ ��������������� �������!");

	os << wine.getName() << ", �����: " << wine.getVol() << ", ��������: " << wine.getABV()
		<< ", ����: " << wine.getColor() << ", ������: " << wine.getCountry() << ", ����: "
		<< wine.getKind() << ", ������� (� �����): " << wine.getAge();

	return os;
}

ostream& Wine::print(ostream& os) const
{
	return os << *this;
}

Wine::~Wine()
{
	delete countryOfOrigin;
	delete kind;
}
