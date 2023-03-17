//
// Created by Francesco Mazzola on 16/03/23.
//

#include "../BankAccount.h"
#include "gtest/gtest.h"
#include <IOSTREAM>

TEST(BankAccount, incrementBalance){ //test for testing the incrementBalance method
    BankAccount *b;
    b=new BankAccount(0);
    b->incrementBalance(105.8);
    EXPECT_FLOAT_EQ(b->getBalance(), 105.8); //for float comparison use EXPECT_FLOAT_EQ because EXPECT_EQ dosent work
}
TEST(BankAccount, decrementBalance){ //test for testing the decrementBalance method
    BankAccount *b;
    b=new BankAccount(0);
    b->incrementBalance(105.8);
    b->decrementBalance(105.8);
    EXPECT_FLOAT_EQ(b->getBalance(), 0);
}

TEST(BankAccount, makeTransaction){ //test for testing the transaction method
    BankAccount *b1;
    BankAccount *b2;
    b1=new BankAccount(0);
    b2=new BankAccount(1);
    b1->incrementBalance(105.8);
    b1->makeTransaction(b2, 105.8);
    EXPECT_FLOAT_EQ(b1->getBalance(), 0);
    EXPECT_FLOAT_EQ(b2->getBalance(), 105.8);
}

