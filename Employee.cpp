#include "Employee.h"
#include <iostream>

using namespace std;

void Employee::getEmployee(){
    cout<<position<<": "<<emloyeeName<<" "<<surname<<"\nSalary: "<<salary;
}

Employee::Employee(string newEmployeeName) {
    emloyeeName = newEmployeeName;
}

Employee::Employee(string newEmployeeName, string newSurname) {
    emloyeeName = newEmployeeName;
    surname = newSurname;
}

Employee::Employee(string newEmployeeName, string newSurname, int newSalary) {
    emloyeeName = newEmployeeName;
    surname = newSurname;
    salary = newSalary;
}

Employee::Employee(string newEmployeeName,string newSurname, int newSalary, string newPosition) {
    emloyeeName = newEmployeeName;
    surname = newSurname;
    salary = newSalary;
    position = newPosition;
};

Employee::~Employee() {
}