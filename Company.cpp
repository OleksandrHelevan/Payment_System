#include <iostream>
#include "Company.h"

Company::Company()
        :nameofCompany("Name_of_company"),avarageSalary{0},specialization("some_specialization"){}

Company::Company(string newName, double avSalary, string spec, CommercialAccount Acc)
    :nameofCompany(newName),avarageSalary(avSalary),specialization(spec),acc(Acc) {}


ostream &operator<<(ostream &os, const Company &obj){
    os<<obj.nameofCompany;
    return os;
}

bool Company::operator>(const Company &rhs) {
    if (this->avarageSalary > rhs.avarageSalary) {
        return true;
    }
    return false;
}

void Company::CompareCompany(const Company &rhs) {
    if (this->operator>(rhs))
        cout<<this->nameofCompany<<" Company has higher salary: "<<this->avarageSalary<<
        " then "<<rhs.nameofCompany<<": "<<rhs.avarageSalary<<endl;
    else cout<<rhs.nameofCompany<<" Company has higher salary: "<<rhs.avarageSalary<<
             " then "<< this->nameofCompany<<": "<<this->avarageSalary<<endl;
}

Company Company::operator=(const Company &rhs) {
    if(this==&rhs)
        return *this;
    else{
        this->avarageSalary = rhs.avarageSalary;
        this->nameofCompany = rhs.nameofCompany;
        this->specialization = rhs.specialization;
        this->acc = rhs.acc;
        return *this;
    }
}

void Company::getCompany() {
    cout<<nameofCompany<<endl<<"Specialization: "<<specialization<<
        endl<<"Average salary: "<<avarageSalary<<endl;
}
void Company::getCompanyAccount() {
    cout<<acc;
}

void Company::Example(){
    cout<<"Base Company example method";//example
}
