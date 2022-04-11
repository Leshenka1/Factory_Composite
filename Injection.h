#pragma once
#include "Medicine.h"
constexpr auto START_LINE = __LINE__;
enum class Format {
    DRIP = 1,
    INTRAVEN,
    INTRAMUS,
};
constexpr auto FORMAT_COUNT = __LINE__ - START_LINE - 3;
const string FORMAT_NAMES[] = { "DRIP", "INTRAVEN", "INTRAMUS" };
const string MENU_STRING = "¬ыберите иньекции (1 - капельница, 2 - внутривенное, 3 - внутримышечное): ";

class Injection :
    public Medicine
{
public:
    Injection();
    Injection(string aManufacture, string aName, int aRelease, int aPrice, Format aFormat, int aAmount);
    void setFormat(Format aFormat);
    void setAmount(int aAmount);
    Format getFormat() const;
    int getAmount() const;
    void readFromConsole() override;
    void writeToStream(ostream&) override;
private:
    Format format;
    int amount;
    void readInjFromConsole();
    void dummy() {};  // убираем абстрактность

    friend ostream& operator << (ostream& os, const Injection& eb);
};