#ifndef PAYMENT_SYSTEM_COMMERCIALACCOUNT_H
#define PAYMENT_SYSTEM_COMMERCIALACCOUNT_H
#include "Account.h"

class CommercialAccount: public Account{
double compTax;
public:
    CommercialAccount();
    CommercialAccount(int thenumber, double thebalance, double theTax, Bank thebank);
    CommercialAccount(CommercialAccount &other);
    ~CommercialAccount() override {};
    void getAccount() override;
    void getBank() override;
    double getTax();
};


#endif //PAYMENT_SYSTEM_COMMERCIALACCOUNT_H
