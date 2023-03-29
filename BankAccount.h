// Created by Francesco Mazzola on 12/02/23.
//

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
#include <list>
#include "Transaction.h"

class BankAccount {

private:
    std::list<Transaction> transactions;

    int id;
    float balance;

    std::string filename;
public:
    BankAccount(int id);

    virtual ~BankAccount();

    const float getBalance();

    const std::list<Transaction> &getTransactions() const;

    const int getId();

    void incrementBalance(float value);

    void decrementBalance(float value);

    void makeTransaction(BankAccount *receiver, float value, std::string description, std::string data);

    void receiveTransaction(BankAccount *sender, float value, Transaction transaction);

    void printAccountBalanceAndTransactions();

    void insertTransaction(Transaction transaction);

    void addTransaction(Transaction transaction);

    void loadTransactionsFromFile();

    void removeTransaction(Transaction transaction);

    void removeBalance(Transaction transaction);

    void editBalanceInFile();
};
#endif
