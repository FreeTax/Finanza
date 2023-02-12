//
// Created by Francesco Mazzola on 12/02/23.
//

#include "Transaction.h"
#include "BankAccount.h"

Transaction::Transaction(int sender, int reciver, float valuse, float balance
    this->sender = sender;
    this->receiver = reciver;
    this->value = valuse;
}

Transaction::~Transaction() {

}

bool Transaction::isValid() {

}
