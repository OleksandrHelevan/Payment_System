//
// Created by Admin on 25.03.2024.
//

#ifndef PAYMENT_SYSTEM_FUNCTIONS_H
#define PAYMENT_SYSTEM_FUNCTIONS_H
#include <iostream>
#include "Bank.h"
using namespace std;
void Shtrix();
void AddPrivateCompany(Bank &bank);
void AddStateCompany(Bank &bank);
void AddEmployee(Bank &bank);
void ReadEmployeesFromFile();
void ThrowMoney(string nameE, string surnameE,double amount,Bank &bank);
bool IsEmpInFile(string nameEm, string surnameEm);
void WithdrawMoneyTrans(string nameE, string surnameE,double amount,string nameE2, string surnameE2,Bank &bank);
void ThrowMoneyTrans(string nameE, string surnameE,double amount,string nameE2, string surnameE2,Bank &bank);
void ShowHistory(string nameE,string surnameE);
void WithdrawMoney(string nameE, string surnameE,double amount,Bank &bank);

#endif //PAYMENT_SYSTEM_FUNCTIONS_H
