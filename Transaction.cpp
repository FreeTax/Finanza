//
// Created by Francesco Mazzola on 12/02/23.
//

#include "Transaction.h"

Transaction::Transaction(const std::string &sender, const std::string &receiver, float value,
                         const std::string &description, const std::string &data) : sender(sender), receiver(receiver),
                                                                                    value(value),
                                                                                    description(description),
                                                                                    data(data) {}

Transaction::~Transaction() {

}

Transaction::Transaction() {}

std::string Transaction::toString() {
    std::string transactionString;
    transactionString = "Sender: " + sender + " Receiver: " + receiver + " Value: " + std::to_string(value) +
                        " Description: " + description + " Data: " + data;
    return transactionString;
}

const std::string &Transaction::getSender() const {
    return sender;
}

void Transaction::setSender(const std::string &sender) {
    Transaction::sender = sender;
}

const std::string &Transaction::getReceiver() const {
    return receiver;
}

void Transaction::setReceiver(const std::string &receiver) {
    Transaction::receiver = receiver;
}

float Transaction::getValue() const {
    return value;
}

void Transaction::setValue(float value) {
    Transaction::value = value;
}

const std::string &Transaction::getDescription() const {
    return description;
}

void Transaction::setDescription(const std::string &description) {
    Transaction::description = description;
}

const std::string &Transaction::getData() const {
    return data;
}

void Transaction::setData(const std::string &data) {
    Transaction::data = data;
}

bool Transaction::operator==(const Transaction &rhs) const {
    return sender == rhs.sender &&
           receiver == rhs.receiver &&
           value == rhs.value &&
           description == rhs.description &&
           data == rhs.data;
}

bool Transaction::operator!=(const Transaction &rhs) const {
    return !(rhs == *this);
}



