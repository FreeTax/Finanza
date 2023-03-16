//
// Created by Francesco Mazzola on 16/03/23.
//

#include "../BankAccount.h"
#include "gtest/gtest.h"
#include <IOSTREAM>

TEST(BankAccount, incrementBalance){
    BankAccount *b;
    b=new BankAccount();
    b->incrementBalance(105.8);
    EXPECT_FLOAT_EQ(b->getBalance(), 105.8); //for float comparison use EXPECT_FLOAT_EQ because EXPECT_EQ dosent work
}

