

#ifndef PAYMENT_SYSTEM_PERSONALACCOUNT_H
#define PAYMENT_SYSTEM_PERSONALACCOUNT_H
#include "Account.h"

class PersonalAccount :public Account{
double limit;
public:
    PersonalAccount();
    PersonalAccount(PersonalAccount const &other);
    //PersonalAccount(PersonalAccount &&other);
    PersonalAccount(int thenumber, double thebalance,double thelimit, Bank thebank);
    ~PersonalAccount() override {};
    PersonalAccount &operator=(const PersonalAccount &rhs);
    void getAccount() override;
    void getBank() override;
    double getLimit();
    void Sendmoney(double amount, Account &other);
    friend istream &operator>>(istream &is, PersonalAccount &obj);
    void takeMoney(double amount) override;
    void addMoney(double amount) override;
};


#endif //PAYMENT_SYSTEM_PERSONALACCOUNT_H
