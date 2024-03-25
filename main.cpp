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
#include "FileException.h"
#include "WrongType.h"
#include "WrongPassword.h"
#include "WrongChoice.h"
#include "Functions.h"

Bank Banker("Banker",0.1,"Chernivtsi");

int main() {
    cout<<"Welcome to the Banker!"<<endl<<endl;
    cout<<"Choose who you are: "<<endl<<"Enter 1 if you are the Admin"
    <<endl<<"Enter 2 if you are the User";
    Shtrix();
    int init;
    cin>>init;
    try {
        if(init != 1 && init != 2)
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
        } else {   //for user
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
