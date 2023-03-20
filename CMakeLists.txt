cmake_minimum_required(VERSION 3.5)
project(Finanza)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)
set(SOURCE_FILES Transaction.cpp Transaction.h BankAccount.cpp BankAccount.h IOFile.h IOFile.cpp)
add_executable(Finanza main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(Finanza core)


