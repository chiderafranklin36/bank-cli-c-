#include <vector>
#include <iostream>
#include <random>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

class Account {
    private:
    string accountNumber;
    double balance;
    string owner;
    int userPin;

    public:
    Account (string n, double money) {
        accountNumber = generateAccountNumber();
        owner = n;
        balance = money;
        int pin;
        while (true) {
            cout << "Enter a 4-digit PIN for this account: ";
            if (!(cin >> pin)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter numeric PIN." << endl;
                continue;
            }
            if (pin >= 1000 && pin <= 9999) {
                userPin = pin;
                break;
            } else {
                cout << "PIN must be 4 digits." << endl;
            }
        }
        cout << "Account created for " << owner << " with account number " << accountNumber << " and initial balance " << balance << endl;
    }
    
    static string generateAccountNumber() {
        static random_device rd;
        static mt19937 gen(rd());
        static uniform_int_distribution<> dis(100000, 999999);
        return "ACC" + to_string(dis(gen));
    }
    
    
    bool verifyPIN(int inputPIN) const {
        return inputPIN == userPin;
    }
    void printBalance () {
        cout << "Balance: " << balance << endl;

    }

   virtual void deposit (double amount) {
        balance += amount;
        if (amount <= 0) {
            cout << "You have entered an invalid deposit amount " << endl;
        } else {
            cout << " Your deposit was successful" << endl;
        } 

    }
    virtual void withdraw (double amount) {
        if (amount > balance) {
            cout << "You currently have insufficient funds" << endl;
        } else {
            balance -= amount;
            cout << "You have made a withdrawal of " << amount << endl;
        }
    }
    virtual void displayBalance() {
        cout << "Current balance is: " << balance << endl;
    }
    virtual void apply_interest() {
        // default no-op for non-interest-bearing accounts
    }
    double getbalance() const {
        return balance;
    }
    string getowner () const {
        return owner;
    }

};
class savings_account : public Account  {
    private:
    double interest_rate;
    public:
    savings_account( string n , double money , double rate) : Account (n, money) {
        interest_rate = rate;
    }
    void apply_interest () override {
        double interest = getbalance() * 20.0/100;
        deposit (interest);
        cout << "Interest of " << interest << " has been applied to your account" << endl;
    }
    void displayBalance() override {
        cout << "savings account balance for" << getowner() << "is" <<getbalance() <<endl;
    }

};
class current_account : public Account {
    private:
    double overdraft_limit;
    public:
    current_account ( string n , double money , double limit) : Account (n, money) {
        overdraft_limit = limit;
    }
    void withdraw (double amount) override {
        if (amount > getbalance() + overdraft_limit) {
            cout << "You have exceeded your overdraft limit" << endl;
        } else {
            Account::withdraw(amount);
        }
    }
    void displayBalance() override {
        cout << "current account balance for" << getowner() << "is" <<getbalance() <<endl;
    }

};

int main() {
    string name;
    double money;
    int pin;

    cout << "Name: ";           cin >> name;
    cout << "Deposit: $";       cin >> money;

    while (true) {
        cout << "Set 4-digit PIN: ";
        cin >> pin;
        if (pin >= 1000 && pin <= 9999) break;
        cout << "Invalid! Must be 4 digits.\n";
    }

    Account frank(name, money, pin);

    frank.displayBalance();
    frank.deposit(300);
    frank.withdraw(100);

    return 0;
}