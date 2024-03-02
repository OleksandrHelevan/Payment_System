#ifndef PAYMENT_SYSTEM_COMPANY_H
#define PAYMENT_SYSTEM_COMPANY_H

#include <iostream>
using namespace std;

class Company {
    string nameofCompany;
    int avarageSalary;
    string speciality;

public:
    void getCompany();
    bool operator>(const Company &rhs);
    void CompareCompany(const Company &rhs);
    Company();
    Company(string newName = "name_of_company", int avSalary = 1000,
            string spec = "spec");
    ~Company();

};



#endif //PAYMENT_SYSTEM_COMPANY_H
