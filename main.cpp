#include <iostream>
#include "BankAccount.h"
#include "Transaction.h"

int main() {
    BankAccount bankAccount(1);
    bankAccount.incrementBalance(10);
    Transaction transaction("1", "receiver", 10, "description", "date");
    bankAccount.insertTransaction(transaction);
    bankAccount.printAccountBalanceAndTransactions();
    bankAccount.removeTransaction(transaction);
    bankAccount.printAccountBalanceAndTransactions();

}
