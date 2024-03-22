#ifndef PAYMENT_SYSTEM_COMPANY_H
#define PAYMENT_SYSTEM_COMPANY_H
#include <iostream>
#include "CommercialAccount.h"
using namespace std;
class Company {
    string nameofCompany;
    double avarageSalary;
    string specialization;
    CommercialAccount acc;

public:
    Company();
    Company(string newName, double avSalary, string spec, CommercialAccount Acc);
    Company operator=(const Company &rhs);
    virtual ~Company(){};
    virtual void getCompany();
    friend ostream &operator<<(ostream &os, const Company &obj);
    bool operator>(const Company &rhs);
    void CompareCompany(const Company &rhs);
};

#endif //PAYMENT_SYSTEM_COMPANY_H
