#include <iostream>
#include "BankAccount.h"
#include "Transaction.h"

int main() {
    int id1=1;
    int id2=2;
    BankAccount *account1 = new BankAccount(id1);
    BankAccount *account2 = new BankAccount(id2);
    account1->incrementBalance(200000);
    account1->makeTransaction(account2, 100000, "test", "13/02/2021");
    account2->makeTransaction(account1, 100000, "test", "13/02/2021");
    account1->printAccountBalanceAndTransactions();
    account2->printAccountBalanceAndTransactions();
    account1->printAccountBalanceAndTransactions();
    account1->removeTransaction(*new Transaction(std::to_string(id1), std::to_string(id2), 100000, "test", "13/02/2021"));
    std::cout<<"After removing the transaction"<<std::endl;
    account1->printAccountBalanceAndTransactions();
    return 0;
}
