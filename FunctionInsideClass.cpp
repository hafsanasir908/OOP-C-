#include<iostream>
using namespace std;

class cricketer{
	public:
		string name;
		int runs;
		int age;
		
		//constructor
		
		cricketer(string name , int runs , int age)
		{
			this->name = name;
			this->runs = runs ; 
			this->age = age;
		}
		
		//function inside class
		
		void print()
		{
			cout<<name<<" "<<runs<<" "<<age<<endl;
		}
		
		
		
};
int main()
{
	cricketer c1("babar" , 25000 , 32);  //bar bar lamba chora cout nhi likhna pare isliye ek dfa function bana dia yai class k baahirr bhi bana skte the
	                                     //jese shayd car wale mai ya kisi or mai banaya hai and it is recommened k function mai cout<<this->name aise
	                                    //krke age or runs wagerah likho ta ke agr in future function mai koi parameter same name k  de to issue na ho:)
	cricketer c2("rizwan" , 35000 , 38);
	
	c1.print();  //aise print se sari cheezein hojayengi jese alag laga c1.name tehn age wagerah krte the
	c2.print();
}

