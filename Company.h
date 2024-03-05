#ifndef PAYMENT_SYSTEM_COMPANY_H
#define PAYMENT_SYSTEM_COMPANY_H
#include <iostream>
using namespace std;
class Company {
    string nameofCompany;
    double avarageSalary;
    string specialization;

public:
    void getCompany();
    bool operator>(const Company &rhs);
    void CompareCompany(const Company &rhs);
    Company();
    Company(string newName, double avSalary, string spec);
    Company operator=(const Company &rhs);//example
    ~Company();

};

#endif //PAYMENT_SYSTEM_COMPANY_H
