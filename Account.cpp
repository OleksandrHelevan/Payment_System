#include <iostream>
#include "Account.h"
using namespace std;


Account::Account()
        :Account{ 0 , 0, Bank("Bank",0,"city")}{}

Account::Account(int newnumber)
        :Account{newnumber,0,Bank("Bank",0,"city")}{}

        Account::Account(int newnumber, double newbalance)
        :Account{newnumber,newbalance,Bank("Bank",0,"city")}{}

Account::Account(int newnumber, double newbalance, Bank thebank)
        :number{newnumber}, balance{newbalance}, bank(thebank) {}

Account &Account::operator=(const Account &rhs) {
    if (this != &rhs){
        this->balance = rhs.balance;
        this->number = rhs.number;
        this->bank = rhs.bank;
    } else return *this;
}
Account::Account(Account const &other) {
    this->number = other.number;
    this->balance = other.balance;
    this->bank = other.bank;
}

void Account::getAccount(){
    cout<<"Account N"<<number<<"\t"<<"balance: "<<balance<<endl;
}

ostream &operator<<(ostream &os, const Account &obj){
    os<<obj.number<<"\t"<<obj.balance;
    return os;
}

void Account::getBank() {
    cout<<bank;
}

void Account::takeMoney(double amount) {
    balance-=amount;
}

void Account::addMoney(double amount) {
    balance+=amount;
}

bool operator>(const Account &lhs, const Account &rhs){
    return lhs.balance>rhs.balance;
}
bool operator<(const Account &lhs, const Account &rhs){
    return lhs.balance>rhs.balance;
}
bool operator==(const Account &lhs, const Account &rhs){
    return lhs.balance==rhs.balance;
}
bool operator!=(const Account &lhs, const Account &rhs){
    return lhs.balance!=rhs.balance;
}