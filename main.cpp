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

Bank Banker("Banker",0.1,"Chernivtsi");

void Shtrix(){
    cout<<endl<<"--------------------------"<<endl;
};


void AddPrivateCompany(Bank &bank){
    cout<<"You want to add private company"<<endl<<endl;
    cout << "You must to create commercial account" << endl;
    shared_ptr <int> num{new int {0}};
    cout<<"Enter the number of your`s account"<<endl;
    cin>>*num;
    shared_ptr <double> bal {new double {0}};
    shared_ptr <double> tax  {new double {0.1}};
    CommercialAccount Acc (*num,*bal,*tax,bank);
    ofstream foutCA (R"(C:\Users\Admin\Desktop\Payment_System\Lists\Commercial_Account_List.txt)",
                     ios_base::app);
    foutCA << Acc <<"\t"<<Acc.getTax()<<endl;
    foutCA.close();

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
    ofstream foutPC (R"(C:\Users\Admin\Desktop\Payment_System\Lists\Private_Company_List.txt)",
                     ios_base::app);
    foutPC<<PrivComp<<"\t"<<PrivComp.getOwnerN()<<" "<<PrivComp.getOwnerS()<<"\t"<<*num<<endl;
    foutPC.close();
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
    ofstream foutCA (R"(C:\Users\Admin\Desktop\Payment_System\Lists\Commercial_Account_List.txt)",
                     ios_base::app);
    foutCA <<Acc<<"\t"<<Acc.getTax()<<endl;
    foutCA.close();

    shared_ptr <string> name {new string {""}};
    cout<<"Enter name of state company"<<endl;
    cin>>*name;
    shared_ptr <double> sal {new double {0.0}};
    cout<<"Enter employee`s salary in state company"<<endl;
    cin>>*sal;
    shared_ptr <string> spec {new string {""}};
    cout<<"Enter specialization of state company"<<endl;
    cin>>*spec;
    shared_ptr <string> state {new string {""}};
    cout<<"Enter company`s State"<<endl;
    cin>>*state;

    StateCompany StateComp (*name,*sal,*spec,*state,Acc);
    ofstream foutSC (R"(C:\Users\Admin\Desktop\Payment_System\Lists\State_Company_List.txt)",ios_base::app);
    foutSC<<StateComp<<"\t"<<StateComp.getState()<<"\t"<<*num<<endl;
    foutSC.close();
}




void AddEmployee(Bank &bank){
    cout << "You must to create personal account" << endl;
    shared_ptr <int> num{new int {0}};
    cout<<"Enter the number of your`s account"<<endl;
    cin>>*num;
    shared_ptr <double> bal {new double {0}};
    shared_ptr <double> lim  {new double {10000}};
    PersonalAccount Acc (*num,*bal,*lim,bank);
    ofstream foutPA (R"(C:\Users\Admin\Desktop\Payment_System\Lists\Personal_Account_List.txt)",
                    ios_base::app);
    foutPA <<Acc<<"\t"<<Acc.getLimit()<<endl;
    foutPA.close();

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
    ofstream foutE (R"(C:\Users\Admin\Desktop\Payment_System\Lists\Employee_List.txt)",ios_base::app);
    foutE<<Emp<<"\t"<<*num;
    foutE.close();
}

void ReadEmployeesFromFile() {
    ifstream finE(R"(C:\Users\Admin\Desktop\Payment_System\Lists\Employee_List.txt)");
    if (!finE.is_open()) {
        cerr << "Error opening file: " << endl;
    }

    shared_ptr <string> name{new string {""}};
    shared_ptr <string> surname{new string {""}};
    shared_ptr <string> position{new string {""}};
    shared_ptr <int> salary{new int {0}};
    shared_ptr <int> numofAcc{new int{0}};
    while (finE >> *name >> *surname >> *salary >> *position >> *numofAcc) {
        cout << *name <<" "<< *surname << "\t" << *salary << "\t" << *position<< endl;
    }

    finE.close();
}

bool IsEmpInFile(string nameEm, string surnameEm){
    ifstream finE(R"(C:\Users\Admin\Desktop\Payment_System\Lists\Employee_List.txt)");
    if (!finE.is_open()) {
        cerr << "Error opening file: " << endl;
    }
    else {
        shared_ptr<string> name{new string{""}};
        shared_ptr<string> surname{new string{""}};
        shared_ptr<string> position{new string{""}};
        shared_ptr<int> salary{new int{0}};
        shared_ptr<int> numofAcc{new int{0}};
        while (finE >> *name >> *surname >> *salary >> *position >> *numofAcc) {
            if (nameEm == *name && surnameEm == *surname) {
                finE.close();
                return true;
            }
        }
        finE.close();
        return false;
    }
}

