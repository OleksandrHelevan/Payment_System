#include <iostream>
#include "Employee.h"
#include "Company.h"
#include "Bank.h"


int main() {
    Employee Spider ("Peter", "Parker",
                     10000,"Spider");
    Spider.getEmployee();
    cout<<endl;
    system("pause");

    Company Marvel ("Marvel");
    Marvel.getCompany();
    cout<<endl;
    system("pause");

    Company DC (Marvel);
    DC.getCompany();
    cout<<endl;
    system("pause");

    Bank Mono ("Monobank");
    Mono.getBank();
    cout<<endl;
    Bank *NewMono (&Mono);
    NewMono->getBank();
    system("pause");




    return 0;
}
