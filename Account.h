
#ifndef PAYMENT_SYSTEM_ACCOUNT_H
#define PAYMENT_SYSTEM_ACCOUNT_H
#include <iostream>
#include "Bank.h"
using namespace std;

class Account {
    int number;
    double balance;
    Bank bank;
public:
    Account();
    Account(int newnumber);
    Account(int newnumber, double newbalance, Bank thebank);
    Account(Account &other);
    virtual ~Account(){}
    virtual void getAccount() = 0;
    virtual void getBank() = 0;
    friend ostream &operator<<(ostream &os, const Account &obj);

};


#endif //PAYMENT_SYSTEM_ACCOUNT_H