#include <iostream>
using namespace std;

class Account {
protected:
    float balance;
public:
    Account(float b) {
        balance = b;
    }
};

class SavingAccount : public Account {
public:
    SavingAccount(float b) : Account(b) {}
    void addInterest() {
        balance += balance * 0.05;
        cout << "Balance with interest: " << balance << endl;
    }
};

class FixedAccount : public Account {
public:
    FixedAccount(float b) : Account(b) {}
    void showBalance() {
        cout << "Fixed Account Balance: " << balance << endl;
    }
};

int main() {
    SavingAccount s(15000);
    FixedAccount f(35000);

    s.addInterest();
    f.showBalance();
}
