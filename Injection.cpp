#include "Injection.h"
string toString(Format f) {
    return FORMAT_NAMES[(int)f - 1];
}

ostream& operator<<(ostream& os, const Injection& eb)
{
    os << (const Medicine&)eb << "Format: " << toString(eb.format) << " Injection amount: " << eb.amount << "\n";
    return os;
}

Injection::Injection() :Medicine()
{
    readInjFromConsole();
}

Injection::Injection(string aManufacture, string aName, int aRelease, int aPrice, Format aFormat, int aAmount) :
    Medicine( aManufacture,  aName,  aRelease,  aPrice)
{
    setFormat(aFormat);
    setAmount(aAmount);
}

void Injection::setFormat(Format aFormat)
{

    format = aFormat;
}

void Injection::setAmount(int aAmount)
{
    if (aAmount <= 0)
        throw exception("setAmount: invalid injection amount!");
    amount = aAmount;
}

Format Injection::getFormat() const
{
    return format;
}

int Injection::getAmount() const
{
    return amount;
}
void Injection::readFromConsole()
{
    Medicine::readFromConsole();
    readInjFromConsole();
}

void Injection::writeToStream(ostream& os)
{
    os << *this;
}

void Injection::readInjFromConsole()
{
    cin.ignore();
    Format inputFormat;
    int t;
    cout << "Выберите тип иньекции: (" + MENU_STRING + "): ";
    while (true) {
        cin >> t;
        if (!((t < 1) || (t > FORMAT_COUNT)))
            break;
        cout << "Вы ошиблись, повторите ввод!\n";
    }
    inputFormat = (Format)t;
    setFormat(inputFormat);
    cout << "введите объём иньекции в миллилитрах: ";
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
