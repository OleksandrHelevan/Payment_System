#include "CommercialAccount.h"


CommercialAccount::CommercialAccount()
    :Account(),compTax{0}{}

CommercialAccount::CommercialAccount(int thenumber, double thebalance, double theTax, Bank thebank)
    :Account(thenumber,thebalance,thebank),compTax{theTax}{}

CommercialAccount::CommercialAccount(CommercialAccount &other)
    : Account(other),compTax{other.compTax}{}
