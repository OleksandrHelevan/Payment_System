cmake_minimum_required(VERSION 3.27)
project(Payment_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Payment_System main.cpp
        Bank.cpp
        Bank.h
        Company.cpp
        Company.h
        Employee.cpp
        Employee.h
        Account.cpp
        Account.h
        PersonalAccount.cpp
        PersonalAccount.h
        CommercialAccount.cpp
        CommercialAccount.h
        PrivatCompany.cpp
        PrivatCompany.h
        StateCompany.cpp
        StateCompany.h
)
