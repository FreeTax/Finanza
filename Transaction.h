//
// Created by Francesco Mazzola on 12/02/23.
//

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <unistd.h>
#include <cstdlib>
#include "string"


class Transaction {

public:
    Transaction(const std::string &sender, const std::string &receiver, float value, const std::string &description,
                const std::string &data);

    Transaction();

    virtual ~Transaction();

    const std::string &getSender() const;

    void setSender(const std::string &sender);

    const std::string &getReceiver() const;

    void setReceiver(const std::string &receiver);

    float getValue() const;

    void setValue(float value);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    const std::string &getData() const;

    void setData(const std::string &data);

    std::string toString();

    bool operator==(const Transaction &rhs) const;

    bool operator!=(const Transaction &rhs) const;


private:
    std::string sender;
    std::string receiver;
    float value;
    std::string description;
    std::string data;
};
#endif