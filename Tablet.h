#pragma once
#include "Medicine.h"
class Tablet :
    public Medicine
{
public:
    Tablet();
    Tablet(string aManufacture, string aName, int aRelease, int aPrice , int aTabletMass);
    void setTabletMass(int aTabletMass);
    int getTabletMass() const;
    void readFromConsole() override;
    void writeToStream(ostream&) override;
private:
    int tabletMass;
    void dummy() {};  // убираем абстрактность
    void readTabletFromConsole();
    friend ostream& operator << (ostream& os, const Tablet& ab);
};


