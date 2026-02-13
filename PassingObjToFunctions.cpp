#include<iostream>
using namespace std;

class car
    {
	public:
	int model;
	string name;
	int prize;
};

void print(car c)
{
	cout<<c.name<<" "<<c.model<<" "<<c.prize<<endl;
	//function bna dia jisme argument car (class) c (object) kara hai k jis bhi num ki car call hogi uski num ki details print hojayengi
}
int main()
{
	car c1 , c2 , c3;
	c1.name = "honda";
	c1.model = 2015;
	c1.prize = 50000;
	
	c2.name = "vitz";
	c2.model = 2025;
	c2.prize = 300000;
	
	
	c3.name = "corolla";
	c3.model = 2022;
	c3.prize = 600000;
	
	
	print(c1);  //function call jese hi compiler yaha aayega wo seedha function mai jayega or sirf is hi num ki detials print then next & ...
	print(c2);
	print(c3);
	
	
	
	
	
	
}

