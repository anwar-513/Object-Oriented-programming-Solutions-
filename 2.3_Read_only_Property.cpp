#include<iostream>
using namespace std;

class Person 
{
	private:
	    string cnic;
	
	public:
	    Person(string id) 
		{
	        cnic = id;
	    }
	    string getCnic() 
		{
	        return cnic;
	    }

};

int main()
{
    Person person1("123123123123");     
    
    cout<<"The CNIC is "<<person1.getCnic();   
    
    return 0;
}
