#include<iostream>
using namespace std;
class calculator{
	private:
		int num1 , num2 , num3;
		
		public:
			calculator()
			{
				cout<<"enter three numbers\n";
				cin>>num1>>num2>>num3;
			}
			
			int add(int a , int b)
			{
				return a + b;
			}
			
			int add(int a , int b , int c)
			{
				return a + b + c;
			}
			
			int mul(int a , int b)
			{
				return a * b;
			}
			
			int mul(int a , int b , int c)
			{
				return a * b * c;
			}
			
			int sub()
			{
				return num1 - num2;
			}
			
			int div()
			{
				if(num2 != 0)
				{
					return num1 / num2;
				}
				
				else{
					cout<<"division by zero is not allowed!\n";
				}
			}
		};
int main()
{
    
    calculator c;  


    cout << "Addition (2 numbers): " << c.add(2, 3) << endl;
    cout << "Addition (3 numbers): " << c.add(2, 3, 4) << endl;

    cout << "Multiplication (2 numbers): " << c.mul(2, 3) << endl;
    cout << "Multiplication (3 numbers): " << c.mul(2, 3, 4) << endl;

    
    cout << "Subtraction (Num1 - Num2): " << c.sub() << endl;
    cout << "Division (Num1 / Num2): " << c.div() << endl;

    return 0;
}
