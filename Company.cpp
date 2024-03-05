#include <iostream>
#include "Company.h"


void Company::getCompany() {
    cout<<"Name of company: "<<nameofCompany<<endl<<"Specialization: "<<specialization<<
        endl<<"Average salary: "<<avarageSalary;
}

Company::Company()
        :nameofCompany("Name_of_company"),avarageSalary{0},specialization("some_specialization"){}

Company::Company(string newName, double avSalary, string spec) {
    this->nameofCompany = newName;
    this->avarageSalary = avSalary;
    this->specialization = spec;
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

Company Company::operator=(const Company &rhs) {
    if(this==&rhs)
        return *this;
    else{
        this->avarageSalary = rhs.avarageSalary;
        this->nameofCompany = rhs.nameofCompany;
        this->specialization = rhs.specialization;
        return *this;
    }
}

Company::~Company() {}