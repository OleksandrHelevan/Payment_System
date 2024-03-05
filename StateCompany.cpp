#include "StateCompany.h"
using namespace std;


StateCompany::StateCompany():Company(),state("state") {}

StateCompany::StateCompany(string newName, int avSalary, string spec, string theState, CommercialAccount Acc)
    :Company(newName,avSalary,spec, Acc),state(theState){}

StateCompany StateCompany::operator=(const StateCompany &rhs) {
    if(this == &rhs)
        return *this;
    else{
        Company::operator=(rhs);
        this->state = rhs.state;
        return  *this;
    }
}