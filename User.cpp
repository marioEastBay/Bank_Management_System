//
// Created by Mario O Salinas on 9/30/23.
//


#include <string>
using namespace std;

#include "User.h"

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