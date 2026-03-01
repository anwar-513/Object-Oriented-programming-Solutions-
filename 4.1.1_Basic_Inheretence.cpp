#include<iostream>
using namespace std;

class person
{
	protected:
		string name;
		string fatherName;
		short age;
		
	public:
		person(string name, string fatherName,short age)
		{
			this->fatherName = fatherName ;
			this->name = name;
			this->age = age;
		}
	virtual void display()
		{
			cout<<"\nName	      "<<name;
			cout<<"\nFather Name   "<<fatherName;
			cout<<"\nAge           "<<age;
		}
};

class student : public person
{
	private:
		string major;
		int rollNumber;
	
	public:
		student(string name, string fatherName, short age, string major, int rollNumber) : person(name, fatherName, age)
		{
			this->major = major;
			this->rollNumber = rollNumber;
		}
		
		void display() override
		{
			cout<<"\n\n~~~~~~Student~~~~~~~~";
			person::display();
			cout<<"\nMajor         "<<major;
			cout<<"\nRollnumber    "<<rollNumber;
		}
};

int main()
{
	student s1("Anwar", "ShamShad Khan", 19,"Computer Science", 77);
	student s2("Bilal", "Kamal", 20,"Art", 78);
	
	
	s1.display();
	s2.display();
		
	return 0;
}
