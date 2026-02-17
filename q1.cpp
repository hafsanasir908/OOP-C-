//hafsa nasir
//CT-068

#include <iostream>
using namespace std;

class Person {
protected:
    string name;
public:
    void setPerson(string n) {
        name = n;
    }
};

class Student : public Person {
    int roll;
public:
    void setStudent(int r) {
        roll = r;
    }
    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << roll << endl;
    }
};

int main() {
    Student s;
    s.setPerson("hafsa");
    s.setStudent(001);
    s.display();
}
