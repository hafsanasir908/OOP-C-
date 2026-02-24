#include<iostream>
#include<vector>
using namespace std;
int main()
{
	//vector  vector kewword <data type> vector name --> vector<int>vec
	
   vector<int> vec;
   vec.push_back(1);
   vec.push_back(2);
   vec.push_back(3);
   vec.emplace_back(6);
   cout<<"size : "<<vec.size()<<endl;
   cout<<"capacity : "<<vec.capacity()<<endl;
   vec.pop_back();
   
   
   for(int val : vec)
   {
   	cout<<val<<" ";
   	
   }
   cout<<endl;
   
   cout<<"value at idx 1 and 2: "<<vec[1]<<" and "<<vec.at(2)<<endl; //dhono tareeqe se kisi specific idx ki value accss krskte
   
    cout<<"value at front: "<<vec.front()<<endl; //to access frist val -> front
     cout<<"value at back "<<vec.back()<<endl;   //to access last val -> back
     
     vector<int> v1 = {8,9,6,5,4}; //can also initilize like this
     
     
   for(int val : v1)
   {
   	cout<<val<<" ";
   	
   }
   
   cout<<endl;
   
//-----------------------------------------------------------------------------------------------
   
   //to copy one vector element into other
   
   vector<int> v3(v1);
   
    for(int val : v3)
   {
   	cout<<val<<" ";
   }
   cout<<endl;
   
//**************************************************************************************************

   //same size ka vector cahiye jisme sari value same hi to usse aise initialize krte
   
   vector<int> v2(3 , 10);  //3 size ka array jisme sri val 10 ho
   
   
//---------------------------------------------------------------------------------------------------
   
   //to erase elements from vector we use 'erase' function
   
   //ham ise idx se access nhi krte  blke we use begin fun and uske aage walo ko access krne k liye ham begin + 1 krdete
   
   vector<int> v5 = {2,4,6,8,10};
   
   //  v5.erase(v5.begin());      //it will erase the first value
  
	
//agr 3rd wali val dlt krni hai which is 6 here to ham begin + 2 likh denge

    //v5.erase(v5.begin() + 2);
      
   
    
    
    /*to dlt a range of val like we want t dlt 6 and 8
    /vec.erase(start , end) where start is included and end is not it means hame jo dlt krna hai usse ek aage ka num dena hoga
	 like begin + 4 krenge to 8 dlt hoga*/
	 
	 v5.erase(v5.begin() + 2 , v5.begin() + 4);
	 
	 for(int val : v5)
    {
   	  cout<<val<<" ";
    }
    
     	


   
   
   
}
