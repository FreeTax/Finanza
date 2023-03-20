#include <iostream>
#include "BankAccount.h"

int main() {
    int id1=1;
    int id2=2;
    BankAccount *account1 = new BankAccount(id1);
    BankAccount *account2 = new BankAccount(id2);
    account1->incrementBalance(200);
    std::cout << "Account "<<id1<<" balance: " << account1->getBalance() << std::endl;
    std::cout << "Account"<<id2<< " balance: " << account2->getBalance() << std::endl;
    account2->incrementBalance(100);
    std::cout << "Account"<<id1<<  " balance: " << account1->getBalance() << std::endl;
    std::cout << "Account<<"<<id2<< " balance: " << account2->getBalance() << std::endl;
    account1->makeTransaction(account2, 100);
    std::cout<< "Transaction done" << std::endl;
    std::cout << "Account "<<id1<<" balance: " << account1->getBalance() << std::endl;
    std::cout << "Account "<<id2<<" balance: " << account2->getBalance() << std::endl;
    account1->makeTransaction(account2, 100);
    std::cout<< "Transaction done" << std::endl;
    std::cout << "Account "<< id1<< " balance: " << account1->getBalance() << std::endl;
    std::cout << "Account "<<id2<<" balance: " << account2->getBalance() << std::endl;

    std::cout<<"Account 1 transactions: "<<std::endl;
    account1->printAccountBalanceAndTransactions();
    std::cout<<"Account 2 transactions: "<<std::endl;
    account2->printAccountBalanceAndTransactions();
    return 0;
}
