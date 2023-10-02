//
//
//
//
//

#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

#include "Account.h"
#include "User.h"

bool check_if_input_is_int (int);


int main() {
    string inputFileName, outputFileName;
    ifstream inputFile;
    ofstream outputFile;
    int displayCommandMenu;
    char mainMenuCommand = 'I';     // initialize variable with a dummy value
    char command = 'I';             // initialize command variable with a dummy value

    Account account;                // this is a temporary Account object. will be changed once
                                    // a file input output stream is created

    cout << "Enter the name of the input file (hint: it's input.txt): ";
    cin >> inputFileName;
    inputFile.open(inputFileName.c_str());

    cout << "Enter the name of the output file (hint: it's output.txt): ";
    cin >> outputFileName;
    outputFile.open(outputFileName.c_str());

    if (!inputFile.good()) {
        cout << "I/O error. Can't find the input file! \n";
        exit(2);
    }

    cout << "*** Welcome to Pioneer Bank. ***" << endl;
    cout << "L: Login" << endl
    << "N: Create a New Account." << endl
    << "Q: Quit." << endl
    << "Enter a command to proceed: ";
    cin  >> mainMenuCommand;

    switch(mainMenuCommand) {
        case 'L':
        case 'l': {
            string username;
            string password;

           User user;

            cout << "Please enter your user information." << endl;
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

            user.PutUsername(username);
            user.PutPassword(password);

            // allow user to enter the command menu below
            displayCommandMenu = 1;
            break;
        }
        case 'N':
        case 'n': {
            int informationIsVerified = 1;

            while (informationIsVerified != 0) {
                string username;
                string password;
                string address;
                int socialSecurityNumber;

                User newUser;
                cout << "Please enter your user information." << endl;
                cout << "Select a username: ";
                cin >> username;
                cout << "Select a password: ";
                cin >> password;
                cout << "Enter your address: ";
                cin >> address;
                cout << "Enter your Social Security Number: ";
                cin >> socialSecurityNumber;

                newUser.PutUsername(username);
                newUser.PutPassword(password);
                newUser.PutAddress(address);
                newUser.PutSocialSecurityNum(socialSecurityNumber);

                cout << "You have entered the following information: " << endl
                     << "Username: " << newUser.GetUsername() << endl
                     // NOTE TO SELF: create a feature that turns PW characters
                     // into asterisks
                     << "Password: " << newUser.GetPassword() << endl
                     << "Address: " << newUser.GetAddress() << endl
                     << "Social Security Number: " << newUser.GetSocialSecurityNum() << endl
                     << "Is this information correct? Enter 1 if yes. Enter 0 if no: ";
                cin >> informationIsVerified;

                if (informationIsVerified == 0) {
                    cout << "You have entered incorrect user information." << endl;
                } else if (informationIsVerified == 1) {
                    cout << "You have created a new account." << endl;
                }
            }
            displayCommandMenu = 1;
            break;
        }
        case 'Q':
        case 'q':
            cout << endl << "Thank you for choosing Pioneer Bank. Program will now close." << endl;
            displayCommandMenu = 0;
            break;
    }

    while (displayCommandMenu != 0) {
        // Create a command menu
        cout << "*** Welcome to your bank management system. ***" << endl
        << "D: Deposit Funds. " << endl
        << "W: Withdraw Funds. " << endl
        << "B: Check your account balance." << endl
        << "C: Card Settings." << endl
        << "Q: Quit." << endl
        << "Enter a command to proceed: ";
        cin >> command;


        switch (command) {
            case 'D':
            case 'd': {
                cout << "*** YOU HAVE SELECTED TO DEPOSIT FUNDS OPTION***" << endl;

                float depositAmount;
                bool isValidated = false;
                bool isInt = true;

                // FIX THIS WHILE LOOP
                while (!isValidated) {
                    cout << "Enter the amount that you would like to deposit: ";
                    cin >> depositAmount;
                    // make sure that input is of type int
                    isInt = check_if_input_is_int(depositAmount);
                    if (isInt == false) {
                        cout << "Invalid input. Please try again." << endl;
                        isValidated = false;
                    } else if (isInt == true) {
                        isValidated = true;
                    }
                }

                account.DepositFunds(depositAmount);

                cout << "$" << depositAmount << " has been deposited into your bank account." << endl;
                cout << "Your new account balance is: $" << account.GetBalance() << endl << endl;
                cout << "Return to the command menu? Enter 1 if yes. Enter 0 if no: ";
                cin >> displayCommandMenu;
                break;
            }
            case 'W':
            case 'w':
                float withdrawAmount;
                cout << "*** YOU HAVE SELECTED TO WITHDRAW FUNDS OPTION***" << endl;

                cout << "Enter the amount that you would like to withdraw: ";
                cin >> withdrawAmount;
                account.WithdrawFunds(withdrawAmount);

                cout << "$" << withdrawAmount << " has been withdrawn from your account." << endl;
                cout << "Your new account balance is: $" << account.GetBalance() << endl << endl;
                cout << "Return to the command menu? Enter 1 if yes. Enter 0 if no: ";
                cin >> displayCommandMenu;
                break;
            case 'B':
            case 'b':
                cout << "*** YOU HAVE SELECTED TO CHECK YOUR ACCOUNT BALANCE ***" << endl;

                cout << "Your account balance is: " << account.GetBalance() << endl << endl;

                cout << "Return to the command menu? Enter 1 if yes. Enter 0 if no: ";
                cin >> displayCommandMenu;
                break;
            case 'C':
            case 'c': {
                cout << "*** YOU HAVE SELECTED TO EDIT YOUR CARD SETTINGS ***" << endl << endl;

                char cardMenuCommand = 'I'; // initialize variable with a dummy value

                cout << "T: Turn card On or Off" << endl
                     << "R: Replace My Card" << endl
                     << "A: Activate Card" << endl
                     << "Q: Quit" << endl
                     << "Enter a command to proceed: ";
                cin >> cardMenuCommand;

                switch (cardMenuCommand) {
                    case 'T':
                    case 't': {
                        User user;

                        cout << "*** YOU HAVE SELECTED TO TURN YOUR CARD ON OR OFF ***" << endl;
                        int tempSSN;

                        // NOTE TO SELF: enhance this feature in the future by prompting the user
                        // to enter only the last four digits of a social security number
                        cout << "To proceed, please verify your social security number: ";
                        cin >> tempSSN;

                        int ssn = user.GetSocialSecurityNum();

                        if (tempSSN == ssn) {
                            cout << " " << endl;
                        } else {
                            cout << "Incorrect social security number. Please try again." << endl;
                        }


                        break;
                    }
                    case 'R':
                    case 'r':
                        break;
                    case 'A':
                    case 'a':
                        break;
                    case 'Q':
                    case 'q':
                        break;
                }

                break;
            }
            case 'Q':
            case 'q':
                displayCommandMenu = 0;
                break;
        }
    }

    cout << endl << "Thank you for banking with Pioneer Bank." << endl;
    return 0;
}


bool check_if_input_is_int (int input) {
        if (isdigit(input) == false)
            return false;
    return true;
}