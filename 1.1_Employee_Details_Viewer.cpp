#include<iostream>
using namespace std;

class employee
{
	public:
		int id;
		string name;
		int salary;
	
	void display()
	{
		cout<<"ID       "<<id<<endl;
		cout<<"Name     "<<name<<endl;
		cout<<"salary   "<<salary<<endl;
		cout<<"_____________________"<<endl;
	}
};

int main()
{	
	employee e1, e2;
	
	e1.id = 1001;
	e1.name = "Khan";
	e1.salary = 10000;
	
	e2.id = 1002;
	e2.name = "jan";
	e2.salary = 12000;
	
	e1.display();
	e2.display();
	
	 

	
	return 0;
}