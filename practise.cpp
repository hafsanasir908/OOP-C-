#include<iostream>
using namespace std;
//class student{
//	public:
//	float marks;
//	string name;
//	
//	void display()
//	{
//		cout<<"name : "<<name<<endl;
//		cout<<"marks : "<<marks<<endl;
//		
//	}
//};
//int main()
//{
//	student s1;
//	s1.name = "hafsa";
//	s1.marks  = 99.7;
//	s1.display();
//
//			  }


//--------------------------------------------------------

//class rectangle{
//	public:
//	float length;
//	float width;
//	
//	int area()
//	{
//		
//		
//		return length * width;
//		
//	}
//	
//	
//	
//};
//
//int main()
//{
//	rectangle r1;
//	r1.length = 5;
//	r1.width = 6;
//	
//	cout<<"area : "<<r1.area();
//}

//----------------------------------------------------------------

//
//  class car{
//  	public:
//  	string name;
//  	int model;
//  	
//  	car(string n , int m)
//  	{
//  		name = n;
//  		model = m;
//  		
//  		
//	  }
//	  
//	  void display()
//	  {
//	  	cout<<"name : "<<name<<endl;
//	  	cout<<"model : "<<model<<endl;
//	  }
//  	
//  };
//  
//  int main()
//  {
//  	car c("toyota" , 2022);
//  	c.display();
//  }

//------------------------------------------

  class bank{
  	private:
  	  float balance = 0;
  	  
  	  public:
  	  	float deposit;
  	  	
  	  	void depositamt(float amount)
  	  	{
  	  		balance += amount;
			}
			
			void showBalance(){
				cout<<"balance : "<<balance;
			}
  };
  
  int main()
  {
  	bank b;
  	b.depositamt(1500);
  	b.showBalance();
  }

