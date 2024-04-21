
#include "PersonalAccount.h"
using namespace std;

PersonalAccount::PersonalAccount()
    :Account(),limit{0}{}

PersonalAccount::PersonalAccount(int thenumber, double thebalance, double thelimit,Bank thebank)
    : Account(thenumber,thebalance,thebank),limit{thelimit}{}

PersonalAccount::PersonalAccount(PersonalAccount const &other)
    : Account(other), limit{other.limit}{}

//PersonalAccount::PersonalAccount(PersonalAccount &&other)
//    : Account(other), limit{other.limit}{
//    other.limit = 0;
//}
PersonalAccount &PersonalAccount::operator=(const PersonalAccount &rhs) {
    if(this != &rhs)
        this->limit = rhs.limit;
    else
        return *this;
}

void PersonalAccount::getAccount() {
    Account::getAccount();
    cout<<"Limit for this account: "<<limit;
}
void PersonalAccount::getBank() {
    Account::getBank();
}

void PersonalAccount::takeMoney(double amount){
    if(amount<=limit)
        Account::takeMoney(amount);
    else
        cerr<<"Not enough money";
}

double PersonalAccount::getLimit() {
    return limit;
}

void PersonalAccount::addMoney(double amount) {
    Account::addMoney(amount);
}

