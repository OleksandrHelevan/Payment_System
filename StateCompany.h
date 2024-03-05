#ifndef PAYMENT_SYSTEM_STATECOMPANY_H
#define PAYMENT_SYSTEM_STATECOMPANY_H
#include "Company.h"

class StateCompany :public Company{
string state;
public:
    StateCompany();
    StateCompany(string newName, int avSalary, string spec, string theState);
    StateCompany operator=(const StateCompany &rhs);//example
    ~StateCompany(){};
};


#endif //PAYMENT_SYSTEM_STATECOMPANY_H
