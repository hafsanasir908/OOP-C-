#include<iostream>
using namespace std;
class cricketer{
	public:
	int runs;
	string name;
	float avg;
	
	
	cricketer(string name , int runs , float avg)
	{
		
		this->name = name;
		this->avg = avg;
		this->runs = runs;
	}
};
int main()
{
	cricketer c1("babar" , 25000  ,55.3);
	
	cricketer (*c2) = new cricketer("rohit" , 23000 , 36.5);
	
	cout<<c1.name<<" "<<c1.runs<<endl;
	cout<<c2->name<<" "<<c2->runs<<endl;
	cricketer (*c2).name = "rizwan";
	cout<<(*c2).name<<endl;
}

