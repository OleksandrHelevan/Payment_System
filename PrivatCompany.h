#ifndef PAYMENT_SYSTEM_PRIVATCOMPANY_H
#define PAYMENT_SYSTEM_PRIVATCOMPANY_H
#include "Company.h"
#include "CommercialAccount.h"

class PrivatCompany : public Company{
string ownerName;
string ownerSurname;

public:
    PrivatCompany();
    PrivatCompany(string newName, int avSalary, string spec,
                  string nameofOw, string surnameofOw, CommercialAccount Acc);
    ~PrivatCompany() override {};
    void getCompany() override;
    void CompareCompany(Company &thisComp, Company &other);
    void Example();//example
};


#endif //PAYMENT_SYSTEM_PRIVATCOMPANY_H
