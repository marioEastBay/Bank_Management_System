//
// Created by Mario O Salinas on 9/29/23.
//

#include <iostream>
using namespace std;

#include "Account.h"

void Account::DepositFunds(float amount) {
    balance += amount;
}

void Account::WithdrawFunds(float amount) {
    if (balance < amount) {
        throw "Insufficient funds in your account.";
    } else {
        balance -= amount;
    }
}

float Account::GetBalance() {
    return balance;
}