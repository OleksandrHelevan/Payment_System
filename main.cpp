#include <iostream>
#include <array>
#include <algorithm>
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
#include "FileException.h"
#include "WrongType.h"
#include "WrongPassword.h"
#include "WrongChoice.h"
#include "Functions.h"

Bank Banker("Banker",0.1,"Chernivtsi");
template <typename T>
void swaps(T &lhs, T&rhs){
    swap(lhs,rhs);
}
template <typename T>
void Laba9Ex(array <T,3> &A, array<T,3> &B){
    array <T,3> A1;
    array <T,3> B1;
    for (int i=0 ;i<3; i++) {
        for(int j=i+1; j<3;j++){
            if(A[i]>A[j]){
                //unique_ptr<T> p = make_unique<T>();
//                *p = A[i];
//                A[i] = A[j];
//                A[j] = *p;
            };
        }
    }

    for(int i=0; i<3; i++ ){
       cout<<A[i]<<endl;
    }


};

int main() {
    cout<<"Welcome to the Banker!"<<endl<<endl;
    cout<<"Choose who you are: "<<endl<<"Enter 1 if you are the Admin"
    <<endl<<"Enter 2 if you are the User";
    Shtrix();
    int init;
    cin>>init;
    try {
        if(init != 1 && init != 2 && init != 3)
            throw WrongType();
        if (init == 1)   //for Admin
        {
            string password;
            cout << "Enter the password" << endl;
            cin >> password;
            if (password == "IPZ") {
                while (true) {
                    Shtrix();
                    cout << "Chose what do you want:" << endl;
                    cout << "A - Add PRIVATE COMPANY" << endl;
                    cout << "B - Add STATE COMPANY" << endl;
                    cout << "C - Add EMPLOYEE" << endl;
                    cout << "D - Show list of Employee" << endl;
                    cout << "press Q - if you want to stop";
                    Shtrix();

                    char choice;
                    cin >> choice;
                    try {
                        if (choice != 'A' && choice != 'B' && choice != 'C' && choice != 'Q' && choice != 'D')
                            throw WrongChoice();
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

                            case 'D': {  //show employees
                                ReadEmployeesFromFile();
                                break;
                            }

                            case 'Q': {
                                return 0;
                            }
                        }

                    }
                    catch (WrongChoice &A){
                        cerr<<A.what();
                    }
                }
            } else {
                throw WrongPassword();
            }
        } else if(init == 2){   //for user
            Shtrix();
            cout << "Hello user";
            Shtrix();
            cout << "You need to authorize" << endl;
            cout << "Enter your name: " << endl;
            shared_ptr<string> name{new string{""}};
            cin >> *name;
            cout << "Enter your surname:" << endl;
            shared_ptr<string> surname{new string{""}};
            cin >> *surname;

            if (IsEmpInFile(*name, *surname)) {
                while (true) {
                    Shtrix();
                    cout << "Chose what do you want:" << endl;
                    cout << "A - Make transaction" << endl;
                    cout << "B - Withdraw money" << endl;
                    cout << "C - Top up the account" << endl;
                    cout << "D - View payment history" << endl;
                    cout << "press Q - if you want to stop";
                    Shtrix();

                    char choice;
                    cin >> choice;
                    try {
                        if (choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D' && choice != 'Q')
                            throw WrongChoice();
                        switch (choice) {
                            case 'A': {
                                shared_ptr<string> name2{new string{""}};
                                cout << "Enter name of recipient: " << endl;
                                cin >> *name2;

                                shared_ptr<string> surname2{new string{""}};
                                cout << "Enter surname of recipient: " << endl;
                                cin >> *surname2;
                                if(!IsEmpInFile(*name2,*surname2))
                                    throw FileExcaption();
                                shared_ptr<double> amount{new double{0}};
                                cout << "Enter amount of throwing:" << endl;
                                cin >> *amount;

                                WithdrawMoneyTrans(*name, *surname, *amount,
                                                   *name2, *surname2,Banker);
                                ThrowMoneyTrans(*name, *surname, *amount,
                                                *name2, *surname2,Banker);
                                break;
                            }

                            case 'B': {
                                shared_ptr<double> amount{new double{0}};
                                cout << "Enter amount of withdrawing:" << endl;
                                cin >> *amount;
                                WithdrawMoney(*name, *surname, *amount,Banker);
                                break;
                            }

                            case 'C': {
                                shared_ptr<double> amount{new double{0}};
                                cout << "Enter amount of throwing:" << endl;
                                cin >> *amount;
                                ThrowMoney(*name, *surname, *amount,Banker);
                                break;
                            }

                            case 'D': {
                                ShowHistory(*name, *surname);
                                break;
                            }

                            case 'Q': {
                                return 0;

                            }

                        }
                    }
                    catch (WrongChoice &A){
                        cerr<<A.what();
                    }
                }
            }
            else
                throw FileExcaption();
        }
        else if(init ==3){
            cout<<"Laba 9 "<<endl;
            Shtrix();
            Bank Laba9 ("Example",0,"Khust");
            PersonalAccount one (3,3000,1000,Laba9);
            PersonalAccount two (1,1000,1000,Laba9);
            PersonalAccount three (2,2000,1000,Laba9);

            PersonalAccount one1 (5,5000,1000,Laba9);
            PersonalAccount two1 (4,4000,1000,Laba9);
            PersonalAccount three1 (3,3000,1000,Laba9);
            array <PersonalAccount, 3> A {one,two,three};
            array <PersonalAccount, 3> B {one1,two1,three1};
            array <int,3> C {3,1,2};
            Laba9Ex(A, A );
        }
    }
    catch(WrongPassword &Password){
        cerr<<Password.what();
    }
    catch(WrongType &A){
        cerr<<A.what();
    }
    catch(FileExcaption &A){
        cerr<<A.what();
    }
}
