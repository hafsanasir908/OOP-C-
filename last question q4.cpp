#include <iostream>
using namespace std;
class Person {
protected:
    string name;
    string occupation;

public:
    // Constructor
    Person( string occupation)
	 {
   
       this->occupation = occupation;
    }

    virtual void Draw() 
	{
        cout << "A person can draw in many ways" << endl;
    }
 
    virtual ~Person()
	 { 
	    
	 }
};

class Artist : public Person {
public:
    Artist() : Person("artist") 
	{
		
	}

    void Draw() 
	 {
        cout << "An artist can draw with a paint brush" << endl;
    }
};

class Gunman : public Person {
public:
    Gunman() : Person("gunman") 
	{
		
	}
	
    void Draw() 
	{
        cout << "A gunman draws a gun to shoot" << endl;
    }
};

int main() 
{
    Person* p[3];

    p[0] = new Person("person");
    p[1] = new Artist();
    p[2] = new Gunman();


    for (int i = 0; i < 3; i++) 
	{
        p[i]->Draw();
    }

    for (int i = 0; i < 3; i++) 
	{
        delete p[i];
    }

    return 0;
}