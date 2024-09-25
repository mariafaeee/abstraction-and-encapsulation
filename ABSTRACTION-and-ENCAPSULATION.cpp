#include <iostream>
#include <limits>

using namespace std;

class BankAccount {
protected:
    double balance;

public:
    BankAccount() : balance(0) {}

    virtual void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount. Please enter a positive value." << endl;
            return;
        }
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    virtual void withdraw(double amount) = 0;

    virtual void checkBalance() const {
        cout << "Current balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
public:
    void withdraw(double amount) override {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount. Please enter a positive value." << endl;
            return;
        }
        if (balance - amount < 1000) {
            cout << "Withdrawal unsuccessful. Minimum balance of 1000 required." << endl;
            return;
        }
        balance -= amount;
        cout << "Withdrawn: " << amount << endl;
    }
};

class CurrentAccount : public BankAccount {
public:
    void withdraw(double amount) override {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount. Please enter a positive value." << endl;
            return;
        }
        balance -= amount;
        cout << "Withdrawn: " << amount << endl;
    }
};

void savingsMenu(SavingsAccount& savings) {
    int choice;
    do {
        cout << "\nSavings Account Menu:\n";
        cout << "1 - Deposit\n2 - Withdraw\n3 - Check Balance\n4 - Back\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0; // Reset choice to an invalid state
        }

        switch (choice) {
        case 1: {
            double amount;
            cout << "Enter deposit amount: ";
            cin >> amount;
            savings.deposit(amount);
            break;
        }
        case 2: {
            double amount;
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            savings.withdraw(amount);
            break;
        }
        case 3:
            savings.checkBalance();
            break;
        case 4:
            cout << "Returning to main menu." << endl;
            break;
        default:
            cout << "Invalid option. Please choose again." << endl;
        }
    } while (choice != 4);
}

void currentMenu(CurrentAccount& current) {
    int choice;
    do {
        cout << "\nCurrent Account Menu:\n";
        cout << "1 - Deposit\n2 - Withdraw\n3 - Check Balance\n4 - Back\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0; // Reset choice to an invalid state
        }

        switch (choice) {
        case 1: {
            double amount;
            cout << "Enter deposit amount: ";
            cin >> amount;
            current.deposit(amount);
            break;
        }
        case 2: {
            double amount;
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            current.withdraw(amount);
            break;
        }
        case 3:
            current.checkBalance();
            break;
        case 4:
            cout << "Returning to main menu." << endl;
            break;
        default:
            cout << "Invalid option. Please choose again." << endl;
        }
    } while (choice != 4);
}

int main() {
    SavingsAccount savings;
    CurrentAccount current;
    int mainChoice;

    do {
        cout << "\nMain Menu:\n";
        cout << "1 - Savings Account\n2 - Current Account\n3 - Exit\n";
        cout << "Choose an option: ";
        cin >> mainChoice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            mainChoice = 0; // Reset choice to an invalid state
        }

        switch (mainChoice) {
        case 1:
            savingsMenu(savings);
            break;
        case 2:
            currentMenu(current);
            break;
        case 3:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid option. Please choose again." << endl;
        }
    } while (mainChoice != 3);

    return 0;
}