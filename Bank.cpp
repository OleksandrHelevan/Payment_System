#include <iostream>
#include "Bank.h"
using namespace std;

void Bank::getBank(){
    cout <<"Name of Bank: "<< nameofBank << endl <<
         "Tax = "<< tax << endl <<"City: "<<city;
}

Bank::Bank()
        :Bank{"Bank", 0 , "City"} {}

Bank::Bank(string name)
        :Bank{name, 0, "City"} {}

Bank::Bank(string name, double newTax)
        :Bank{name, newTax, "City"} {}

Bank::Bank(string name, double newTax, string newCity)
        :nameofBank{name}, tax{newTax}, city{newCity} {}

Bank::~Bank() {}