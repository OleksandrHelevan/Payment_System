
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
    Account(int newnumber, double newbalance);
    Account(Account const &other);
    Account &operator=(const Account &rhs);
    virtual ~Account(){}
    virtual void getAccount() = 0;
    virtual void getBank() = 0;
    virtual void takeMoney(double amount);
    virtual void addMoney(double amount);
    friend ostream &operator<<(ostream &os, const Account &obj);
    friend bool operator>(const Account &lhs, const Account &rhs);
    friend bool operator<(const Account &lhs, const Account &rhs);
    friend bool operator==(const Account &lhs, const Account &rhs);
    friend bool operator!=(const Account &lhs, const Account &rhs);
};



#endif //PAYMENT_SYSTEM_ACCOUNT_H