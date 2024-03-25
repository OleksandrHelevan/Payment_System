#include "Functions.h"
#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include "PersonalAccount.h"
#include "Bank.h"
#include "CommercialAccount.h"
#include "Employee.h"
#include "PrivatCompany.h"
#include "StateCompany.h"
using namespace std;

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
    foutE<<Emp<<"\t"<<*num<<endl;
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



void ThrowMoney(string nameE, string surnameE,double amount,Bank &bank){
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
                                PersonalAccount Acc(*number, *balance, *limit, bank);
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
                                    for(int i=0; i<numbers.size(); i++)
                                    {
                                        if(numbers[i]!= *numofAcc)
                                        {
                                            foutPA<<numbers[i]<<"\t"<<balances[i]<<"\t"<<limits[i]<<endl;
                                        }
                                        else{
                                            foutPA<<Acc<<"\t"<<Acc.getLimit()<<endl;
                                            ofstream foutH(R"(C:\Users\Admin\Desktop\Payment_System\Lists\History.txt)"
                                                    ,ios_base::app);
                                            foutH<<numbers[i]<<"\t"<<balances[i]<<" -> " << balances[i]+amount<<
                                                 "\t"<<"thrown_by "<<nameE<<" "<<surnameE<<endl;
                                        }
                                    }
                                    foutPA.close();
                                    break;
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



void WithdrawMoneyTrans(string nameE, string surnameE,double amount,string nameE2, string surnameE2, Bank &bank){
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
                                PersonalAccount Acc(*number, *balance, *limit, bank);
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
                                    for(int i=0; i<numbers.size(); i++)
                                    {
                                        if(numbers[i]!= *numofAcc)
                                        {
                                            foutPA<<numbers[i]<<"\t"<<balances[i]<<"\t"<<limits[i]<<endl;
                                        }
                                        else{
                                            foutPA<<Acc<<"\t"<<Acc.getLimit()<<endl;
                                            ofstream foutH(R"(C:\Users\Admin\Desktop\Payment_System\Lists\History.txt)"
                                                    ,ios_base::app);
                                            foutH<<numbers[i]<<"\t"<<balances[i]<<" -> " << balances[i]-amount<<
                                                 "\t"<<"sent_to "<<nameE2<<" "<<surnameE2<<endl;
                                            foutH.close();
                                        }
                                    }
                                    foutPA.close();
                                    break;
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



void ThrowMoneyTrans(string nameE, string surnameE,double amount,string nameE2, string surnameE2,Bank &bank){
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
                if (nameE2 == *name && surnameE2 == *surname) {
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
                                PersonalAccount Acc(*number, *balance, *limit, bank);
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
                                    for(int i=0; i<numbers.size(); i++)
                                    {
                                        if(numbers[i] != *numofAcc)
                                        {
                                            foutPA<<numbers[i]<<"\t"<<balances[i]<<"\t"<<limits[i]<<endl;
                                        }
                                        else{
                                            cout<<amount;
                                            foutPA<<numbers[i]<<"\t"<<balances[i]+amount<<"\t"<<limits[i]<<endl;
                                            ofstream foutH(R"(C:\Users\Admin\Desktop\Payment_System\Lists\History.txt)"
                                                    ,ios_base::app);
                                            foutH<<numbers[i]<<"\t"<<balances[i]<<" -> " << balances[i]+amount<<
                                                 "\t"<<"sent_from "<<nameE<<" "<<surnameE<<endl;
                                            foutH.close();
                                        }
                                    }
                                    foutPA.close();
                                    break;
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



void ShowHistory(string nameE,string surnameE){
    shared_ptr<int>number{new int{0}};
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
                    *number=*numofAcc;
                    finE.close();
                    break;
                }
            }
        }
    }else
        cerr<<"ERROR";

    ifstream finH(R"(C:\Users\Admin\Desktop\Payment_System\Lists\History.txt)");
    shared_ptr<int> numb{new int{0}};
    shared_ptr<double> bal1{new double {0}};
    shared_ptr<string> some{new string {""}};
    shared_ptr<double> bal2{new double {0}};
    shared_ptr<string> info{new string {""}};
    shared_ptr<string> name{new string {""}};
    shared_ptr<string> surname{new string {""}};
    while(finH >> *numb >> *bal1 >> *some >> *bal2 >> *info >> *name >> *surname){
        if(*number==*numb){
            cout<< *numb << "\t" << *bal1 <<" " << *some << " "<< *bal2 << "\t" << *info <<" "
                << " "<<*name<<" "<<*surname<<endl;
        }
    }
    finH.close();
}

void WithdrawMoney(string nameE, string surnameE,double amount,Bank &bank){
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
                                PersonalAccount Acc(*number, *balance, *limit, bank);
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
                                    for(int i=0; i<numbers.size(); i++)
                                    {
                                        if(numbers[i]!= *numofAcc)
                                        {
                                            foutPA<<numbers[i]<<"\t"<<balances[i]<<"\t"<<limits[i]<<endl;
                                        }
                                        else{
                                            foutPA<<Acc<<"\t"<<Acc.getLimit()<<endl;
                                            ofstream foutH(R"(C:\Users\Admin\Desktop\Payment_System\Lists\History.txt)"
                                                    ,ios_base::app);
                                            foutH<<numbers[i]<<"\t"<<balances[i]<<" -> " << balances[i]-amount<<
                                                 "\t"<<"withdrawn_by "<<nameE<<" "<<surnameE<<endl;
                                        }
                                    }
                                    foutPA.close();
                                    break;
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