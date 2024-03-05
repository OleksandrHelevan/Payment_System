#include <iostream>
#include "Bank.h"
using namespace std;


Bank::Bank()
        :Bank{"Bank", 0 , "City"} {}

Bank::Bank(string name)
        :Bank{name, 0, "City"} {}

Bank::Bank(string name, double newTax)
        :Bank{name, newTax, "City"} {}

Bank::Bank(string name, double newTax, string newCity)
        :nameofBank{name}, tax{newTax}, city{newCity} {}



void Bank::getBank() {
    cout<<nameofBank<<"\n"<<"Tax: "<<tax<<"\n"<<"City: "<<city<<endl;
}

ostream &operator<<(ostream &os, const Bank &obj){
    os<<obj.nameofBank<<"\n"<<"Tax: "<<obj.tax<<"\n"<<"City: "<<obj.city<<endl;
    return os;
}

