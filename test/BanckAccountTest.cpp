//
// Created by Francesco Mazzola on 16/03/23.
//

#include "../BankAccount.h"
#include "gtest/gtest.h"
#include <stdio.h>

TEST(BankAccountTest, testGetBalance) {
    remove("-1.txt");
    BankAccount bankAccount(-1);
    EXPECT_EQ(0, bankAccount.getBalance());
    remove("-1.txt");
}

TEST(BankAccountTest, testGetId) {
    remove("-1.txt");
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
    remove("-1.txt");
    BankAccount bankAccount(-1);
    bankAccount.incrementBalance(10);
    bankAccount.decrementBalance(5);
    EXPECT_EQ(5, bankAccount.getBalance());
    remove("-1.txt");
}

TEST(BankAccountTest, testInsertTransaction) {
    remove("-1.txt");
    BankAccount bankAccount(-1);
    Transaction transaction("sender", "receiver", 10, "description", "date");
    bankAccount.insertTransaction(transaction);
    EXPECT_EQ(1, bankAccount.getTransactions().size());
    remove("-1.txt");
}

TEST(BankAccountTest, testRemoveTransaction) {
    remove("-1.txt");
    BankAccount bankAccount(-1);
    Transaction transaction("sender", "receiver", 10, "description", "date");
    bankAccount.insertTransaction(transaction);
    bankAccount.removeTransaction(transaction);
    EXPECT_EQ(0, bankAccount.getTransactions().size());
    remove("-1.txt");
}

TEST(BankAccountTest, testEditTransaction) {
    remove("-1.txt");
    BankAccount bankAccount(-1);
    Transaction transaction("sender", "receiver", 10, "description", "date");
    bankAccount.insertTransaction(transaction);
    Transaction newTransaction("sender1", "receiver2", 10, "description", "date");
    bankAccount.editTransaction(transaction, newTransaction);
    EXPECT_EQ(1, bankAccount.getTransactions().size());
    EXPECT_TRUE(bankAccount.getTransactions().front().getSender() == "sender1");
    EXPECT_TRUE(bankAccount.getTransactions().front().getReceiver() == "receiver2");
    EXPECT_TRUE(bankAccount.getTransactions().front().getDescription() == "description");
    EXPECT_TRUE(bankAccount.getTransactions().front().getData() == "date");
    EXPECT_EQ(10, bankAccount.getTransactions().front().getValue());
    remove("-1.txt");
}