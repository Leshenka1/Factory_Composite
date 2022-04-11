#include "Receipt.h"

Receipt::Receipt(string aReceiptDcName, string aReceiptDate)
{
	receiptDcName = aReceiptDcName;
	receiptDate = aReceiptDate;
}

int Receipt::getPrice() const
{
	int price = 0;
	for (auto x : medicines)
		price += x->getPrice();
	return price;
}

void Receipt::addMedicine(Medicine* b)
{
	for (auto x : medicines) {
		if (x->getID() == b->getID())
			throw runtime_error("Duplicate of medicine in reciept!");
	}
	medicines.push_back(b);
}

void Receipt::removeMedicine(Medicine* b)
{
	for (auto x = medicines.begin(); x != medicines.end(); x++) {
		if ((*x)->getID() == b->getID())
			medicines.erase(x);
		return;
	}
	throw runtime_error("Missing medicine with such ID in receipt!");
}

string Receipt::getReceiptDcName() const
{
	return receiptDcName;
}

string Receipt::getDate() const
{
	return receiptDate;
}

Receipt::~Receipt() 
{
	for (int i = 0; i < medicines.size(); ++i)
		delete medicines[i];
}