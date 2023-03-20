//
// Created by Francesco Mazzola on 20/03/23.
//

#ifndef FINANZA_IOFILE_H
#define FINANZA_IOFILE_H

#endif //FINANZA_IOFILE_H
#include <fstream>
#include <iostream>

class IOFile {
public:
    IOFile();

    IOFile(int id);

    virtual ~IOFile();

    float getBalanceFromFile();

    void saveToFile(std::string data);

    void printAccountBalnceAndTransactions();

private:
    int id;
    std::string filename;

};
