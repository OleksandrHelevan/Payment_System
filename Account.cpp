

#include <iostream>
#include "Account.h"
using namespace std;



void Account::ShowAcc() {
    cout<<number<<" "<<balance<<endl;
}

Account::Account()
        :Account{ 0 , 0, Bank("Bank",0,"city")}{}

Account::Account(int newnumber)
        :Account{newnumber,0,Bank("Bank",0,"city")}{}

Account::Account(int newnumber, double newbalance, Bank thebank)
        :number{newnumber}, balance{newbalance}, bank(thebank) {}

Account::Account(Account &other) {
    this->number = other.number;
    this->balance = other.balance;
}

