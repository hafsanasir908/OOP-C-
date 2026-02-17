#include<iostream>
using namespace std;
class hotel{
	private:
	string name;
	int days;
	float rent;
	static const  float PerDayCharge;
	public:
	
	hotel(string n , int d)
	{
		name = n;
		days = d;
		
		if(d > 7)
		{
			rent = (d - 1) * PerDayCharge;
		}
		else{
			 rent = d * PerDayCharge;
		}
	}
	
	void display() const{
		cout<<"coustomer name : "<<name<<endl;
		cout<<"days: "<<days<<endl;
		cout<<"rent : "<<rent<<endl;
	}
};

const float hotel :: PerDayCharge = 1000.85;
int main()
{
	hotel h1("hafsa" , 5);
	hotel h2("eman" , 10);
	
	cout<<"coustomer 1 details"<<endl;
	h1.display();
	
	
	cout<<"coustomer 2 details"<<endl;
	h2.display();}


