#include <iostream>
#include <cmath>
using namespace std;

class Vector {
private:
    float x, y;

public:

    Vector(float x = 0 , float y = 0) {
       this->x = x;
       this->y = y;
    }
    Vector operator+( Vector& v) 
	{
        return Vector(x + v.x, y + v.y);
    }

    Vector operator-( Vector& v) 
	 {
        return Vector(x - v.x, y - v.y);
    }

    Vector operator*(float scalar) 
	{
        return Vector(x * scalar, y * scalar);
    }

    Vector operator/(float scalar) 
	 {
        return Vector(x / scalar, y / scalar);
    }

    float magnitude() 
	{
        return sqrt(x * x + y * y);
    }

    void display()  
	{
        cout<< x << ", " << y << endl;
    }
};

int main() {

    Vector v1(6, 8);
    Vector v2(2, 4);

    cout << "Vector 1: ";
    v1.display();

    cout << "Vector 2: ";
    v2.display();

    Vector add = v1 + v2;
    cout << "Addition (v1 + v2): ";
    add.display();

    Vector sub = v1 - v2;
    cout << "Subtraction (v1 - v2): ";
    sub.display();

    Vector mul = v1 * 2;
    cout << "Scalar Multiplication (v1 * 2): ";
    mul.display();

    Vector div = v1 / 2;
    cout << "Scalar Division (v1 / 2): ";
    div.display();

    cout << "Magnitude of v1: " << v1.magnitude() << endl;
}