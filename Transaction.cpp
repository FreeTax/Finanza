//
// Created by Francesco Mazzola on 12/02/23.
//

#include "Transaction.h"
#include "BankAccount.h"

Transaction::Transaction(BankAccount *sender, BankAccount *receiver, float value) : sender(sender), receiver(receiver),
                                                                                    value(value) {}

Transaction::~Transaction() {

}


bool Transaction::isValid() {
    if (sender->getBalance() >= value) {
        return true;
    } else {
        return false;
    }
}


bool Transaction::makeTransaction() {
    if (isValid()) {
        sleep(random() % 10);
        sender->decrementBalance(value);
        receiver->incrementBalance(value);
        return true;
    } else {
        return false;
    }
}

