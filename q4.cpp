//hafsa nasir
//CT-068

#include <iostream>
using namespace std;

class Device {
protected:
    string brand;
};

class Laptop : public Device {
protected:
    int ram;
};

class GamingLaptop : public Laptop {
    string gpu;
public:
    void setData(string b, int r, string g) {
        brand = b;
        ram = r;
        gpu = g;
    }
    void display() {
        cout << "Brand: " << brand << endl;
        cout << "RAM: " << ram << "GB\n";
        cout << "GPU: " << gpu << endl;
    }
};

int main() {
    GamingLaptop g;
    g.setData("Dell", 8, "RTX 4800");
    g.display();
}
