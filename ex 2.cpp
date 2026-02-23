#include <iostream>
using namespace std;
class Complex {
private:
    float real;
    float imag;

public:
    Complex() : real(0), imag(0) {}

    void input() {
        cout << "Enter real and imaginary parts respectively: ";
        cin >> real >> imag;
    }

    Complex operator+(const Complex& obj) {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};
int main() {
    Complex c1, c2, c3;

    c1.input();
    c2.input();

    c3 = c1 + c2;

    cout << "Result: ";
    c3.display();
    return 0;
}