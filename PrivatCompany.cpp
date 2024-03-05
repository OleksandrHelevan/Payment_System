#include "PrivatCompany.h"
#include "CommercialAccount.h"
using namespace std;

PrivatCompany::PrivatCompany()
    :Company(),ownerName("Name_of_owner"),ownerSurname("Surname_of_owner"),
        acc(0,0,0, Bank("bank",0,"city")){}

    PrivatCompany::PrivatCompany(string newName, int avSalary,
                                 string spec, string nameofOw,string surnameofOw, CommercialAccount Acc)
                  : Company(newName,avSalary,spec), ownerName(nameofOw),ownerSurname(surnameofOw), acc(Acc){}