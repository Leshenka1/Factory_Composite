#pragma once
#include "Medicine.h"
class Potion :
    public Medicine
{
public:
    Potion();
    Potion(string aManufacture, string aName, int aRelease, int aPrice, int aAmount);
    void setAmount(int aAmount);
    int getAmount() const;
    void readFromConsole() override;
    void writeToStream(ostream&) override;
private:
    int amount;
    void dummy() {};  // убираем абстрактность
    void readPotionFromConsole();

    friend ostream& operator << (ostream& os, const Potion& pb);
};
