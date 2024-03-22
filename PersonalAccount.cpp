
#include "PersonalAccount.h"
using namespace std;

PersonalAccount::PersonalAccount()
    :Account(),limit{0}{}

PersonalAccount::PersonalAccount(int thenumber, double thebalance, double thelimit,Bank thebank)
    : Account(thenumber,thebalance,thebank),limit{thelimit}{}

PersonalAccount::PersonalAccount(PersonalAccount &other)
    : Account(other), limit{other.limit}{}


void PersonalAccount::getAccount() {
    Account::getAccount();
    cout<<"Limit for this account: "<<limit;
}
void PersonalAccount::getBank() {
    Account::getBank();
}

void PersonalAccount::sendMoney(double amount, int number) {
    if(amount<=limit)
        Account::sendMoney(amount,number);
    else
        cerr<<"Not enough money";
}

double PersonalAccount::getLimit() {
    return limit;
}

void PersonalAccount::addMoney(double amount, int number) {
    Account::addMoney(amount,number);
}

