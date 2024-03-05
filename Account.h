
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
    void ShowAcc();
    Account();
    Account(int newnumber);
    Account(int newnumber, double newbalance, Bank thebank);
    Account(Account &other);
    ~Account(){};
};


#endif //PAYMENT_SYSTEM_ACCOUNT_H