void Withdraw(string nameE, string surnameE,double amount){
    if(IsEmpInFile(nameE,surnameE)) {
        ifstream finE(R"(C:\Users\Admin\Desktop\Payment_System\Lists\Employee_List.txt)");
        if (!finE.is_open()) {
            cerr << "Error opening file: " << endl;
        } else {
            shared_ptr<string> name{new string{""}};
            shared_ptr<string> surname{new string{""}};
            shared_ptr<string> position{new string{""}};
            shared_ptr<int> salary{new int{0}};
            shared_ptr<int> numofAcc{new int{0}};
            while (finE >> *name >> *surname >> *salary >> *position >> *numofAcc) {
                if (nameE == *name && surnameE == *surname) {
                    finE.close();
                    ifstream finPA(R"(C:\Users\Admin\Desktop\Payment_System\Lists\Personal_Account_List.txt)");
                    if(!finPA.is_open())
                        cerr<<"ERROR";
                    else{
                        shared_ptr<int> number{new int{0}};
                        shared_ptr<double> balance{new double {0}};
                        shared_ptr<double> limit{new double {0}};
                        while (finPA >> *number >> *balance >> *limit) {
                            if (*numofAcc == *number) {
                                finPA.close();
                            }
                            PersonalAccount Acc(*number, *balance, *limit, Banker);
                            Acc.takeMoney(amount);
                            vector<int> numbers;
                            vector<double> balances;
                            vector<double> limits;
                            ifstream finPA
                            (R"(C:\Users\Admin\Desktop\Payment_System\Lists\Personal_Account_List.txt)");
                            if (!finPA.is_open())
                                cerr << "ERROR";
                            else {
                                while (finPA >> *number >> *balance >> *limit) {
                                    numbers.push_back(*number);
                                    balances.push_back(*balance);
                                    limits.push_back(*limit);
                                }
                                finPA.close();
                                ofstream foutPA
                                (R"(C:\Users\Admin\Desktop\Payment_System\Lists\Personal_Account_List.txt)");
                                for(int i=0; i<numbers.capacity(); i++)
                                {
                                    if(numbers[i]!= *numofAcc)
                                    {
                                        foutPA<<numbers[i]<<"\t"<<balances[i]<<"\t"<<limits[i]<<endl;
                                    }
                                    else{
                                        foutPA<<Acc<<"\t"<<Acc.getLimit();
                                        ofstream foutH(R"(C:\Users\Admin\Desktop\Payment_System\Lists\History.txt)"
                                                       ,ios_base::app);
                                        foutH<<numbers[i]<<"\t"<<balances[i]<<" -> " << balances[i]-amount<<
                                        "\t"<<"withdrawing"<<endl;
                                    }
                                    foutPA.close();
                                }
                            }
                        }
                    }
                }

            }
            finE.close();
        }
    }
    else
        cerr<<"ERROR";

}

