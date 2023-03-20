//
// Created by Francesco Mazzola on 20/03/23.
//

#include "IOFile.h"


IOFile::IOFile(int id) : id(id){
    filename=std::to_string(id);
    filename = filename + ".txt";
}

IOFile::IOFile() {}

IOFile::~IOFile() {

}

float IOFile::getBalanceFromFile() {
    float balance;
    std::ifstream file;
    file.open(filename);
    if(!file.is_open()){
        balance = 0.00;
        std::cout << id<<" is a new user" << std::endl;
        std::string dataString="Account created with id: "+std::to_string(id)+" and balance: "+std::to_string(balance);
        saveToFile(dataString);
    }
    else{
        std::cout << id<<" is an old user" << std::endl;
        std::string line;
        std::string old;
        while (std::getline(file, line)) {
            old = line;
        }
        int index = old.find("balance: ");
        std::string balanceString = old.substr(index + 9);
        balance = std::stof(balanceString);
        file.close();
    }
    return balance;
}

void IOFile::saveToFile(std::string data) {
    std::ofstream file;
    file.open(filename, std::ios_base::app);
    file << data << std::endl;
    file.close();
}

void IOFile::printAccountBalnceAndTransactions() {
    std::ifstream file;
    file.open(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
}



