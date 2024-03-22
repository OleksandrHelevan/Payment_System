#include "Employee.h"
#include <iostream>
using namespace std;


int Employee::counter=0;

Employee::Employee(string newEmployeeName) {
emloyeeName = newEmployeeName;
operator++();
}
Employee::Employee(string newEmployeeName, string newSurname) {
    emloyeeName = newEmployeeName;
    surname = newSurname;
    operator++();
}
Employee::Employee(string newEmployeeName, string newSurname, double newSalary) {
    emloyeeName = newEmployeeName;
    surname = newSurname;
    salary = newSalary;
    operator++();
}
Employee::Employee(string newEmployeeName,string newSurname, double newSalary,
                   string newPosition, PersonalAccount Acc): emloyeeName(newEmployeeName),
                   surname(newSurname),salary(newSalary),position(newPosition),acc(Acc) {operator++();}


Employee::~Employee() {
    operator--();
}


void Employee::getEmployee(){
    cout<<position<<": "<<emloyeeName<<" "<<surname<<"\nSalary: "<<salary;
}

ostream &operator<<(ostream &os,const Employee &obj ){
    os<<obj.emloyeeName<<" "<<obj.surname<<"\t"<<obj.salary<<"\t"<<obj.position<<endl;
    return os;
}

void Employee::operator++() {
    counter++;
}

void Employee::operator--() {
    counter--;
}

void Employee::ShowCounter() {
    cout<<counter<<" employees";
}
