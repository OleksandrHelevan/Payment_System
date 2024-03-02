#include <iostream>
#include "Company.h"


void Company::getCompany() {
    cout<<"Name of company: "<<nameofCompany<<endl<<"Specialization: "<<speciality<<
        endl<<"Average salary: "<<avarageSalary;
}


Company::Company(string newName, int avSalary, string spec) {
    this->nameofCompany = newName;
    this->avarageSalary = avSalary;
    this->speciality = spec;
}

bool Company::operator>(const Company &rhs) {
    if (this->avarageSalary > rhs.avarageSalary) {
        return true;
    }
    return false;
}

void Company::CompareCompany(const Company &rhs) {
    if (this->operator>(rhs))
        cout<< this->nameofCompany<<"\t"<<this->avarageSalary<<endl;
    else cout<<rhs.nameofCompany<<"\t"<<rhs.avarageSalary<<endl;
}


Company::~Company() {}
