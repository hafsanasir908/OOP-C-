//hafsa nasir
//CT-068

#include <iostream>
using namespace std;

class Person {
protected:
    string name;
public:
    void setName(string n) {
        name = n;
    }
};

class Student : public Person {
protected:
    int roll;
public:
    void setRoll(int r) {
        roll = r;
    }
};

class Result : public Student {
    int marks;
public:
    void setMarks(int m) {
        marks = m;
    }
    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll: " << roll << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Result r;
    r.setName("hafsa");
    r.setRoll(68);
    r.setMarks(98);
    r.display();
}
