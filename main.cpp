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

ifstream finA (R"(C:\Users\Admin\Desktop\Payment_System\Lists\AccountList.txt)");
ifstream finC (R"(C:\Users\Admin\Desktop\Payment_System\Lists\CompanyList.txt)");
ifstream finE (R"(C:\Users\Admin\Desktop\Payment_System\Lists2\EmployeeList.txt)");

ofstream foutA (R"(C:\Users\Admin\Desktop\Payment_System\Lists\AccountList.txt)",ios_base::app);
ofstream foutC (R"(C:\Users\Admin\Desktop\Payment_System\Lists\CompanyList.txt)",ios_base::app);
ofstream foutE (R"(C:\Users\Admin\Desktop\Payment_System\Lists2\EmployeeList.txt)",ios_base::app);


int main() {
    Bank Banker("Banker",0.1,"Chernivtsi");
    cout<<"Welcome to the Banker!"<<endl<<endl;
    cout<<"Choose who you are: "<<endl<<"Enter 1 if you are the Admin"
    <<endl<<"Enter 2 if you are the User"<<endl;
    int init;
    cin>>init;
    if(init == 1)   //for Admin
    {
        string password;
        cout<<"Enter the password"<<endl;
        cin>>password;
        if(password=="IPZ")
        {
            cout<<"Chose what do you want:"<<endl;
            cout<<"A - to create PERSONAL ACCOUNT"<<endl;
            cout<<"B - to create COMMERCIAL ACCOUNT"<<endl;
            cout<<"C - to add PRIVATE COMPANY"<<endl;
            cout<<"D - to add STATE COMPANY"<<endl;
            cout<<"E - to add EMPLOYEE"<<endl;
            char choice;
            cin>>choice;

            switch (choice) {

                case 'A': { //create personal account
                    cout << "You want to create personal account" << endl;
                    shared_ptr <int> num{new int {0}};
                    cout<<"Enter the number of your`s account"<<endl;
                    cin>>*num;
                    shared_ptr <double> bal {new double {0}};
                    shared_ptr <double> lim  {new double {10000}};
                    PersonalAccount Acc (*num,*bal,*lim,Banker);
                    foutA <<Acc<<"\t"<<"Limit:"<<Acc.getLimit()<<endl;
                    foutA.close();
                    cout<<Acc;
                    break;
                }
                case 'B':{  //create commercial account
                    cout << "You want to create commercial account" << endl;
                    shared_ptr <int> num{new int {0}};
                    cout<<"Enter the number of your`s account"<<endl;
                    cin>>*num;
                    shared_ptr <double> bal {new double {0}};
                    shared_ptr <double> tax  {new double {0.1}};
                    CommercialAccount Acc (*num,*bal,*tax,Banker);
                    foutA << Acc <<"\t"<<"tax: "<<Acc.getTax()<<endl;
                    foutA.close();
                    cout<<Acc;
                    break;
                }

                case 'C':{  //add private company
                        cout<<"You want to add private company"<<endl;

                    break;
                }

                case 'D':{  //add state company

                    break;
                }

                case 'E':{  //add employee

                    break;
                }
            }

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
