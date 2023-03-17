// Created by Francesco Mazzola on 12/02/23.
//

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>



class BankAccount {
private:
    int id;
    float balance;
public:
    BankAccount(int id, float balance = 0.0);

    virtual ~BankAccount();

    float getBalance();

    int getId();

    void incrementBalance(float value);

    void decrementBalance(float value);

    void makeTransaction(BankAccount *receiver, float value);

    void receiveTransaction(BankAccount *sender, float value);

    void saveToFile(std::string data);

};
#endif


