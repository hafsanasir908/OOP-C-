#include<iostream>
using namespace std;
class account{
	protected:
		 double balance;
		public:
			account()
			{
				balance = 200000; 
			}
};

class saving : public account{
	
	void withdraw(double amount)
	{
		if(amount > 100000)
		{
			cout<<"cannot withdraw more tan 100000\n";
			return;
		}
		
		
			tax = amount * 0.02;
			balance -= (amount + tax);
			
			if(amount > 50000)
			{
				balane -= balance * 0.05;
			}
		cout<<"remaining balance : "<<balance<<endl;
	}
};
	class current : public account{
		
		void withdraw(double amount)
		{
			if(amount > 100000)
		{
			cout<<"cannot withdraw more tan 100000\n";
			return;
		}
		
		 balance -= amount - 100;
		 
		 if(amount > 50000)
		 {
		 	balance -= balance * 0.05;
		 }
		  
			cout<<"remaining balance : "<<balance<<endl;
		}
	};
	
	

int main()   
{
	char type;
	double amount;
	
	cout<<"enter account type (S\N): \n";
	cin>>type;
	
	cout<<"enter withdrawal amount : \n";
	cin>>amount;
	
	if(type == 's' || type == 'S')
	{
		saving s;
		s.withdraw (amount);
	}
	else if (type == 'c' || type == 'C' )
	{
		current c;
		c.withdraw(amount);
	}
	
	else{
		cout<<"invalid account type!"<<endl;
	}
	
	return 0;

}

