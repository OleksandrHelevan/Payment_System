#include <iostream>
#include "Employee.h"
#include "Company.h"
#include "Bank.h"
#include "Counter.h"
#include "Account.h"


int main() {
    Counter TheCounter;
    Employee Spider ("Peter", "Parker",
                     10000,"Spider");
    Spider.getEmployee();
    cout<<endl;
    system("pause");
    TheCounter.Calculate();

    Company Marvel ("Marvel");
    Marvel.getCompany();
    cout<<endl;
    system("pause");

    Bank Mono ("Monobank", 0.1);
    Mono.getBank();
    cout<<endl;
    system("pause");

    Employee Spider2 (Spider);
    Spider.getEmployee();
    cout<<endl;
    system("pause");
    TheCounter.Calculate();
    cout<<Spider2;

    cout<<"Counter calculate: "<<endl;
    TheCounter.ShowCounter();
    cout<<endl;
    system("pause");;

    Account SpiderAcc(1,1000);
    SpiderAcc.ShowAcc();
    Account *Spider2Acc(&SpiderAcc);
    Spider2Acc->ShowAcc();


    Company DC ("DC", 2500,"films");
    DC.CompareCompany(Marvel);




    return 0;
}
