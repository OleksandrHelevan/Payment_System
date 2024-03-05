#ifndef PAYMENT_SYSTEM_COMMERCIALACCOUNT_H
#define PAYMENT_SYSTEM_COMMERCIALACCOUNT_H
#include "Account.h"

class CommercialAccount: public Account{
double compTax;
public:
    CommercialAccount();
    CommercialAccount(int thenumber, double thebalance, double theTax, Bank thebank);
    CommercialAccount(CommercialAccount &other);
    ~CommercialAccount(){};
};


#endif //PAYMENT_SYSTEM_COMMERCIALACCOUNT_H
