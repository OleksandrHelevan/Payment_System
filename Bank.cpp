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

bool operator<(const Bank &lhs, const Bank &rhs){
    return lhs.tax<rhs.tax;
}

bool operator>(const Bank &lhs, const Bank &rhs){
    return lhs.tax>rhs.tax;
}

bool operator==(const Bank &lhs, const Bank &rhs){
    return lhs.tax==rhs.tax;
}

bool operator!=(const Bank &lhs, const Bank &rhs){
    return lhs.tax!=rhs.tax;
}


void Bank::getBank() {
    cout<<nameofBank<<"\n"<<"Tax: "<<tax<<"\n"<<"City: "<<city<<endl;
}

ostream &operator<<(ostream &os, const Bank &obj){
    os<<obj.nameofBank<<"\t"<<obj.tax<<"\t"<<obj.city;
    return os;
}
double operator%(const Bank &lhs, int  value){
    int tax1  =lhs.tax*10;
    return tax1 % value;
}
