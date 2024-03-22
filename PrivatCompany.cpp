#include "PrivatCompany.h"
#include "CommercialAccount.h"
using namespace std;

PrivatCompany::PrivatCompany()
    :Company(),ownerName("Name_of_owner"),ownerSurname("Surname_of_owner"){}

    PrivatCompany::PrivatCompany(string newName, double avSalary,
                                 string spec, string nameofOw,string surnameofOw, CommercialAccount Acc)
                  : Company(newName,avSalary,spec,Acc), ownerName(nameofOw),ownerSurname(surnameofOw){}


void PrivatCompany::getCompany(){
    Company::getCompany();
    cout<<"Owner: "<<ownerName<<" "<<ownerSurname<<endl;
}
void PrivatCompany::CompareCompany(Company &thisComp, Company &other) {
    thisComp.Company::CompareCompany(other);
}

string PrivatCompany::getOwnerN() {
    return ownerName;
}

string PrivatCompany::getOwnerS() {
    return ownerSurname;
}