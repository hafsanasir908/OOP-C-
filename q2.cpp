#include<iostream>
using namespace std;
class dynamicArray{
	private:
	int* arr;
	int capacity; //total size
	int current_size;  //currrent elements added
	
	public:
	dynamicArray(int size)
	{
		capacity = size;
		current_size = 0;
		arr = new int[capacity];
		
		//initialize all elements to zero
		for(int i = 0; i < capacity ; i++)
		{
			arr[i] = 0;
		}
	}
	
	//push values if space is availabe
	
	void push(int value)
	{
		if(current_size  < capacity)
		{
			arr[current_size] = value;
			current_size++;
			
	
		}
		else{
			cout<<"Array is full! Cannot add more elements!"<<endl;
		}
	}
	
	int size() const{
		return current_size;
	}
	
	void display()
	{
		for(int i = 0 ; i < current_size; i++)
		{
			cout<<arr[i]<<" ";
			cout<<endl;
		}
	}
	
	~dynamicArray()
	{
		delete[] arr;
	}
	
};
int main()
{
   dynamicArray d(5);
   
   d.push(10);
   d.push(20);
   d.push(30);
   
   cout<<"elements in arrray"<<endl;
   d.display();
   
   cout<<"array size"<<d.size()<<endl;
   
   d.push(40);
   d.push(50);
   d.push(60);
   cout<<"after adding more elements"<<endl;
   d.display();
   cout<<d.size();

}
