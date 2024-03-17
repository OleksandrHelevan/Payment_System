#include <iostream>
#include "Account.h"
using namespace std;



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


void Account::getAccount(){
    cout<<"Account N"<<number<<"\t"<<"balance: "<<balance<<endl;
}

ostream &operator<<(ostream &os, const Account &obj){
    os<<"Account N"<<obj.number<<"\t"<<"balance: "<<obj.balance;
    return os;
}

void Account::getBank() {
    cout<<bank;
}