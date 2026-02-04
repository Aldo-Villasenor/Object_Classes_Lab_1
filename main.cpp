/*
 *Author: Aldo Villasenor
 *Date: 1/30/26
 *Purpose: Bank Account Management System
 */
#include <iostream>
#include <vector>
#include "BankAccount.h"

int main() {
   std::vector<BankAccount> accounts;
    int choice = 0;

    while (choice !=5) { //Implements a menu to make a new account to deposit or withdraw money
        std::cout << "1. Add New Account\n";
        std::cout << "2. View Account\n";
        std::cout << "3. Update Account\n";
        std::cout << "4. Deposit/Withdraw\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter Choice: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::string discard; std::cin >>discard;
            continue;
        }
        if (choice == 1) { //Asks the user to make an account with their name and amount added to the account
            std::string accountName;
            double initialBal;

            std::cout << "Enter Account Holder Name: "; std::cin.ignore(); std::getline(std::cin, accountName);
            std::cout << "Enter initial Balance: "; std::cin >> initialBal;

            accounts.push_back(BankAccount(accountName, initialBal));
            std::cout << "Account added.\n";
        }
        else if (choice == 2) {
            if (accounts.empty()) { //Ensures an account is accessible and displays their name and balance
                std::cout << "No accounts added.\n";
            } else {
                for (size_t i = 0; i < accounts.size(); i++) {
                    std::cout << " | Name: " << accounts[i].getAccountHolderName()
                    << " | Balance: $" << accounts[i].getBalance() << "\n";
                }
            }
        }
        else if (choice == 3) { //Prompts the user to change their account name if necessary
            if (accounts.empty()) {
                std::cout << "No accounts added.\n";
            } else {
                std::string newName;
                std::cout << "Enter new account Name: ";
                std::cin.ignore(); std::getline(std::cin, newName);
                accounts.back().setAccountHolderName(newName);
            }
        }
        else if (choice == 4) { //Offers the option to add or take away money from the account added
            if (accounts.empty()) {
                std::cout << "No accounts added.\n";
            } else {
                double amount;
                std::cout << "1. Deposit\n2. Withdraw\n Enter Choice: ";
                int option; std::cin >> option;
                std::cout << "Amount: "; std::cin >> amount;

                if (option == 1) accounts.back().deposit(amount); //Ensures no money can be taken if none is available
                else if (!accounts.back().withdraw(amount)) std::cout << "Not Enough Funds.\n";
            }
        }
    } 
    return 0;
}