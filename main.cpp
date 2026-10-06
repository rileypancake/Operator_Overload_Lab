#include <iostream>
#include <vector>
#include <limits>
#include "BankAccount.h"

int main() {
    std::vector<BankAccount> accounts;
    int choice = 0;

    while (choice != 7) {
        std::cout << "\n========== Bank Account System ==========\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. View Account\n";
        std::cout << "5. Compare Accounts\n";
        std::cout << "6. Copy Account\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number from 1 to 7.\n";

            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            continue;
        }

        // CREATE ACCOUNT
        if (choice == 1) {
            BankAccount newAccount =
                BankAccount::createAccountFromInput();

            bool duplicate = false;

            for (const BankAccount& account : accounts) {
                if (account == newAccount) {
                    duplicate = true;
                    break;
                }
            }

            if (duplicate) {
                std::cout << "An account with that number already exists.\n";
            } else {
                accounts.push_back(newAccount);
                std::cout << "Account created successfully!\n";
            }
        }

        // DEPOSIT
        else if (choice == 2) {
            std::string accountNumber;
            double amount;

            std::cout << "Enter account number: ";
            std::cin >> accountNumber;

            bool found = false;

            for (BankAccount& account : accounts) {
                if (account.getAccountNumber() == accountNumber) {
                    found = true;

                    std::cout << "Enter deposit amount: ";

                    if (!(std::cin >> amount)) {
                        std::cout << "Invalid amount.\n";

                        std::cin.clear();
                        std::cin.ignore(
                            std::numeric_limits<std::streamsize>::max(),
                            '\n'
                        );

                        break;
                    }

                    if (amount <= 0) {
                        std::cout
                            << "Deposit amount must be greater than zero.\n";
                        break;
                    }

                    // Using overloaded += operator
                    account += amount;

                    std::cout << "Deposit successful!\n";
                    std::cout << "New balance: $"
                              << account.getBalance() << "\n";

                    break;
                }
            }

            if (!found) {
                std::cout << "Account not found.\n";
            }
        }

        // WITHDRAW
        else if (choice == 3) {
            std::string accountNumber;
            double amount;

            std::cout << "Enter account number: ";
            std::cin >> accountNumber;

            bool found = false;

            for (BankAccount& account : accounts) {
                if (account.getAccountNumber() == accountNumber) {
                    found = true;

                    std::cout << "Enter withdrawal amount: ";

                    if (!(std::cin >> amount)) {
                        std::cout << "Invalid amount.\n";

                        std::cin.clear();
                        std::cin.ignore(
                            std::numeric_limits<std::streamsize>::max(),
                            '\n'
                        );

                        break;
                    }

                    if (amount <= 0) {
                        std::cout
                            << "Withdrawal amount must be greater than zero.\n";
                    }
                    else if (amount > account.getBalance()) {
                        std::cout
                            << "Insufficient funds.\n";
                    }
                    else {
                        // Using overloaded -= operator
                        account -= amount;

                        std::cout << "Withdrawal successful!\n";
                        std::cout << "New balance: $"
                                  << account.getBalance() << "\n";
                    }

                    break;
                }
            }

            if (!found) {
                std::cout << "Account not found.\n";
            }
        }

        // VIEW ACCOUNT
        else if (choice == 4) {
            std::string accountNumber;

            std::cout << "Enter account number: ";
            std::cin >> accountNumber;

            bool found = false;

            for (const BankAccount& account : accounts) {
                if (account.getAccountNumber() == accountNumber) {
                    BankAccount::printAccount(account);
                    found = true;
                    break;
                }
            }

            if (!found) {
                std::cout << "Account not found.\n";
            }
        }

        // COMPARE ACCOUNTS
        else if (choice == 5) {
            if (accounts.size() < 2) {
                std::cout << "You need at least two accounts to compare.\n";
                continue;
            }

            std::string firstNumber;
            std::string secondNumber;

            std::cout << "Enter first account number: ";
            std::cin >> firstNumber;

            std::cout << "Enter second account number: ";
            std::cin >> secondNumber;

            const BankAccount* firstAccount = nullptr;
            const BankAccount* secondAccount = nullptr;

            for (const BankAccount& account : accounts) {
                if (account.getAccountNumber() == firstNumber) {
                    firstAccount = &account;
                }

                if (account.getAccountNumber() == secondNumber) {
                    secondAccount = &account;
                }
            }

            if (firstAccount == nullptr || secondAccount == nullptr) {
                std::cout << "One or both accounts could not be found.\n";
            }
            else {
                std::cout << "\nComparison Results:\n";

                if (*firstAccount == *secondAccount) {
                    std::cout
                        << "The accounts have the same account number.\n";
                }
                else {
                    std::cout
                        << "The accounts have different account numbers.\n";
                }

                if (*firstAccount < *secondAccount) {
                    std::cout
                        << "The first account has a lower balance.\n";
                }
                else if (*firstAccount > *secondAccount) {
                    std::cout
                        << "The first account has a higher balance.\n";
                }
                else {
                    std::cout
                        << "The accounts have the same balance.\n";
                }
            }
        }

        // COPY ACCOUNT
        else if (choice == 6) {
            if (accounts.empty()) {
                std::cout << "There are no accounts to copy.\n";
                continue;
            }

            std::string accountNumber;

            std::cout << "Enter account number to copy: ";
            std::cin >> accountNumber;

            bool found = false;

            for (const BankAccount& account : accounts) {
                if (account.getAccountNumber() == accountNumber) {

                    // Demonstrates the copy constructor
                    BankAccount copiedAccount(account);

                    std::cout << "\nCopied account:\n";
                    BankAccount::printAccount(copiedAccount);

                    // Demonstrates copy assignment
                    BankAccount assignedAccount;
                    assignedAccount = account;

                    std::cout << "\nAccount created using copy assignment:\n";
                    BankAccount::printAccount(assignedAccount);

                    found = true;
                    break;
                }
            }

            if (!found) {
                std::cout << "Account not found.\n";
            }
        }

        // EXIT
        else if (choice == 7) {
            std::cout
                << "Thank you for using the Bank Account Management System!\n";
        }

        else {
            std::cout
                << "Invalid choice. Please enter a number from 1 to 7.\n";
        }
    }

    return 0;
}
