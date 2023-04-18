// Created by Francesco Mazzola on 12/02/23.
//

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
#include <list>
#include "Transaction.h"

class Transaction;

class BankAccount {

private:
    std::list<Transaction> transactions;
    int id;
    float balance;
    std::string filename;

    void loadTransactionsFromFile();

    void removeTransactionFromFile(Transaction& transaction);

    bool removeTransactionFromTransactions(Transaction& transaction);

    void editBalanceInFile();

    void insertTransactionInFile(Transaction& transaction);

public:
    BankAccount(int id);

    float getBalance() const;

    std::list<Transaction> &getTransactions();

    int getId() const;

    void incrementBalance(float value);

    void decrementBalance(float value);

    void printAccountBalanceAndTransactions();

    bool removeTransaction(Transaction& transaction);

    void insertTransaction(Transaction& transaction);

    bool editTransaction(Transaction& transaction, Transaction& newTransaction);
};
#endif
