#include <iostream>
using namespace std;

class Ticket {
protected:
    string source, destination;
    float price;
public:
    Ticket(string s, string d, float p) {
        source = s;
        destination = d;
        price = p;
    }
};

class BusTicket : public Ticket {
public:
    BusTicket(string s, string d, float p) : Ticket(s,d,p) {}
    void totalFare() {
        cout << "Bus Fare: " << price << endl;
    }
};

class FlightTicket : public Ticket {
public:
    FlightTicket(string s, string d, float p) : Ticket(s,d,p) {}
    void totalFare() {
        cout << "Flight Fare: " << price + 5000 << endl;
    }
};

int main() {
    BusTicket b("Islamabad", "Karachi", 3000);
    FlightTicket f("Faisalabad", "Lahore", 15000);

    b.totalFare();
    f.totalFare();
}
