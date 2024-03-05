#ifndef PAYMENT_SYSTEM_EMPLOYEE_H
#define PAYMENT_SYSTEM_EMPLOYEE_H
#include "PersonalAccount.h"
#include <iostream>

using namespace std;

class Employee {
    string emloyeeName;
    string surname;
    int salary;
    string position;
    PersonalAccount acc;

public:
    void getEmployee();
    int getSalary();
    Employee();
    Employee(string newEmployeeName);
    Employee(string newEmployeeName, string newSurname);
    Employee(string newEmployeeName, string newSurname, int newSalary);
    Employee(string newEmployeeName, string newSurname, int newSalary,
             string newPosition, PersonalAccount Acc);
    ~Employee();
    Employee(const Employee & other);
    friend ostream &operator<<( ostream &os, const Employee &obj);
    Employee(Employee && other);
    };

#endif //PAYMENT_SYSTEM_EMPLOYEE_H
