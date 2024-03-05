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
Employee::Employee(string newEmployeeName,string newSurname, int newSalary,
                   string newPosition,PersonalAccount Acc): emloyeeName(newEmployeeName),
                   surname(newSurname),salary(newSalary),position(newPosition),acc(Acc) {}


ostream &operator<<(ostream &os,const Employee &obj ){
    os<<obj.emloyeeName<<" "<<obj.surname<<endl<<
      "position: "<<obj.position<<"\t"<<"Salary: "<<obj.salary<<endl;
    return os;
}



Employee::~Employee() {
}