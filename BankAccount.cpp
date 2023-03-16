//
// Created by Francesco Mazzola on 12/02/23.
//
#include "BankAccount.h"
#include "Transaction.h"


BankAccount::BankAccount() {}

BankAccount::~BankAccount() {}

float BankAccount::getBalance() {
    return balance;
}

int BankAccount::getId() {
    return id;
}

void BankAccount::incrementBalance(float value) {
    balance += value;
}

void BankAccount::decrementBalance(float value) {
    balance = balance - value;
}

void BankAccount::makeTransaction(BankAccount *receiver, float value) {
    Transaction transaction = *new Transaction(this, receiver, value);
    transaction.makeTransaction();
}
