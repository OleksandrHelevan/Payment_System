#include <iostream>
#include <array>
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
array<T,100> ArrayLaba(array <T,3> &A, array<T,3> &B, int size1, int size2){
    for (int i=0 ;i<size1; i++) {
        for(int j=i+1; j<size1;j++){
            if(A[i]>A[j]){
                unique_ptr<T> p = make_unique<T>();
                *p = A[i];
                A[i] = A[j];
                A[j] = *p;
            }
        }
    }

    for (int i=0 ;i<size2; i++) {
        for(int j=i+1; j<size2;j++){
            if(B[i]>B[j]){
                unique_ptr<T> p = make_unique<T>();
                *p = B[i];
                B[i] = B[j];
                B[j] = *p;
            }
        }
    }
    array<T,100> C;
    for(int i=0; i<size1; i++ ){
       cout<<A[i]<<endl;
    }
    Shtrix();
    for(int i=0; i<size2; i++ ) {
        cout << B[i] << endl;
    }

    Shtrix();
    for (int i=0; i<size1+size2; i++){
        if(i<size1)
            C[i] = A[i];
        else C[i] = B[i-size1];
    }

    for (int i=0; i<size1+size2; i++)
        cout<<C[i]<<endl;

    for (int i =0; i<size1+size2; i++)
    for(int j=i+1; j<size1+size2;j++){
        if(C[i]>C[j]){
            unique_ptr<T> p = make_unique<T>();
            *p = C[i];
            C[i] = C[j];
            C[j] = *p;
        }
    }

    return C;
}
template <typename T>

void VectorLaba(vector <T> A){
    int countp;
    int countnp;
    vector<T> Par;
    vector <T> Npar;
    auto it = A.begin();
    while (it!=A.end()) {
        if (*it % 2 == 0) {
            Par.push_back(*it);
        } else Npar.push_back(*it);

        cout << *it << endl;
        it++;

    }
    vector <T> Res;
    auto pit = Par.begin();
    while(pit!=Par.end()){
        Res.push_back(*pit);
        pit++;
    }
    auto npit = Npar.begin();
    while(npit!=Npar.end()) {
        Res.push_back(*npit);
        npit++;
    }

    auto resit = Res.begin();
    while(resit!=Res.end()) {
        cout << *resit;
        resit++;
    }


}


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
            cout<<"First "<<endl;
            Shtrix();
            Bank A1 ("SECOND",0.2,"Khust");
            Bank A2 ("THIRD",0.3,"Khust");
            Bank A3 ("FIRST",0.1,"Khust");

            Bank B1 ("SECOND",0.2,"Khust");
            Bank B2 ("FIFTH",0.5,"Khust");
            Bank B3 ("FOURTH",0.4,"Khust");

            array <Bank,3> A {A1,A2,A3};
            array <Bank,3> B {B1,B2,B3};
            array <Bank,100> C;
            C = ArrayLaba(A,B,A.size(),B.size());
            Shtrix();
            for (int i = 0; i< 6; i++)
                cout<<C[i]<<endl;
            Shtrix();
            cout<<"\tSecond"<<endl;
            Shtrix();
            vector <Bank> VA{A1,A2,A3,B1,B2,B3};
            vector <int> Al{1,2,3,4,5,6};
            VectorLaba(Al);

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
