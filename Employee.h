#ifndef PAYMENT_SYSTEM_EMPLOYEE_H
#define PAYMENT_SYSTEM_EMPLOYEE_H
#include "PersonalAccount.h"
#include <iostream>

using namespace std;

class Employee{
    static int counter;
    string emloyeeName;
    string surname;
    double salary;
    string position;
    PersonalAccount acc;

public:
    Employee();
    Employee(string newEmployeeName);
    Employee(string newEmployeeName, string newSurname);
    Employee(string newEmployeeName, string newSurname, double newSalary);
    Employee(string newEmployeeName, string newSurname, double newSalary,
             string newPosition, PersonalAccount Acc);
    ~Employee();
    Employee(const Employee &other);
    Employee(Employee && other);
    void getEmployee();
    friend ostream &operator<<( ostream &os, const Employee &obj);
    void operator++();
    void operator--();
    void ShowCounter();
    void getAccount();
    };

#endif //PAYMENT_SYSTEM_EMPLOYEE_H
