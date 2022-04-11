#include "Medicine.h"
#include "Tablet.h"
#include "Injection.h"
#include "Potion.h"
#include <cassert>

unsigned Medicine::nextID = 0;

Medicine* Medicine::createMedicine(MedicineType mt)
{
	Medicine* m = nullptr;
	switch (mt) {
	case MedicineType::TABLET:
		m = new Tablet();
		break;
	case MedicineType::INJECTION:
		m = new Injection();
		break;
	case MedicineType::POTION:
		m = new Potion();
		break;
	default:
		assert(false);
	}
	return m;
}

Medicine::Medicine(string aManufacture, string aName, int aRelease, int aPrice) : ID(nextID++)
{
	setManufacture(aManufacture);
	setName(aName);
	setYearRelease(aRelease);
	setPrice(aPrice);
}
void Medicine::setManufacture(string aManufacture)
{
	manufacture = aManufacture;
}

void Medicine::setName(string aName)
{
	name = aName;
}

string Medicine::getManufacture() const
{
	return manufacture;
}

string Medicine::getName() const
{
	return name;
}

int Medicine::getYearRelease() const
{

	return yearRelease;
}

Medicine::Medicine(const Medicine& other) : ID(nextID++)
{
	clone(other);
}

void Medicine::operator=(const Medicine& other)
{
	clone(other);
}

Medicine::Medicine() : ID(nextID++)
{
	readFromConsole();
}

void Medicine::setYearRelease(int aRelease)
{
	if (aRelease < 2000 || aRelease > 2021)
		throw exception("setYearRelease: invalid release year!");
	yearRelease = aRelease;
}

void Medicine::setPrice(int aPrice)
{
	if (aPrice < 0)
		throw exception("setPrice: invalid medicine price");
	price = aPrice;
}

int Medicine::getPrice() const
{
	return price;
}

unsigned Medicine::getID() const
{
	return ID;
}

void Medicine::readFromConsole()
{
	int t;
	string s;
	cout << "Введите имя производителя: ";
	getline(cin, s);
	setManufacture(s);
	cout << "Введите название лекарства: ";
	getline(cin, s);
	setName(s);
	cout << "Введите год производства лекарства: ";
	while (true) {
		cin >> t;
		try {
			setYearRelease(t);
			break;
		}
		catch (...) {
			cout << "Вы ошиблись, повторите ввод!\n";
		}
	}
	cout << "Введите цену лекарства: ";
	while (true) {
		cin >> t;
		try {
			setPrice(t);
			break;
		}
		catch (...) {
			cout << "Вы ошиблись, повторите ввод!\n";
		}
	}
}

void Medicine::writeToStream(ostream& os)
{
	os << *this;
}


void Medicine::clone(const Medicine& other)
{
	name = other.name;
	manufacture = other.manufacture;
	yearRelease = other.yearRelease;
	price = other.price;
}

ostream& operator<<(ostream& os, const Medicine& b)
{
	os << "Medicine ID: " << b.ID << " Manufacture: " << b.manufacture << " Name: " << b.name <<
		" Realese year: " << b.yearRelease << " Price: " << b.price << "\n";
	return os;
}
