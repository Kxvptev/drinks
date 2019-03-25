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
		throw exception("������� ������������� �� ����� ���� ������������!");
	if (min > 15)
		throw exception("���� �� �������� ������������� ���� 15 �� �������� � ������������.");

	mineralization = min;
}

void MineralWater::setPurpose(minWatPurposes pr)
{
	if (pr < minWatPurposes::MEDICAL || pr > minWatPurposes::FEEDING)
		throw exception("���� purpose ����� ��������� ������: MEDICAL, MEDICALFEEDING, FEEDING.");

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
		throw exception("������� ������ ��������������� �������!");

	os << mw.getName() << ", " << mw.getType() << ", �����: " << mw.getVol()
		<< ", " << mw.getPurpose() << ", �������������: " << mw.getMineral();

	return os;
}

ostream& MineralWater::print(ostream& os) const
{
	return os << *this;
}

MineralWater::~MineralWater()
{
}
