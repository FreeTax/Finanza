//
// Created by Francesco Mazzola on 12/02/23.
//
#include "BankAccount.h"
#include "Transaction.h"
#include <iostream>



BankAccount::BankAccount(int id) : id(id){
//check if the file existss
    ioFile = *new IOFile(id);
    balance = ioFile.getBalanceFromFile();

}

BankAccount::~BankAccount() {}

float BankAccount::getBalance() {
    return balance;
}

int BankAccount::getId() {
    return id;
}

void BankAccount::incrementBalance(float value) {
    balance += value;
    ioFile.saveToFile("balance incremented with value: "+std::to_string(value)+" and balance: "+std::to_string(balance));
}

void BankAccount::decrementBalance(float value) {
    balance = balance - value;
    ioFile.saveToFile("balance decremented with value: "+std::to_string(value)+" and balance: "+std::to_string(balance));
}

void BankAccount::makeTransaction(BankAccount *receiver, float value) {
    Transaction transaction = *new Transaction(this, receiver, value);
    transaction.makeTransaction();
    std::string dataString="transaction made to the user: "+std::to_string(receiver->getId())+" with value: "+std::to_string(value)+" and balance: "+std::to_string(balance);
    ioFile.saveToFile(dataString);
}

void BankAccount::receiveTransaction(BankAccount *sender, float value) {
    balance += value;
    std::string dataString="transaction received from the user: "+std::to_string(sender->getId())+" with value: "+std::to_string(value)+" and balance: "+std::to_string(balance);
    ioFile.saveToFile(dataString);
}

void BankAccount::printAccountBalanceAndTransactions() {
    std::cout<<"Account balance and Transactions: "<<balance<<std::endl;
    ioFile.printAccountBalnceAndTransactions();

}