void ThrowMoney(string nameE, string surnameE,double amount){
    if(IsEmpInFile(nameE,surnameE)) {
        ifstream finE(R"(C:\Users\Admin\Desktop\Payment_System\Lists\Employee_List.txt)");
        if (!finE.is_open()) {
            cerr << "Error opening file: " << endl;
        } else {
            shared_ptr<string> name{new string{""}};
            shared_ptr<string> surname{new string{""}};
            shared_ptr<string> position{new string{""}};
            shared_ptr<int> salary{new int{0}};
            shared_ptr<int> numofAcc{new int{0}};
            while (finE >> *name >> *surname >> *salary >> *position >> *numofAcc) {
                if (nameE == *name && surnameE == *surname) {
                    finE.close();
                    ifstream finPA(R"(C:\Users\Admin\Desktop\Payment_System\Lists\Personal_Account_List.txt)");
                    if(!finPA.is_open())
                        cerr<<"ERROR";
                    else{
                        shared_ptr<int> number{new int{0}};
                        shared_ptr<double> balance{new double {0}};
                        shared_ptr<double> limit{new double {0}};
                        while (finPA >> *number >> *balance >> *limit) {
                            if (*numofAcc == *number) {
                                finPA.close();
                            }
                            PersonalAccount Acc(*number, *balance, *limit, Banker);
                            Acc.addMoney(amount);
                            vector<int> numbers;
                            vector<double> balances;
                            vector<double> limits;
                            ifstream finPA
                                    (R"(C:\Users\Admin\Desktop\Payment_System\Lists\Personal_Account_List.txt)");
                            if (!finPA.is_open())
                                cerr << "ERROR";
                            else {
                                while (finPA >> *number >> *balance >> *limit) {
                                    numbers.push_back(*number);
                                    balances.push_back(*balance);
                                    limits.push_back(*limit);
                                }
                                finPA.close();
                                ofstream foutPA
                                        (R"(C:\Users\Admin\Desktop\Payment_System\Lists\Personal_Account_List.txt)");
                                for(int i=0; i<numbers.capacity(); i++)
                                {
                                    if(numbers[i]!= *numofAcc)
                                    {
                                        foutPA<<numbers[i]<<"\t"<<balances[i]<<"\t"<<limits[i]<<endl;
                                    }
                                    else{
                                        foutPA<<Acc<<"\t"<<Acc.getLimit();
                                        ofstream foutH(R"(C:\Users\Admin\Desktop\Payment_System\Lists\History.txt)"
                                                       ,ios_base::app);
                                        foutH<<numbers[i]<<"\t"<<balances[i]<<" -> " << balances[i]+amount<<
                                        "\t"<<"throwing"<<endl;
                                    }
                                    foutPA.close();
                                }
                            }
                        }
                    }
                }

            }
            finE.close();
        }
    }
    else
        cerr<<"ERROR";

}



int main() {
    cout<<"Welcome to the Banker!"<<endl<<endl;
    cout<<"Choose who you are: "<<endl<<"Enter 1 if you are the Admin"
    <<endl<<"Enter 2 if you are the User";
    Shtrix();
    int init;
    cin>>init;

    if(init == 1)   //for Admin
    {
        string password;
        cout<<"Enter the password"<<endl;
        cin>>password;
        if(password=="IPZ")
        {
            while(true) {
                Shtrix();
                cout << "Chose what do you want:" << endl;
                cout << "A - Add PRIVATE COMPANY" << endl;
                cout << "B - Add STATE COMPANY" << endl;
                cout << "C - Add EMPLOYEE" << endl;
                cout <<"D - Show list of Employee" << endl;
                cout << "press Q - if you want to stop";
                Shtrix();

                char choice;
                cin >> choice;
                try {
                    if (choice!='A' && choice!='B' && choice!='C' && choice!='Q' && choice!='D' )
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

                        case 'D':{  //show employees
                            ReadEmployeesFromFile();
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
        Shtrix();
        cout<<"Hello user";
        Shtrix();
        cout<<"You need to authorize"<<endl;
        cout<<"Enter your name: "<<endl;
        shared_ptr <string> name{new string {""}};
        cin>>*name;
        cout<<"Enter your surname:"<<endl;
        shared_ptr <string> surname{new string {""}};
        cin>>*surname;

        if(IsEmpInFile(*name,*surname)){
            while (true) {
                Shtrix();
                cout << "Chose what do you want:" << endl;
                cout << "A - Make transaction" << endl;
                cout << "B - Withdraw money" << endl;
                cout << "C - Top up the account" << endl;
                cout <<"D - View payment history" << endl;
                cout << "press Q - if you want to stop";
                Shtrix();

                char choice;
                cin >> choice;
                try {
                    if (choice != 'A' && choice != 'B' && choice != 'C' &&  choice != 'D' && choice != 'Q')
                        throw 0.0;
                    switch (choice) {
                        case 'A':{

                            break;
                        }

                        case 'B':{
                            shared_ptr <double> amount{new double {0}};
                            cout<<"Enter amount of withdrawing:"<<endl;
                            cin>>*amount;
                            Withdraw(*name,*surname,*amount);
                            break;
                        }

                        case 'C':{
                            shared_ptr <double> amount{new double {0}};
                            cout<<"Enter amount of throwing:"<<endl;
                            cin>>*amount;
                            ThrowMoney(*name,*surname,*amount);
                            break;
                        }

                        case 'D':{
                            break;
                        }

                        case 'Q':{
                            return 0;

                        }

                    }
                }
                catch (double &ex) {
                    cerr << "Wrong choice!!!";
                }
            }
        }
    }
}
