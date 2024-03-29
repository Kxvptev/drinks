#include "pch.h"
#pragma once
#include "Beer.h"
#include "Wine.h"
#include "Cognac.h"
#include "Milk.h"
#include "MineralWater.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	Beer* stout;
	Beer* weissbier;
	Beer* lager;

	AlcoholDrinks* sevensevenseven;

	Wine* sauvignon;

	Cognac* hennessyPI;

	Milk* goatMilk;

	MineralWater* borjomi;

	try
	{
		stout = new Beer("Ирландский стаут Murphy's", 1.0, 4.0, rawMaterial::BARLEY, beerColors::BLACK, fermentationTypes::UPPER);
		weissbier = new Beer("Schofferhofer Kristallweizen вайсбир", 0.33, 5.0, rawMaterial::WHEAT, beerColors::WHITE, fermentationTypes::UPPER);
		lager = new Beer;

		cout << *stout << "\n";
		cout << *weissbier << "\n";
		cout << *lager << "\n";

		sevensevenseven = new Wine("Портвейн 777", 1.0, 15.0, wineColors::BURGUNDY, "Россия", "Неопределённый", 2);

		sevensevenseven->print(cout);

		cout << "\n";

		sauvignon = new Wine("Chateau Lafite Rothschild Pauillac", 0.75, 13, wineColors::RED, "Франция", "Каберне Совиньон", 23);

		cout << *sauvignon << "\n";

		hennessyPI = new Cognac("HENNESSY PARADIS IMPERIAL", 0.7, 43.5, cognacClass::XO, "Фоль Бланш", "Коньяк, Франция");

		cout << *hennessyPI << "\n";

		goatMilk = new Milk("Козье молоко", 2.0, nonAlcDrinkType::COLD, milkSpecies::GOAT, 4.0);

		cout << *goatMilk << "\n";

		borjomi = new MineralWater("Боржоми", 0.7, nonAlcDrinkType::COLD, 7, minWatPurposes::MEDICALFEEDING);

		cout << *borjomi << "\n";

	}
	catch (exception& ex)
	{
		cerr << ex.what() << "\n";
		return 1;
	}

	delete stout;
	delete weissbier;
	delete lager;
	delete sauvignon;
	delete hennessyPI;
	delete goatMilk;
	delete borjomi;

	return 0;
}