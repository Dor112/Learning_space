#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string id;
    string name;
    double balance;

public:
    BankAccount(string ide, string owner, double bal) : id(ide), name(owner), balance(bal) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Added: " << amount << ". Balance: " << balance << endl;
        }
        else {
            cout << "Adding sum need to be positive." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Removed: " << amount << ". Balance: " << balance << endl;
        }
        else {
            cout << "Not enough money to remove." << endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    void displayAccountInfo() const {
        cout << "Bill id: " << id << ", User: " << name << ", Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double rate;
public:
    SavingsAccount(string ide, string owner, double balance, double rate) : BankAccount(ide, owner, balance), rate(rate) {}

    void percent() {
        double interest = getBalance() * (rate / 100);
        deposit(interest);
        cout << "Added percents: " << interest << ". Balance: " << getBalance() << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    BankAccount firacc("1", "Ivan Ivanov", 500.0);
    firacc.displayAccountInfo();

    firacc.deposit(500.0);
    firacc.withdraw(200.0);
    firacc.withdraw(1500.0);

    SavingsAccount secacc("2", "Dima Dmitriev", 2000.0, 5.0);
    secacc.displayAccountInfo();

    secacc.deposit(300.0);
    secacc.withdraw(100.0);
    secacc.percent();

    return 0;
}
