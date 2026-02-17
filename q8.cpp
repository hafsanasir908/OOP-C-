#include <iostream>
using namespace std;

class Attack {
protected:
    int attackPower;
public:
    Attack(int a) {
        attackPower = a;
    }
    void attack() {
        cout << "Attack Power: " << attackPower << endl;
    }
};

class Defense {
protected:
    int shieldPower;
public:
    Defense(int s) {
        shieldPower = s;
    }
    void defend() {
        cout << "Shield Power: " << shieldPower << endl;
    }
};

class Warrior : public Attack, public Defense {
public:
    Warrior(int a, int s) : Attack(a), Defense(s) {}

    void totalPower() {
        cout << "Total Battle Power: " << attackPower + shieldPower << endl;
    }
};

int main() {
    Warrior w(80, 40);
    w.attack();
    w.defend();
    w.totalPower();
}
