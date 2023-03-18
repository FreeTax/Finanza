#include <iostream>
#include "BankAccount.h"

int main() {
    BankAccount *account1 = new BankAccount(0);
    BankAccount *account2 = new BankAccount(1);
    account1->incrementBalance(200);
    std::cout << "Account 1 balance: " << account1->getBalance() << std::endl;
    std::cout << "Account 2 balance: " << account2->getBalance() << std::endl;
    account2->incrementBalance(100);
    std::cout << "Account 1 balance: " << account1->getBalance() << std::endl;
    std::cout << "Account 2 balance: " << account2->getBalance() << std::endl;
    account1->makeTransaction(account2, 100);
    std::cout<< "Transaction done" << std::endl;
    std::cout << "Account 1 balance: " << account1->getBalance() << std::endl;
    std::cout << "Account 2 balance: " << account2->getBalance() << std::endl;
    account1->makeTransaction(account2, 100);
    std::cout<< "Transaction done" << std::endl;
    std::cout << "Account 1 balance: " << account1->getBalance() << std::endl;
    std::cout << "Account 2 balance: " << account2->getBalance() << std::endl;

    return 0;
}
