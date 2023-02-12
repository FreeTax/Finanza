//
// Created by Francesco Mazzola on 12/02/23.
//

#ifndef FINANZA_TRANSACTION_H
#define FINANZA_TRANSACTION_H
#include "BankAccount.h"



class Transaction {
public:
//attributes
    float value;
    int sender;
    int receiver;
//methods
    Transaction(BankAccount sender, BankAccount receiver, float value);
    virtual ~Transaction();

    bool isValid();
    bool makeTransaction();
};


#endif //FINANZA_TRANSACTION_H
