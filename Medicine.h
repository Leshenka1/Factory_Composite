#pragma once
#pragma once
#include <string>
#include <iostream>
using namespace std;

constexpr auto t1 = __LINE__;
enum MedicineType {
	TABLET = 1,
	INJECTION,
	POTION
};
constexpr auto n_types = __LINE__ - t1 - 3;
// string bookTypeNames[] = { "Paper", "Audio", "Electronic" };


class Medicine
{
public:
	virtual ~Medicine() {}
	Medicine(string aManufacture, string aName, int aRelease, int aPrice);
	Medicine(const Medicine& other);
	void operator = (const Medicine& other);
	Medicine();
	void setPrice(int aPrice);
	void setManufacture(string aManufacture);
	void setName(string aName);
	void setYearRelease(int aRelease);
	string getManufacture() const;
	string  getName() const;
	int getYearRelease() const;
	virtual int getPrice() const;
	unsigned getID() const;
	virtual void readFromConsole();
	virtual void writeToStream(ostream&);
	virtual void addMedicine(Medicine* b) {}   // Component
	virtual void removeMedicine(Medicine* b) {}   // Component
	static Medicine* createMedicine(MedicineType mt);

protected:
	unsigned ID;
	string manufacture;
	string name;
	int yearRelease;
	int price;
	void clone(const Medicine& other);
	virtual void dummy() = 0;   // для обеспечения абстрактности класса
	static unsigned nextID;  // для обеспечения уникальности ID

	friend ostream& operator << (ostream& os, const Medicine& b);

};
