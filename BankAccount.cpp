//
// Created by Francesco Mazzola on 12/02/23.
//
#include "BankAccount.h"
#include "Transaction.h"
#include <fstream>


BankAccount::BankAccount(int id, float balance) : id(id), balance(balance){

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
}

void BankAccount::decrementBalance(float value) {
    balance = balance - value;
}

void BankAccount::makeTransaction(BankAccount *receiver, float value) {
    Transaction transaction = *new Transaction(this, receiver, value);
    transaction.makeTransaction();
    std::string dataString="transaction made to the user: "+std::to_string(receiver->getId())+" with value: "+std::to_string(value);
    saveToFile(dataString);
}

void BankAccount::receiveTransaction(BankAccount *sender, float value) {
    balance += value;
    std::string dataString="transaction received from the user: "+std::to_string(sender->getId())+" with value: "+std::to_string(value);
    saveToFile(dataString);

}

void BankAccount::saveToFile(std::string data) {
    std::ofstream file;
    std::string filename = std::to_string(id);
    filename = filename + ".txt";
    file.open(filename);
    file << data<< std::endl;
    file.close();
}
