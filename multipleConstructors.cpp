#include<iostream>
using namespace std;
class student {
	public:
	string name;
	int roll_no;
	float gpa;
	
	//constructor  1
	
	student(string s , int r)  //class name   |   it has 2 parameter so it will represent s1
	{
		name = s;
		roll_no = r;
		
	}
	
	student(){  /*this is a default constructor it will represt s2 which has 0 arguments , 
             	yai banana zarori hota agr multiple constructor hote program mai wrna yai by default hota hai likhna nhi prt*/
		
	}
	
	student(string s , int r , float g)  // it has 3 parameter so it will represent s3
	{
		name = s;
		roll_no = r;
		gpa = g;
		
	}
	 
	student(int r , float g , string s)  /* order same hona bhi zarori hai const ka and jahan declare kar rahe waha k 
	                                      s3 or s4 dhono mai 3 arguments hai to ab order dekeh ge const 3 k order s3 se 
	                                      match kr rahe to wo usse represent karega and same for s4*/
	{
		roll_no = r;
		gpa = g;
		name = s;
	}
	
	      };
    int main()
     {
	    student s1("hafsa nasir" , 68);
	    s1.gpa = 3.6;
	  
	    
	    //normally initialized without using constructor
	    student s2;
	    s2.name = "laiba";
	    s2.roll_no = 45;
	    s2.gpa = 3.2;
	    
	    
	    student s3("saud nasir" , 52 , 3.3 );
	    
	    student s4(65 , 3.8 , "eman");
	    
	    
	    student s5(s1);  //this is copy constructor like hamene ek student s5 obj banaya hau and usme consttructor s1 call kara dia 
	                     //to wo isme copy hogya and it is a deep copy like changes in it wil affect the original
	                     
	                     
	    //it can also be done like this : 
	    student s6 = s1; //this is also a deep copy
	    s6.name = " dua";
	    
	    cout<<s1.name<<" "<<s1.roll_no<<" "<<s1.gpa<<endl;
	    cout<<s2.name<<" "<<s2.roll_no<<" "<<s2.gpa<<endl;
	    cout<<s3.name<<" "<<s3.roll_no<<" "<<s3.gpa<<endl;
	    cout<<s4.name<<" "<<s4.roll_no<<" "<<s4.gpa<<endl;
	    cout<<s5.name<<" "<<s5.roll_no<<" "<<s5.gpa<<endl;
	    cout<<s6.name<<" "<<s6.roll_no<<" "<<s6.gpa<<endl;
	    
	    
	    
	    
                                                             
															 }



