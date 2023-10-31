//
// Created by Mario O Salinas on 9/30/23.
//

#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
private:
    string username;
    string password;
    string address;
    int socialSecurityNumber;
public:
    User();
    void PutUsername(string);
    void PutPassword(string);
    void PutAddress(string);
    void PutSocialSecurityNum(int);
    string GetUsername();
    string GetPassword();
    string GetAddress();
    int GetSocialSecurityNum();
};



User::User() {
    username = " ";
    password = " ";
    address = " ";
    socialSecurityNumber = 0;
}

void User::PutUsername(string uName) {
    username = uName;
}

void User::PutPassword(string pw) {
    password = pw;
}

void User::PutAddress(string userAddress) {
    address = userAddress;
}

void User::PutSocialSecurityNum(int ssn) {
    socialSecurityNumber = ssn;
}

string User::GetUsername() {
    return username;
}

string User::GetPassword() {
    return password;
}

string User::GetAddress() {
    return address;
}

int User::GetSocialSecurityNum() {
    return socialSecurityNumber;
}


#endif //BANK_MANAGEMENT_SYSTEM_USER_H
