#include<iostream>
using namespace std;
class student {
	public:
	string name;
	int roll_no;
	float gpa;
};

class car
    {
	public:
	int model;
	string name;
	int prize;
};
int main()

{
	student s1;
	s1.name = "hafsa nasir";
//	s1.roll_no = 68;
	s1.gpa = 3.7;
	
	student s2;
	s2.name = "laiba nasir";
	s2.roll_no = 57;
	s2.gpa = 3.6;
	
		
	//for input
	
	cin>>s1.roll_no;
	cout<<s1.name<<" "<<s1.roll_no<<" "<<s1.gpa<<endl;
	cout<<s2.name<<" "<<s2.roll_no<<" "<<s2.gpa<<endl;
	
	
	car c;
	cin>>c.name;
	cin>>c.model;
	cin>>c.prize;
	
	cout<<c.name<<" "<<c.model<<" "<<c.prize<<endl;
	
	
	

	
	
	
	
}



