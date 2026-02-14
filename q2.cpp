#include<iostream>
using namespace std;
class swapNumber{

	
	void swapThree(	int* a , int* b	, int* c)
	{
		int temp = *a;
		*a = *b;
		*b = *c;
		*c = temp;
		
	}
};
int main()
{
	int x , y , z;
	cout<<"enter three numbers : ";
	cin>>x>>y>>z;
	
	cout<<"before swapping"<<x<<" "<<y<<" "<<z<<endl;
	  
	swapNumber s;
    s.swapThree(&x , &y , &z);
    
    cout<<"after swapping"<<x<<" "<<y<<" "<<z<<endl;
    
	

}

