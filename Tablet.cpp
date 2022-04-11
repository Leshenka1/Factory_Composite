#include "Tablet.h"

ostream& operator<<(ostream& os, const Tablet& ab)
{
	os << (const Medicine&)ab << " Tablet mass: " << ab.tabletMass << "\n";
	return os;
}

Tablet::Tablet() : Medicine()
{
	readTabletFromConsole();
}

Tablet::Tablet(string aManufacture, string aName, int aRelease, int aPrice, int aTabletMass) :
	Medicine(aManufacture, aName, aRelease, aPrice)
{
	setTabletMass(aTabletMass);
}

void Tablet::setTabletMass(int aTabletMass)
{
	if (aTabletMass <= 0)
		throw exception("setTabletMass: invalid mass!");
	tabletMass = aTabletMass;
}

int Tablet::getTabletMass() const
{
	return tabletMass;
}

void Tablet::readFromConsole()
{
	Medicine::readFromConsole();
	readTabletFromConsole();
}

void Tablet::writeToStream(ostream& os)
{
	os << (const Medicine&)*this << "Tablet weight : " << tabletMass << "\n";

}

void Tablet::readTabletFromConsole()
{
	cin.ignore();
	string s;
	int t;
	cout << "Введите массу таблетки (в милиграммах): ";
	while (true) {
		cin >> t;
		try {
			setTabletMass(t);
			cin.ignore();
			break;
		}
		catch (...) {
			cout << "Вы ошиблись, повторите ввод!\n";
		}
	}

}

