//hafsa nasir
//CT-068

#include <iostream>
using namespace std;

class Product {
protected:
    string name;
    float price;
public:
    Product(string n, float p) {
        name = n;
        price = p;
    }
};

class Electronics : public Product {
    int warranty;
public:
    Electronics(string n, float p, int w) : Product(n,p) {
        warranty = w;
    }
    void finalPrice() {
        cout << name << " Final Price: " << price << endl;
        cout << "Warranty: " << warranty << " years\n";
    }
};

class Clothing : public Product {
    string size;
public:
    Clothing(string n, float p, string s) : Product(n,p) {
        size = s;
    }
    void finalPrice() {
        cout << name << " Final Price: " << price << endl;
        cout << "Size: " << size << endl;
    }
};

int main() {
    Electronics e("Laptop", 55000, 2);
    Clothing c("Shirt", 18000, "M");

    e.finalPrice();
    c.finalPrice();
}
