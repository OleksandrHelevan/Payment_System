

#ifndef PAYMENT_SYSTEM_PERSONALACCOUNT_H
#define PAYMENT_SYSTEM_PERSONALACCOUNT_H
#include "Account.h"

class PersonalAccount :public Account{
double limit;
public:
    PersonalAccount();
    PersonalAccount(PersonalAccount &other);
    PersonalAccount(int thenumber, double thebalance,double thelimit, Bank thebank);
    ~PersonalAccount(){};
};


#endif //PAYMENT_SYSTEM_PERSONALACCOUNT_H