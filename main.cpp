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
#include <vector>

ifstream finA (R"(C:\Users\Admin\Desktop\Payment_System\Lists\AccountList.txt)");
ifstream finC (R"(C:\Users\Admin\Desktop\Payment_System\Lists\CompanyList.txt)");
ifstream finE (R"(C:\Users\Admin\Desktop\Payment_System\Lists2\EmployeeList.txt)");

void AddPrivateCompany(Bank &bank){
    cout<<"You want to add private company"<<endl<<endl;
    cout << "You must to create commercial account" << endl;
    shared_ptr <int> num{new int {0}};
    cout<<"Enter the number of your`s account"<<endl;
    cin>>*num;
    shared_ptr <double> bal {new double {0}};
    shared_ptr <double> tax  {new double {0.1}};
    CommercialAccount Acc (*num,*bal,*tax,bank);
    ofstream foutA (R"(C:\Users\Admin\Desktop\Payment_System\Lists\AccountList.txt)",ios_base::app);
    foutA << Acc <<"\t"<<"tax: "<<Acc.getTax()<<endl;
    foutA.close();

    shared_ptr <string> name {new string {""}};
    cout<<"Enter name of private company"<<endl;
    cin>>*name;
    shared_ptr <double> sal {new double {0.0}};
    cout<<"Enter employee`s salary in private company"<<endl;
    cin>>*sal;
    shared_ptr <string> spec {new string {""}};
    cout<<"Enter specialization of private company"<<endl;
    cin>>*spec;
    shared_ptr <string> owName {new string {""}};
    cout<<"Enter owner`s name of private company"<<endl;
    cin>>*owName;
    shared_ptr <string> owSurname {new string {""}};
    cout<<"Enter owner`s surname of private company"<<endl;
    cin>>*owSurname;

    PrivatCompany PrivComp (*name,*sal,*spec,*owName,*owSurname,Acc);
    ofstream foutC (R"(C:\Users\Admin\Desktop\Payment_System\Lists\CompanyList.txt)",ios_base::app);
    foutC<<PrivComp<<"\t"<<"Owner: "<<PrivComp.getOwnerN()<<" "<<PrivComp.getOwnerS()<<endl;
}

void AddStateCompany(Bank &bank){
    cout<<"You want to add state company"<<endl<<endl;
    cout << "You must to create commercial account" << endl;
    shared_ptr <int> num{new int {0}};
    cout<<"Enter the number of your`s account"<<endl;
    cin>>*num;
    shared_ptr <double> bal {new double {0}};
    shared_ptr <double> tax  {new double {0.1}};
    CommercialAccount Acc (*num,*bal,*tax,bank);
    ofstream foutA (R"(C:\Users\Admin\Desktop\Payment_System\Lists\AccountList.txt)",ios_base::app);
    foutA <<Acc<<"\t"<<"tax:"<<Acc.getTax()<<endl;
    foutA.close();

    shared_ptr <string> name {new string {""}};
    cout<<"Enter name of state company"<<endl;
    cin>>*name;
    shared_ptr <double> sal {new double {0}};
    cout<<"Enter employee`s salary in state company"<<endl;
    cin>>*sal;
    shared_ptr <string> spec {new string {""}};
    cout<<"Enter specialization of state company"<<endl;
    cin>>*spec;
    shared_ptr <string> state {new string {""}};
    cout<<"Enter company`s State"<<endl;
    cin>>*state;

    StateCompany StateComp (*name,*sal,*spec,*state,Acc);
    ofstream foutC (R"(C:\Users\Admin\Desktop\Payment_System\Lists\CompanyList.txt)",ios_base::app);
    foutC<<StateComp<<"\t"<<"state: "<<StateComp.getState()<<endl;
    foutC.close();
}


void AddEmployee(Bank &bank){
    cout << "You must to create personal account" << endl;
    shared_ptr <int> num{new int {0}};
    cout<<"Enter the number of your`s account"<<endl;
    cin>>*num;
    shared_ptr <double> bal {new double {0}};
    shared_ptr <double> lim  {new double {10000}};
    PersonalAccount Acc (*num,*bal,*lim,bank);
    ofstream foutA (R"(C:\Users\Admin\Desktop\Payment_System\Lists\AccountList.txt)",ios_base::app);
    foutA <<Acc<<"\t"<<"Limit:"<<Acc.getLimit()<<endl;
    foutA.close();

    shared_ptr<string> name {new string {""}};
    cout<<"Enter name of employee"<<endl;
    cin>>*name;
    shared_ptr<string> surname {new string {""}};
    cout<<"Enter surname of employee"<<endl;
    cin>>*surname;
    shared_ptr<int> salary {new int {0}};
    cout<<"Enter salary of employee"<<endl;
    cin>>*salary;
    shared_ptr<string> pos {new string {""}};
    cout<<"Enter position of employee"<<endl;
    cin>>*pos;

    Employee Emp (*name,*surname,*salary,*pos,Acc);
    ofstream foutE (R"(C:\Users\Admin\Desktop\Payment_System\Lists\EmployeeList.txt)",ios_base::app);
    foutE<<Emp;
    foutE.close();
};

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
            while(1) {
                cout << "Chose what do you want:" << endl;
                cout << "A - to add PRIVATE COMPANY" << endl;
                cout << "B - to add STATE COMPANY" << endl;
                cout << "C - to add EMPLOYEE" << endl;
                cout << "Q - if you want to stop" << endl;
                char choice;
                cin >> choice;
                try {
                    if (choice!='A'&&choice!='B'&&choice!='C'&&choice!='Q' )
                        throw 0;
                    switch (choice) {
                        case 'A': {  //add private company
                            AddPrivateCompany(Banker);
                            break;
                        }
                        case 'B': {  //add state company
                            AddStateCompany(Banker);
                            break;
                        }

                        case 'C': {  //add employee
                            AddEmployee(Banker);
                            break;
                        }
                        case 'Q': {
                            return 0;
                        }
                    }

                }
                catch (int &ex) {
                    cerr << "Wrong choice!!!" << endl;
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
