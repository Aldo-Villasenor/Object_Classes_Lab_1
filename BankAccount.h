//
// Created by aldov on 1/30/2026.
//

#ifndef OBJECT_CLASSES_LAB_BANKACCOUNT_H
#define OBJECT_CLASSES_LAB_BANKACCOUNT_H
#include <iostream>


class BankAccount {
private:
    std::string accountHolderName;
    double balance;

public:

    BankAccount() :  accountHolderName("Unknown"), balance(0.0) {}

    BankAccount(std::string accountName, double bal)
        : accountHolderName(accountName), balance(bal) {}

    std::string getAccountHolderName() const { return accountHolderName; }
    double getBalance() const { return balance; }

    void setAccountHolderName(std::string accountName) { this->accountHolderName = accountName; }

    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }
};

#endif //OBJECT_CLASSES_LAB_BANKACCOUNT_H