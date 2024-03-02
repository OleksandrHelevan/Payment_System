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
        Counter.cpp
        Counter.h
        Account.cpp
        Account.h)
