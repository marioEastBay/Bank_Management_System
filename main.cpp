//
//
//
//
//

#include <iostream>
#include <fstream>
using namespace std;

#include "Account.h"

int main() {
    string inputFileName, outputFileName;
    ifstream inputFile;
    ofstream outputFile;
    int displayCommandMenu = 1;
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

    while (displayCommandMenu != 0) {
        // Create a command menu
        cout << "*** Welcome to your bank management system. ***" << endl
        << "D: Deposit Funds. " << endl
        << "W: Withdraw Funds. " << endl
        << "B: Check your account balance." << endl
        << "Q: Quit." << endl
        << "Enter a command to proceed: ";
        cin >> command;


        switch (command) {
            case 'D':
            case 'd':
                cout << "*** YOU HAVE SELECTED THE DEPOSIT FUNDS OPTION***" << endl;

                float depositAmount;
                cout << "Enter the amount that you would like to deposit: ";
                cin >> depositAmount;
                account.DepositFunds(depositAmount);

                cout << "$" << depositAmount << " has been deposited into your bank account." << endl;
                cout << "Your new account balance is: $" << account.GetBalance() << endl << endl;
                cout << "Return to the command menu? Enter 1 if yes. Enter 0 if no: ";
                cin >> displayCommandMenu;
                break;
            case 'W':
            case 'w':
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
            case 'B':
            case 'b':
                cout << "*** YOU HAVE SELECTED TO CHECK YOUR ACCOUNT BALANCE***" << endl;

                cout << "Your account balance is: " << account.GetBalance() << endl << endl;

                cout << "Return to the command menu? Enter 1 if yes. Enter 0 if no: ";
                cin >> displayCommandMenu;
                break;
        }
    }

    cout << "Thank you for banking with Pioneer Bank." << endl;
    return 0;
}
