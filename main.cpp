#include <iostream>
#include "Employee.h"
#include "Company.h"
#include "Bank.h"
#include "Account.h"
#include "PersonalAccount.h"
#include "CommercialAccount.h"
#include "PrivatCompany.h"
#include "StateCompany.h"


int main() {
    Bank Mono("Mono",0.1,"Kyiv");
    CommercialAccount Marvel_Account(1,120000.0,0.15,Mono);
    Company *Marvel = new PrivatCompany("Marvel",1000,"movie",
                                        "Tony","Stark",Marvel_Account);
    Marvel->Example();
    cout<<endl;
    system("pause");
    Marvel->getCompany();
    system("pause");
    Marvel_Account.getAccount();
    system("pause");
    ;

PrivatCompany DC("DC",15000,"movie","Ivan",
                 "Mask",Marvel_Account);
Company Sony ("Sony",12000,"movie",Marvel_Account);
DC.CompareCompany(DC,Sony);
Sony.CompareCompany(DC);
    return 0;
}
