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


#endif //ACCOUNT_H
