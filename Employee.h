#ifndef PAYMENT_SYSTEM_EMPLOYEE_H
#define PAYMENT_SYSTEM_EMPLOYEE_H

#include <iostream>

using namespace std;

class Employee {
    string emloyeeName;
    string surname;
    int salary;
    string position;
public:
    void getEmployee();
    int getSalary();
    Employee();
    Employee(string newEmployeeName);
    Employee(string newEmployeeName, string newSurname);
    Employee(string newEmployeeName, string newSurname, int newSalary);
    Employee(string newEmployeeName, string newSurname, int newSalary, string newPosition);
    ~Employee();
};
#endif //PAYMENT_SYSTEM_EMPLOYEE_H
