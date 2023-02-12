cmake_minimum_required(VERSION 3.24)
project(Finanza)

set(CMAKE_CXX_STANDARD 17)

add_executable(Finanza main.cpp Transaction.cpp Transaction.h BankAccount.cpp BankAccount.h)
