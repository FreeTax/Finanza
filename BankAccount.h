//
// Created by Francesco Mazzola on 12/02/23.
//

#ifndef FINANZA_BANKACCOUNT_H
#define FINANZA_BANKACCOUNT_H


class BankAccount {
public:
    virtual ~BankAccount();

    BankAccount();

    float getBalance();
    int getId();
    void incrementBalance(float balance);

private:
    int id;
    float balance;
};


#endif //FINANZA_BANKACCOUNT_H
