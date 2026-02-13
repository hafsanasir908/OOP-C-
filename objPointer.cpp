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
	cricketer c1("babar azam" , 50000 , 56.6);
	
	cricketer* p1 = &c1;
	cout<<(*p1).runs<<endl;
	(*p1).avg = 58.9;
	cout<<(*p1).avg<<endl;
	

    
			  }

