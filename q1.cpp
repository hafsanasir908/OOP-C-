#include<iostream>
using namespace std;
class student{
	private:
		int roll_no;
		float marks[5];
		int total;
		float percentage;
		
		public:
			void input(){
				cout<<"enter your roll num : "<<endl;
				cin>>roll_no;
				
				total = 0;
				for(int i = 0; i < 5; i++)
				{
					cout<<"enter marks of subject   "<<i+1<<" : "<<endl;
					cin>>marks[i];
					total += marks[i];
				}
			}
			
			void calculate(){
				percentage = (total/500)*100
				
			}
			void display(){
				cout<<"roll no : "<<roll_no<<endl;
				cout<<"total : "<<total<<endl;
				cout<<"percentage : "<<percentage<<endl;
				
			}
};
int main()
{
	 //lab 1 qno 1
	 student s;
	 s1.input();
	 s1.calculate();
	 s1.display();
	 
	 

}

