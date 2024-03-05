#include "PrivatCompany.h"
#include "CommercialAccount.h"
using namespace std;

PrivatCompany::PrivatCompany()
    :Company(),ownerName("Name_of_owner"),ownerSurname("Surname_of_owner"){}

    PrivatCompany::PrivatCompany(string newName, int avSalary,
                                 string spec, string nameofOw,string surnameofOw, CommercialAccount Acc)
                  : Company(newName,avSalary,spec,Acc), ownerName(nameofOw),ownerSurname(surnameofOw){}