//
// Created by Francesco Mazzola on 12/02/23.
//
#include "BankAccount.h"
#include "Transaction.h"
#include <fstream>
#include <iostream>


BankAccount::BankAccount(int id) : id(id){
//check if the file existss
    std::string filename = std::to_string(id);
    filename = filename + ".txt";
    std::ifstream file(filename);
    if(!file.good()){
        balance=0;
        std::cout<<"file does not exist"<<std::endl;
        file.close();
        std::ofstream file;
        file.open(filename);
        file << "Account created with id: " << id << " and balance: " << balance << std::endl;
        file.close();
    }
    else{
        std::cout<<"file exists"<<std::endl;
        file.close();
        std::ifstream file;
        file.open(filename);
        std::string line;
        std::string old;
        while (std::getline(file, line)) {
            old=line;
        }
        int index = old.find("balance: ");
        std::cout<<old<<std::endl;
        std::cout<<index<<std::endl;
        std::string balanceString = old.substr(index+9);
        std::cout<<balanceString<<std::endl;
        balance=std::stof(balanceString); //TODO:convert string to float
        std::cout<<"the balance of the account"<<id<< "is: "<<balance<<std::endl;
    }
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
    std::string dataString="transaction made to the user: "+std::to_string(receiver->getId())+" with value: "+std::to_string(value)+" and balance: "+std::to_string(balance);
    saveToFile(dataString);
}

void BankAccount::receiveTransaction(BankAccount *sender, float value) {
    balance += value;
    std::string dataString="transaction received from the user: "+std::to_string(sender->getId())+" with value: "+std::to_string(value)+" and balance: "+std::to_string(balance);
    saveToFile(dataString);

}

void BankAccount::saveToFile(std::string data) {
    std::string filename = std::to_string(id);
    filename = filename + ".txt";
    std::ofstream file;
    file.open(filename, std::ios_base::app);
    file << data << std::endl;
    file.close();
}
