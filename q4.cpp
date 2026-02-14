#include<iostream>
using namespace std;

class matrix{
	int a[3][3] , b[3][3] , sum[3][3] , mul[3][3];
	
	void input()
	{
		cout<<"enter first mtrix"<<endl;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3 ; j++)
			{
				cin>>a[i][j];
			}
		}
		
		cout<<"enter second mtrix"<<endl;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3 ; j++)
			{
				cin>>b[i][j];
			}
		}
	}
	
	void addition()
	{
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				sum[i][j] = a[i][j] + b[i][j];
			}
			
		}
	}
	
	void multiply()
	{
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				mul[i][j] = 0;
				for(int k = 0; k < 3;k++)
				{
					mul[i][j] += a[i][k] *b[j][k]; 
				}
				cout<<endl;
			}
			
		}
	}
	
	void display(int m[3][3])
	{
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				cout<<m[i][j]<<" ";
			}
			cout<<endl;
		}
	}

};
int main()
{
	  matrix m;
	 m.addition();
	cout<<"addditon"<<endl;
	
	m.display(m.sum);
	
	 m.multiply();
	cout<<"multiplication"<<endl;
	
	m.display(m.mul);
	
	
	

}

