#include <iostream>
#include "Employee.h"
#include "Company.h"
#include "Bank.h"
#include "Account.h"
#include "PersonalAccount.h"
#include "CommercialAccount.h"
#include "PrivatCompany.h"
#include "StateCompany.h"
#include <memory>
#include <fstream>



int main() {
    cout<<"Welcome to the Banker!"<<endl<<endl;
    cout<<"Choose who you  are: "<<endl<<"Enter 1 if you are the Admin"
    <<endl<<"Enter 2 if you are the User"<<endl;
    int init;
    cin>>init;
    Bank Banker("Banker",0.1,"Chernivtsi");
    if(init == 1)   //for Admin
    {
        string password;
        cout<<"Enter the password"<<endl;
        cin>>password;
        if(password=="IPZ")
        {
            cout<<"Chose what do you want:"<<endl;
            cout<<"A - to make account"<<endl;
            cout<<"C - to add Company"<<endl;
            cout<<"E - to add Employee"<<endl;

        }
        else{
            cout<<"Sorry but you entered wrong password";
        }
    }

    else{   //for user
        cout<<"Hello user";
    }
    return 0;
}
