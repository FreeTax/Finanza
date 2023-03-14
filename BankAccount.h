// Created by Francesco Mazzola on 12/02/23.
//

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <unistd.h>

class BankAccount {
private:
    int id;
    float balance;
public:
    BankAccount();

    virtual ~BankAccount();

    float getBalance();

    int getId();

    void incrementBalance(float value);

    void decrementBalance(float value);

    void makeTransaction(BankAccount *receiver, float value);


};
#endif


