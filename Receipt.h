#pragma once
#include "Medicine.h"
#include <vector>
using namespace std;

class Receipt //: public Medicine ������
{
public:
    string receiptDcName; 
    string receiptDate;
    Receipt(string aReceiptDcName, string aReceiptDate);
    int getPrice() const;
    void addMedicine(Medicine* b);
    void removeMedicine(Medicine* b);
    string  getReceiptDcName() const;
    string  getDate() const;
    ~Receipt();
private:
    virtual void dummy() {};   // ������� �������������
    vector <Medicine*> medicines;

};