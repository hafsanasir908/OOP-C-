#include<iostream>
using namespace std;
class complex{
	private:
		int real , imag;
		
		public:
			complex(int real , int imag)
			{
				this->real = real;
				this->imag = imag;
				
			}
			
			void display()
			{
				cout<<real<<"+"<<imag<<"i"<<endl;
			}
			
			complex()
			{
				 //defalut constructor for c3
			}
			
			complex operator + (complex &c)  /*return type then operator is a keyword then + is a operator jise ham overload
			                                kara rahe then brakcet aise hai k c1 call kara rha hai is function ko or c2 ko as a
			                                parameter lia hai ta ke real ko real mai and img ko img mai add krwa saken*/
			{
				complex ans;
				ans.real  = real + c.real;
				ans.imag = imag + c.imag;
				return ans;
			}
};

int main()
{
   complex c1(3,4);
   complex c2(5,2);
   
   complex c3 = c1 + c2;
   c3.display();
}
