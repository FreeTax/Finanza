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

void BankAccount::makeTransaction(BankAccount *receiver, float value, std::string description, std::string data) {
    if (balance >= value) {
        balance -= value;
        Transaction transaction(std::to_string(id), std::to_string(receiver->getId()), value, description, data);
        receiver->receiveTransaction(this, value, transaction);
        addTransaction(transaction);
        std::string dataString="transaction made to the user: "+std::to_string(receiver->getId())+" with value: "+std::to_string(value)+" and balance: "+std::to_string(balance);
    } else {
        std::cout << "Not enough money" << std::endl;
    }
}

void BankAccount::addTransaction(Transaction transaction) {
    transactions.push_back(transaction);
    insertTransaction(transaction);
}

void BankAccount::receiveTransaction(BankAccount *sender, float value, Transaction transaction) {
    balance += value;
    addTransaction(transaction);
    std::string dataString="transaction received from the user: "+std::to_string(sender->getId())+" with value: "+std::to_string(value)+" and balance: "+std::to_string(balance);
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

void BankAccount::insertTransaction(Transaction transaction) {
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

void BankAccount::removeTransaction(Transaction transaction) {
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
        else{
            sender=sender.substr(6);
            receiver=receiver.substr(4);
            value=value.substr(7);
            description=description.substr(13);
            data=data.substr(6);
            Transaction transaction= *new Transaction(sender, receiver, std::stof(value), description, data);
            try {
                transactions.remove(transaction);
                removeBalance(transaction);
            } catch (std::exception e) {
                std::cout<<"error"<<std::endl;
                std::cout<<e.what()<<std::endl;
            }
        }
    }
    remove(filename.c_str());
    rename("outfile.txt", filename.c_str());
}

void BankAccount::removeBalance(Transaction transaction) {
    if(transaction.getSender().find(id)!=std::string::npos){ //case that i am the sender: i increment my balance and decrement the receiver balance
        balance+=transaction.getValue();
        BankAccount *receiver= new BankAccount(std::stoi(transaction.getReceiver()));
        receiver->decrementBalance(transaction.getValue());
    }
    else{ //case that i am the receiver: i decrement my balance and increment the sender balance
        balance-=transaction.getValue();
        BankAccount *sender= new BankAccount(std::stoi(transaction.getSender()));
        sender->incrementBalance(transaction.getValue());
    }
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


