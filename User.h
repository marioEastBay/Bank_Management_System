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


#endif //BANK_MANAGEMENT_SYSTEM_USER_H
