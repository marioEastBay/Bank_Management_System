//
// Created by Mario O Salinas on 9/29/23.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H


class Account {
private:
    float balance;
public:
    Account();
    void DepositFunds(float);
    void WithdrawFunds(float);
    float GetBalance();
};


Account::Account() {
    balance = 0;
}

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

#endif //ACCOUNT_H
