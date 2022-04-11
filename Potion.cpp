#include "Potion.h"

Potion::Potion() : Medicine()
{
	readPotionFromConsole();
}

Potion::Potion(string aManufacture, string aName, int aRelease, int aPrice, int aAmount) :
	Medicine(aManufacture, aName, aRelease, aPrice)
{
	setAmount(aAmount);
}

void Potion::setAmount(int aAmount)
{
	if (aAmount <= 0)
		throw exception("setAmount: invalid amount!");
	amount = aAmount;
}

int Potion::getAmount() const
{
	return amount;
}

ostream& operator<<(ostream& os, const Potion& pb)
{
	os << (const Medicine&)pb << " Amount: " << pb.amount << "\n";
	return os;
}
void Potion::readFromConsole()
{
	Medicine::readFromConsole();
	readPotionFromConsole();
}

void Potion::writeToStream(ostream& os)
{
	os << *this;
}

void Potion::readPotionFromConsole()
{
	cin.ignore();
	string s;
	int t;
	cout << "Введите объём микстуры: ";
	while (true) {
		cin >> t;
		try {
			setAmount(t);
			cin.ignore();
			break;
		}
		catch (...) {
			cout << "Вы ошиблись, повторите ввод!\n";
		}
	}
}
