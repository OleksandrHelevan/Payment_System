#include "CommercialAccount.h"


CommercialAccount::CommercialAccount()
    :Account(),compTax{0}{}

CommercialAccount::CommercialAccount(int thenumber, double thebalance, double theTax, Bank thebank)
    :Account(thenumber,thebalance,thebank),compTax{theTax}{}

CommercialAccount::CommercialAccount(CommercialAccount &other)
    : Account(other),compTax{other.compTax}{}

void CommercialAccount::getAccount(){
    Account::getAccount();
    cout<<"Tax for this company: "<<compTax<<endl;
}
void CommercialAccount::getBank() {
    Account::getBank();
}

void CommercialAccount::sendMoney(double amount, int number) {
    Account::sendMoney(amount,number);
}

double CommercialAccount::getTax() {
    return compTax;
}

void CommercialAccount::addMoney(double amount, int number) {
    double totalamount = amount - amount*compTax;
    Account::addMoney(totalamount,number);
}

