//
// Created by Mario O Salinas on 9/29/23.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H


class Account {
private:
    float balance;
    string userName;
public:
    Account();
    void SetUsername(string);
    string GetUsername(string);
    void DepositFunds(float);
    void WithdrawFunds(float);
    float GetBalance();
};


Account::Account() {
    balance = 0;
    userName = " ";
}

void Account::SetUsername(string uName) {
    userName = uName;
}

string Account::GetUsername(string) {
    return userName;
}

void Account::DepositFunds(float amount) {
    balance += amount;
}

void Account::WithdrawFunds(float amount) {
    balance -= amount;

}

float Account::GetBalance() {
    return balance;
}

#endif //ACCOUNT_H
