

#ifndef PAYMENT_SYSTEM_ACCOUNT_H
#define PAYMENT_SYSTEM_ACCOUNT_H
#include <iostream>
using namespace std;

class Account {
    int *number;
    double *balance;
public:
    void ShowAcc();
    Account();
    Account(int newnumber);
    Account(int newnumber, double newbalance);
    Account(Account &&other);
    ~Account();
};


#endif //PAYMENT_SYSTEM_ACCOUNT_H
