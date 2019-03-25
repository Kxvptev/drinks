#include "pch.h"
#include "MineralWater.h"


MineralWater::MineralWater(const char* nm, double vol, nonAlcDrinkType tp, int min, minWatPurposes pr)
{
	setName(nm);
	setVol(vol);
	setType(tp);
	setMineral(min);
	setPurpose(pr);
}

void MineralWater::setMineral(int min)
{
	if (min < 0)
		throw exception("Степень минерализации не может быть отицательной!");
	if (min > 15)
		throw exception("Вода со степенью минерализации выше 15 не пригодна к употреблению.");

	mineralization = min;
}

void MineralWater::setPurpose(minWatPurposes pr)
{
	if (pr < minWatPurposes::MEDICAL || pr > minWatPurposes::FEEDING)
		throw exception("Поле purpose может принимать только: MEDICAL, MEDICALFEEDING, FEEDING.");

	purpose = pr;
}

int MineralWater::getMineral() const
{
	return mineralization;
}

minWatPurposes MineralWater::getPurpose() const
{
	return purpose;
}

ostream& operator << (ostream & os, const MineralWater& mw)
{
	if (&mw == NULL)
		throw exception("Попытка вывода несуществующего объекта!");

	os << mw.getName() << ", " << mw.getType() << ", объём: " << mw.getVol()
		<< ", " << mw.getPurpose() << ", минерализация: " << mw.getMineral();

	return os;
}

ostream& MineralWater::print(ostream& os) const
{
	return os << *this;
}

MineralWater::~MineralWater()
{
}
