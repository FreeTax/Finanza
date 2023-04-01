//
// Created by Francesco Mazzola on 12/02/23.
//
#include "BankAccount.h"
#include <iostream>
#include <fstream>



BankAccount::BankAccount(int id) : id(id){
    //check if the file exists
    //if it exists, load the balance from the file
    //else create the file and set the balance to 0
    balance=0;
    filename = std::to_string(id);
    filename = filename + ".txt";
    std::ifstream file(filename);
    if(file.good()) {
        std::string line;
        while (std::getline(file, line)) {
            if (line.find("balance: ") != std::string::npos) {
                int index = line.find("balance: ");
                std::string balanceString = line.substr(index + 9);
                balance = std::stof(balanceString);
            }
        }
        file.close();
        loadTransactionsFromFile();
    } else{
        std::ofstream file(filename);
        file << "Account created with id: " << id << " and balance: " << balance << std::endl;
        file<<"transactions"<<std::endl;
        file.close();
    }
}

BankAccount::~BankAccount() {}

const float BankAccount::getBalance() {
    return balance;
}

const int BankAccount::getId() {
    return id;
}

void BankAccount::incrementBalance(float value) {
    balance += value;
    editBalanceInFile();
}

void BankAccount::decrementBalance(float value) {
    balance = balance - value;
    editBalanceInFile();
}

void BankAccount::insertTransaction(Transaction transaction) {
    transactions.push_back(transaction);
    insertTransactionInFile(transaction);
    if(transaction.getSender()==std::to_string(id)){
        decrementBalance(transaction.getValue());
    }else if(transaction.getReceiver()==std::to_string(id)){
        incrementBalance(transaction.getValue());
    }else{
        std::cout<<"Error: transaction not valid"<<std::endl;
    }
}

void BankAccount::printAccountBalanceAndTransactions() {
    std::cout << "Account id: " << id << std::endl;
    std::cout << "Balance: " << balance << std::endl;
    std::cout << "Transactions: " << std::endl;
    for (Transaction transaction : transactions) {
        std::cout << "Sender: " << transaction.getSender() << std::endl;
        std::cout << "Receiver: " << transaction.getReceiver() << std::endl;
        std::cout << "Value: " << transaction.getValue() << std::endl;
        std::cout << "Description: " << transaction.getDescription() << std::endl;
        std::cout << "Data: " << transaction.getData() << std::endl;
        std::cout << "----------------" << std::endl;
    }
}

void BankAccount::insertTransactionInFile(Transaction transaction) {
    //function that insert transaction inside txt file
    std::ofstream file;
    file.open(filename, std::ios_base::app);
    file<< "{"<<std::endl;
    file<<"from: "<<transaction.getSender()<<std::endl;
    file<<"to: "<<transaction.getReceiver()<<std::endl;
    file<<"value: "<<std::to_string(transaction.getValue())<<std::endl;
    file<<"description: "<<transaction.getDescription()<<std::endl;
    file<<"data: "<<transaction.getData()<<std::endl;
    file<<"}"<<std::endl;
    file.close();
}

void BankAccount::loadTransactionsFromFile() {
    std::ifstream file;
    file.open(filename);
    std::string line;
    while (std::getline(file, line)) {
        if(line.find("{")!=std::string::npos){
            Transaction transaction= *new Transaction();
            while (std::getline(file, line)) {
                if(line.find("from: ")!=std::string::npos){
                    int index = line.find("from: ");
                    std::string fromString = line.substr(index + 6);
                    transaction.setSender(fromString);
                }
                if(line.find("to: ")!=std::string::npos){
                    int index = line.find("to: ");
                    std::string toString = line.substr(index + 4);
                    transaction.setReceiver(toString);
                }
                if(line.find("value: ")!=std::string::npos){
                    int index = line.find("value: ");
                    std::string valueString = line.substr(index + 7);
                    transaction.setValue(std::stof(valueString));
                }
                if(line.find("description: ")!=std::string::npos){
                    int index = line.find("description: ");
                    std::string descriptionString = line.substr(index + 13);
                    transaction.setDescription(descriptionString);
                }
                if(line.find("data: ")!=std::string::npos){
                    int index = line.find("data: ");
                    std::string dataString = line.substr(index + 6);
                    transaction.setData(dataString);
                }
                if(line.find("}")!=std::string::npos){
                    transactions.push_back(transaction);
                    break;
                }
            }
        }
    }

}

bool BankAccount::removeTransactionFromTransactions(Transaction transaction) {
    try{
        transactions.remove(transaction);
        decrementBalance(transaction.getValue());
        return true;
    }
    catch(...){
        std::cout<<"transaction not found"<<std::endl;
        return false;
    }
}

void BankAccount::removeTransactionFromFle(Transaction transaction) {
    std::ifstream file;
    std::ofstream out("outfile.txt");
    file.open(filename);

    std::string line;
    std::string sender;
    std::string receiver;
    std::string value;
    std::string description;
    std::string data;
    std::string line_f;

    bool copy= false;

    //copy intestation of file in outfile
    std::getline(file, line); //first row
    out<<line<<std::endl;

    std::getline(file, line); //second row
    out<<line<<std::endl;

    //copy all transaction except the one to delete
    while(std::getline(file,line)){
        copy=true;

        std::getline(file, sender);
        std::getline(file, receiver);
        std::getline(file, value);
        std::getline(file, description);
        std::getline(file, data);
        std::getline(file, line_f);

        if(sender.find(transaction.getSender())!=std::string::npos){
            if(receiver.find(transaction.getReceiver())!=std::string::npos){
                if(value.find(std::to_string(transaction.getValue()))!=std::string::npos){
                    if(description.find(transaction.getDescription())!=std::string::npos){
                        if(data.find(transaction.getData())!=std::string::npos){
                            copy=false;
                        }
                    }
                }
            }
        }

        if(copy){
            out<<line<<std::endl;
            out<<sender<<std::endl;
            out<<receiver<<std::endl;
            out<<value<<std::endl;
            out<<description<<std::endl;
            out<<data<<std::endl;
            out<<line_f<<std::endl;
        }
    }
    remove(filename.c_str());
    rename("outfile.txt", filename.c_str());
}

void BankAccount::editBalanceInFile() {
    std::ifstream file(filename);
    std::ofstream temp("temp.txt");
    std::string line;
    std::getline(file, line);
    temp <<"Account created with id: "<<id  <<" and balance: "<<balance<< std::endl;
    while (std::getline(file, line)) {
        temp << line << std::endl;
    }
    file.close();
    temp.close();
    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
}

const std::list<Transaction> &BankAccount::getTransactions() const {
    return transactions;
}

bool BankAccount::removeTransaction(Transaction transaction) {
    bool esit=removeTransactionFromTransactions(transaction);
    removeTransactionFromFle(transaction);
    return esit;
}

void BankAccount::editTransaction(Transaction transaction, Transaction newTransaction) {
    if(removeTransaction(transaction)) {
        insertTransaction(newTransaction);
    }
    else{
        std::cout<<"transaction not found"<<std::endl;
    }
}
