
#include <iostream>
#include "Account.h"
using namespace std;



void Account::ShowAcc() {
    cout<<*number<<" "<<*balance<<endl;
}

Account::Account()
    :Account{ 0 , 0}{}

Account::Account(int newnumber)
    :Account{newnumber,0}{}

Account::Account(int newnumber, double newbalance)
    :number{&newnumber}, balance{&newbalance} {}


Account::~Account() {
    number = nullptr;
    balance = nullptr;
}
Account::Account(Account &&other)
    : number{other.number}, balance{other.balance}{
    number = nullptr;
    balance = nullptr;
}
