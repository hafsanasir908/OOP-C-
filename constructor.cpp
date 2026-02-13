#include<iostream>
using namespace std;
class student {
	public:
	string name;
	int roll_no;
	float gpa;
	
	//constructor 
	
	student(string s , int r , float g)  //class name
	{
		name = s;
		roll_no = r;
		gpa = g;
	}
};
int main()
{
	   student s1("hafsa nasir" , 68 , 3.6);
		cout<<s1.name<<" "<<s1.roll_no<<" "<<s1.gpa<<endl;
}

