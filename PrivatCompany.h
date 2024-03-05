#ifndef PAYMENT_SYSTEM_PRIVATCOMPANY_H
#define PAYMENT_SYSTEM_PRIVATCOMPANY_H
#include "Company.h"
#include "CommercialAccount.h"

class PrivatCompany : public Company{
string ownerName;
string ownerSurname;
CommercialAccount acc;

public:
    PrivatCompany();
    PrivatCompany(string newName, int avSalary, string spec,
                  string nameofOw, string surnameofOw, CommercialAccount Acc);
    ~PrivatCompany(){};
};


#endif //PAYMENT_SYSTEM_PRIVATCOMPANY_H
