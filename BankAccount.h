#ifndef OPERATOR_OVERLOAD_LAB_BANKACCOUNT_H
#define OPERATOR_OVERLOAD_LAB_BANKACCOUNT_H

#include <string>

class BankAccount {
private:
    std::string accountNumber;
    std::string* accountHolderName;
    double balance;

public:
    // Constructors
    BankAccount();
    BankAccount(std::string accountNumber,
                std::string accountHolderName,
                double balance);

    // Rule of Three
    BankAccount(const BankAccount& other);
    BankAccount& operator=(const BankAccount& other);
    ~BankAccount();

    // Getters
    std::string getAccountNumber() const;
    std::string getAccountHolderName() const;
    double getBalance() const;

    // Existing functions
    void deposit(double amount);
    bool withdraw(double amount);

    // Arithmetic assignment operators
    BankAccount& operator+=(double amount);
    BankAccount& operator-=(double amount);

    // Comparison operators
    bool operator==(const BankAccount& other) const;
    bool operator<(const BankAccount& other) const;
    bool operator>(const BankAccount& other) const;

    // Static utility functions
    static void printAccount(const BankAccount& account);
    static BankAccount createAccountFromInput();
};

#endif // OPERATOR_OVERLOAD_LAB_BANKACCOUNT_H
