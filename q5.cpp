//hafsa nasir
//CT-068
#include <iostream>
using namespace std;

class Reader {
public:
    void read() {
        cout << "Reading file...\n";
    }
};

class Writer {
public:
    void write() {
        cout << "Writing file...\n";
    }
};

class File : public Reader, public Writer {
};

int main() {
    File f;
    f.read();
    f.write();
}
