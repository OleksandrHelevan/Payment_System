
#include "PersonalAccount.h"
using namespace std;

PersonalAccount::PersonalAccount()
    :Account(),limit{0}{}

PersonalAccount::PersonalAccount(int thenumber, double thebalance, double thelimit,Bank thebank)
    : Account(thenumber,thebalance,thebank),limit{thelimit}{}

PersonalAccount::PersonalAccount(PersonalAccount &other)
    : Account(other), limit{other.limit}{}



