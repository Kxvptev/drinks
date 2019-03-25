#pragma once
#include <exception>
#include <string.h>
#include <iostream>

#pragma warning(disable : 4996)

using namespace std;

class Drinks
{
private:
	char* name;
	double packageVol;

public:
	void exceptString(const char* str)
	{
		if (str == 0)
			throw exception("Передан пустой указатель на строку!");
		if (str[0] == '\0')
			throw exception("Переданная строка не содержит символов!");
	}
	Drinks();

	double getVol() const;
	char* getName() const;

	void setName(const char*);
	void setVol(double);

	virtual ostream& print(ostream&) const;

	virtual ~Drinks();
};

