//
// Created by Francesco Mazzola on 12/02/23.
//

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <unistd.h>
#include <cstdlib>
#include "BankAccount.h"


class Transaction {

public:
//methods
    Transaction(BankAccount *sender, BankAccount *receiver, float value);

    virtual ~Transaction();

    bool isValid();

    bool makeTransaction();

private:
    BankAccount *sender;
    BankAccount *receiver;
    float value;
};
#endif
