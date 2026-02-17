#include<iostream>
using namespace std;
class account{
	private:
	int acc_num;
	int acc_bal;
	int security_code;
	static int count;
	
	public:
	account(){
		count++;
	}
	
	void initialize(int num , int bal , int code)
	{
		acc_num = num;
		acc_bal = bal;
		security_code = code;
		
	}
	
	void display()
	{
		cout<<"account num : "<<acc_num<<" "<<"account balance : "<<acc_bal<<" "<<"security code : "<<security_code;
	}
	
	static int getcount()
	{
		return count;
	}
	
};

int account :: count = 0;
int main()
{
    account a1 , a2 , a3;
    
    a1.initialize(101 , 50000 , 1234);
    a2.initialize(102 , 25000, 4321);
    a3.initialize(103 , 1500 , 2343);
    
    cout<<"account 1 details"<<endl;
    a1.display();
    cout<<endl;
    
    
    cout<<"account 2 details"<<endl;
     a2.display();
     cout<<endl;
     
    cout<<"account 3 details"<<endl;
     a3.display();
	 cout<<endl;
     
     cout<<"total objects created"<<endl;
     cout<<account::getcount()<<endl;
}
