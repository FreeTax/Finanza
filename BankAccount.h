// Created by Francesco Mazzola on 12/02/23.
//

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
#include "IOFile.h"


class BankAccount {
private:
    int id;
    float balance;
    IOFile ioFile;
public:
    BankAccount(int id);

    virtual ~BankAccount();

    float getBalance();

    int getId();

    void incrementBalance(float value);

    void decrementBalance(float value);

    void makeTransaction(BankAccount *receiver, float value);

    void receiveTransaction(BankAccount *sender, float value);

    void printAccountBalanceAndTransactions();


};

#endif


