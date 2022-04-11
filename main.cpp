#include <iostream>
#include "windows.h"
#include "Medicine.h"
#include "Tablet.h"
#include "Injection.h"
#include "Potion.h"
#include "Receipt.h"
#include <vector>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<Medicine*> v;
	v.push_back(Medicine::createMedicine(TABLET));
	v.push_back(Medicine::createMedicine(INJECTION));
	v.push_back(Medicine::createMedicine(POTION));
	for (int i = 0; i < v.size(); i++)
	{
		cout << "ID " << v[i]->getName() << " : " << v[i]->getID() << "\n";
	}


	Receipt receipt("Tomas", "30.01.2021");
	receipt.addMedicine(v[0]);
	receipt.addMedicine(v[1]);

	cout << "Сумма лекарств в рецепте доктора "<< receipt.getReceiptDcName()<< " на дату "<<receipt.getDate() << " : " << receipt.getPrice() << endl;

	receipt.removeMedicine(v[0]);

	cout << "Сумма лекарств в рецепте доктора " << receipt.getReceiptDcName() << " на дату " << receipt.getDate() << " : " << receipt.getPrice() << endl;

	return 0;
}
