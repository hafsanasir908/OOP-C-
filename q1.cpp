#include<iostream>
using namespace std;
class employee{
	private:
	char* emp_name;
	const int emp_id;
	
	public:
		employee(const char*name  , int id) : emp_id(id)
		{
			emp_name = new char[strlen(name) + 1];
			strcpy(emp_name , name); 
		}
		
		//setter for name
		
		void setname(const char*name)
		{
			delete[] emp_name;
			emp_name = new char[strlen(name) + 1];
			strcpy(emp_name , name);
			
		}
		
		//getter for name
		
		const char* getname()
		{
			return emp_name;
			
		}
		
		//getter for id
	  
	    int getid() const{
	    	return emp_id;
		}
		
		~employee(){
			delete[] emp_name;
		}
	

	
};
int main()
{
    employee e1("hafsa" , 101);
    employee e2("eman" , 102);
    employee e3("duaa" , 103);
    
    e1.setname("amna");
    cout<<e1.getname()<<" "<<e1.getid()<<endl;
    cout<<e2.getname()<<" "<<e2.getid()<<endl;
    cout<<e3.getname()<<" "<<e3.getid()<<endl;
    
    
}
