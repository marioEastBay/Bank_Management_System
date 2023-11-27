//
//
//

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;

#include "Account.h"
#include "User.h"

int main() {
    string inputFileName, outputFileName;
    ifstream inputFile;
    ofstream outputFile;
    int displayCommandMenu;
    char mainMenuCommand = 'I';     // initialize variable with a dummy value
    char command = 'I';             // initialize command variable with a dummy value

    Account account;                // this is a temporary Account object. will be changed once
                                    // a file input output stream is created

    User user;      // create an instance of a user

    cout << "*** Welcome to Pioneer Bank. ***" << endl;
    cout << "L: Login" << endl
    << "N: Create a New Account." << endl
    << "Q: Quit." << endl
    << "Enter a command to proceed: ";
    cin  >> mainMenuCommand;

    switch(mainMenuCommand) {
        case 'L':
        case 'l': {
            // open Accounts file
            const char* inFile = "Users.dat";
            ifstream file(inFile, ios::in);

            if (!file.is_open()) {
                cerr << "Failed to open the Users.dat file." << endl;
            }

            string username;
            string password;
            bool promptUser = 1;

            while (promptUser == 1) {
                cout << "Please enter your user information." << endl;
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;

                user.PutUsername(username);
                user.PutPassword(password);

                account.SetUsername(username);

                string usernameLine;
                string passwordLine;
                int lineNumber = 0;
                string targetUsername = username;
                string targetPassword = password;
                // search Users.dat for username
                while (getline(file, usernameLine)) {
                    lineNumber++;
                    // Search for the target word in the line
                    size_t pos = usernameLine.find(targetUsername);

                    if (pos != string::npos) {
                        promptUser = 0;
                        //cout << "Found at line " << lineNumber << ", position " << pos << ": " << usernameLine << endl;
                        break;
                    } else {
                        break;
                    }
                }
                // search Users.dat for password
                while (getline(file, passwordLine)) {
                    lineNumber++;
                    // Search for the target word in the line
                    size_t pos = passwordLine.find(targetPassword);

                    if (pos != string::npos) {
                        promptUser = 0;
                        //cout << "Found at line " << lineNumber << ", position " << pos << ": " << passwordLine << endl;
                        break;
                    } else {
                        //cout << "Incorrect password. Please try again." << endl;
                        break;
                    }
                }
            }

            file.close();
            // continue to the command menu
            displayCommandMenu = 1;
            break;
        }
        case 'N':
        case 'n': {
            // open Accounts file
            const char* inFile = "Users.dat";
            ofstream file(inFile, ios::app);

            if (!file.is_open()) {
                cerr << "Failed to open the AccountsInput file." << endl;
            }

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

                file << username << " " << password << " " << address << " " <<
                socialSecurityNumber << endl;

                user.PutUsername(username);
                user.PutPassword(password);
                user.PutAddress(address);
                user.PutSocialSecurityNum(socialSecurityNumber);

                cout << "You have entered the following information: " << endl
                     << "Username: " << username << endl
                     // NOTE TO SELF: create a feature that turns PW characters
                     // into asterisks
                     << "Password: " << password << endl
                     << "Address: " << address << endl
                     << "Social Security Number: " << socialSecurityNumber << endl
                     << "Is this information correct? Enter 1 if yes. Enter 0 if no: ";
                cin >> informationIsVerified;

                if (informationIsVerified == 0) {
                    cout << "You have entered incorrect user information." << endl;
                } else if (informationIsVerified == 1) {
                    cout << "You have created a new account." << endl;
                    informationIsVerified = 0;
                }
            }

            file.close();
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
        cout << endl << "*** PIONEER BANK ***" << endl
        << "Welcome, " << user.GetUsername() << "." << endl
        << "What would you like to do today?" << endl
        << "D: Deposit Funds. " << endl
        << "W: Withdraw Funds. " << endl
        << "B: Check your account balance." << endl
        << "C: Card Settings." << endl
        << "L: Apply for a Loan." << endl
        << "Q: Quit." << endl
        << "Enter a command to proceed: ";
        cin >> command;


        switch (command) {
            case 'D':
            case 'd': {
                cout << "*** YOU HAVE SELECTED TO DEPOSIT FUNDS ***" << endl;

                float depositAmount;

                // verify that user has entered a value that is of data type int or float
                for (;;) {
                    cout << "Enter the amount that you would like to deposit: ";
                    if (cin >> depositAmount)
                        break;
                    else {
                        cout << "Please enter a valid value." << endl;
                        cin.clear();
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
            case 'w': {
                float withdrawAmount;
                cout << "*** YOU HAVE SELECTED THE WITHDRAW FUNDS OPTION***" << endl;


                cout << "Enter the amount that you would like to withdraw: ";
                cin >> withdrawAmount;

                account.WithdrawFunds(withdrawAmount);

                cout << "$" << withdrawAmount << " has been withdrawn from your account." << endl;
                cout << "Your new account balance is: $" << account.GetBalance() << endl << endl;
                cout << "Return to the command menu? Enter 1 if yes. Enter 0 if no: ";
                cin >> displayCommandMenu;
                break;
            }
            case 'B':
            case 'b':
                cout << "*** YOU HAVE SELECTED TO CHECK YOUR ACCOUNT BALANCE ***" << endl;

                cout << "Your account balance is: $" << account.GetBalance() << endl << endl;

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
                        bool cardIsOn = user.GetCardIsOn();

                        if (tempSSN == ssn) {
                            cout << " " << endl;
                        } else {
                            cout << "Incorrect social security number. Please try again." << endl;
                        }

                        int cardCommand;

                        if (cardIsOn == true) {
                            cout << "Your card is on. "
                                 << "Would you like to turn off your card? (1 = yes / 0 = no): " << endl;
                            cin >> cardCommand;
                            if (cardCommand == 1) {
                                cout << "Your card has been turned off." << endl;
                                cardIsOn = false;
                            } else {
                                cout << "No changes have been made to your card and your card is still on." << endl;
                                cardIsOn = true;
                            }
                        } else {
                            cout << "Your card is off."
                                 << "Would you like to turn on your card? (1 = yes / 0 = no): " << endl;
                            cin >> cardCommand;
                            if (cardCommand == 1) {
                                cout << "Your card has been turned on." << endl;
                                cardIsOn = true;
                            } else {
                                cout << "No changes have been made to your card and your card is still off." << endl;
                                cardIsOn = false;
                            }
                        }

                        user.ChangeCardIsOn(cardIsOn);

                        break;
                    }
                    case 'R':
                    case 'r': {
                        cout << "*** YOU HAVE SELECTED THE REPLACE MY CARD OPTION ***" << endl;

                        string address = user.GetAddress();
                        string verifyAddress;
                        bool rightAddress = true;
                        int requestNewCard;

                        while (rightAddress) {

                            cout << "Verify your address to continue: " << endl;
                            cin >> verifyAddress;

                            if (verifyAddress == address) {
                                cout << "Wrong address. Please enter the correct address. " << endl;
                                rightAddress = true;
                            } else {
                                rightAddress = false;
                            }
                        }

                        cout << "You have requested that a new card be sent to your address on file. "
                        << "Are you sure you want a new card? (1 = yes / 0 = no): ";
                        cin >> requestNewCard;

                        if (requestNewCard = 1) {
                            cout << "A new card has been sent to your address. " << endl;
                        } else {
                            cout << "Request for a new card has been canceled." << endl;
                        }

                        break;
                    }
                    case 'A':
                    case 'a': {
                        cout << "*** YOU HAVE CHOSEN THE ACTIVATE YOUR CARD OPTION. ***" << endl;

                        int numTurnOnCard;
                        int tempSSN;

                        cout << "To proceed, please verify your social security number: ";
                        cin >> tempSSN;

                        cout << "Enter your card verification number: ";
                        cin >> numTurnOnCard;

                        cout << "Your card has been successfully activated. " << endl;

                        break;
                    }
                    case 'Q':
                    case 'q':
                        break;
                }
                break;
            }
            case 'L':
            case 'l':
                cout << "*** YOU HAVE SELECTED THE APPLY FOR A LOAN OPTION ***" << endl;

                int tempSSN;
                int income;
                int rentOrMortgage;
                int creditScore;
                bool isCitizen;
                int loanAmount;


                cout << "To proceed, please verify your social security number: ";
                cin >> tempSSN;

                cout << "Enter your desired loan amount: ";
                cin >> loanAmount;
                cout << "Are you a US Citizen? (1 = yes / 0 = no): " ;
                cin >> isCitizen;
                cout << "Enter your annual income: ";
                cin >> income;
                cout << "Enter your credit score: ";
                cin >> creditScore;
                cout << "Enter your monthly rent or mortgage: ";
                cin >> rentOrMortgage;

                cout << "Determining your eligibility for a $" << loanAmount << " loan..." << endl << endl;

                cout << "Congratulations! You have been approved for a loan of " << loanAmount << "!" << endl;

                account.DepositFunds(loanAmount);

                cout << "Your loan amount has been deposited into your account." << endl;

                break;
            case 'Q':
            case 'q':
                displayCommandMenu = 0;
                break;
        }
    }

    cout << endl << "You have chosen to exit the program. Thank you for choosing Pioneer Bank." << endl;
    return 0;
}

