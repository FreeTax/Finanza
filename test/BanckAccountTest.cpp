//
// Created by Francesco Mazzola on 16/03/23.
//

#include "../BankAccount.h"
#include "gtest/gtest.h"
#include <stdio.h>

TEST(BankAccountTest, testGetBalance) {
    BankAccount bankAccount(-1);
    EXPECT_EQ(0, bankAccount.getBalance());
    remove("-1.txt");
}

TEST(BankAccountTest, testGetId) {
    BankAccount bankAccount(-1);
    EXPECT_EQ(-1, bankAccount.getId());
    remove("-1.txt");
}

TEST(BankAccountTest, testIncrementBalance) {
    BankAccount bankAccount(-1);
    bankAccount.incrementBalance(10);
    EXPECT_EQ(10, bankAccount.getBalance());
    remove("-1.txt");
}

TEST(BankAccountTest, testDecrementBalance) {
    BankAccount bankAccount(-1);
    bankAccount.incrementBalance(10);
    bankAccount.decrementBalance(5);
    EXPECT_EQ(5, bankAccount.getBalance());
    remove("-1.txt");
}

TEST(BankAccountTest, testMakeTransaction) {
    BankAccount bankAccount1(-1);
    BankAccount bankAccount2(-2);
    bankAccount1.incrementBalance(10);
    bankAccount1.makeTransaction(&bankAccount2, 5, "test", "13/02/2021");
    EXPECT_EQ(5, bankAccount1.getBalance());
    EXPECT_EQ(5, bankAccount2.getBalance());
    remove("-1.txt");
    remove("-2.txt");
}

TEST(BankAccountTest, removeTransaction){
    BankAccount bankAccount1(-1);
    BankAccount bankAccount2(-2);
    bankAccount1.incrementBalance(10);
    bankAccount1.makeTransaction(&bankAccount2, 5, "test", "13/02/2021");
    bankAccount1.removeTransaction(*new Transaction(std::to_string(-1), std::to_string(-2), 5, "test", "13/02/2021"));
    EXPECT_EQ(10, bankAccount1.getBalance());
    EXPECT_EQ(0, bankAccount2.getBalance());
    EXPECT_EQ(0, bankAccount1.getTransactions().size());
    remove("-1.txt");
    remove("-2.txt");
}
