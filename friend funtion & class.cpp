/*#include<iostream>
using namespace std;
class test{
	private:
		int num;
		friend void fun();
		
};

void fun(){
	test obj;
	obj.num = 90;
	cout<<obj.num;
}
int main()       /*class se bahar ham private members ko ccess nhi kr skte pt hmne yhana fun nami function ko class 
{                  ka friend bana dia by writing friend keyword than return type and function name(basically prototype)
                   ab phir hmne us funcion ko main mai call kia to wo accessble hogya same kam ham main k sath bhi krskte 
                   the k main ko friend bana dete
//   test obj;
//   obj.num = 90;  //cannot access like this
     fun();
}*/


//**********************example 2*********************************

/*#include<iostream>
using namespace std;
class happycoding{
	private:
		int a , b;
		
		public:
			happycoding(int a , int b)
			{
				this->a = a;
				this->b = b;
			}
			
			friend void display(happycoding obj3);
};


void display(happycoding obj3)
{
	cout<<obj3.a<<endl;
	cout<<obj3.b<<endl;
}

int main()
{
	happycoding obj1(10 , 20);
	happycoding obj2(11 , 12);
	display(obj1);
}
*/

//-------------------------------friend class------------------------


#include<iostream>
using namespace std;
class A{
	private:
		int num;
		protected:
			int x;
			friend class B;
};

class B{
	public:
void display(){
	A obj // A class ka obj
	obj.num = 10;
	obj.x = 11;
}
};

int main()
{
	B obj;  //display normal function nhi hai wo class B ka ek member hi isliye uso access krne k liye B ka ek obj bhi banana para
	obj.display();
}

