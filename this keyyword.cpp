#include<iostream>
using namespace std;
class cricketer{
	public:
		string name;
		int runs;
		
		cricketer(string name  , int runs)  /*ham chahte hain k ham apne obj naem public k bad jo likhe hain & construcor mai jo parmeter variale hain 
		                                    unka name same rakhen to agr ham yai kam baghair this keyword ke karenge to compiler garabage value dega 
		                                    qk wo khali dabbe mai or jis dabbe dabbe mai values store hain usme difference ni kar payenge so is wajah
		                                    se ham this key word ka use kara hai simple*/
		{
			this->name = name;
			this->runs = runs;
		}
		
};
int main()
{
	cricketer c1("babar azam",25000);
	
	cricketer c2("m.rizwan" , 20000);
	
	cout<<c1.name<<" "<<c1.runs<<endl;
	cout<<c2.name<<" "<<c2.runs<<endl;
			
			  }

