#include <iostream>
#include "Employee.h"
#include "Company.h"
#include "Bank.h"
#include "Counter.h"
#include "Account.h"
#include "PersonalAccount.h"
#include "CommercialAccount.h"
#include "PrivatCompany.h"


int main() {
    Counter TheCounter;
Bank Mono ("Monobank", 0.1,"Kyiv");
CommercialAccount Marvel_Account(1,10000.0,0.1,Mono);
PrivatCompany Marvel ("Marvel",1000,
                      "movies","Tony","Stark",Marvel_Account);

PersonalAccount Spider_Account(1,1000.0,2500.0,Mono);
Employee Spider("Piter","Parker",5000,
                "hero",Spider_Account);


    return 0;
}
