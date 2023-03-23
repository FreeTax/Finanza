//
// Created by Francesco Mazzola on 23/03/23.
//
#include "gtest/gtest.h"
#include "../IOFile.h"

TEST(IOFile, getBalanceFromFile) {
    IOFile *io;
    io = new IOFile(-1);
    io->saveToFile("balance: 100");
    EXPECT_FLOAT_EQ(io->getBalanceFromFile(), 100);
    remove("-1.txt"); //remove the file if it exists
}


