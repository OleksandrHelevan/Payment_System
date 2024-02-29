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

Company::~Company() {}
