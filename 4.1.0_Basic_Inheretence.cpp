#include<iostream>
using namespace std;

class person
{
	protected:
		string name;
		string fatherName;
		short age;
		
		public:
			void setPerson(string name, string fatherName,int age)
			{
				this->fatherName = fatherName ;
				this->name = name;
				this->age = age;
			}
			
			void displayPerson()
			{
				cout<<"Name:         "<<name<<endl;
				cout<<"Father Name:  "<<fatherName<<endl;
				cout<<"Age:          "<<age<<endl;
			}
};

class student : public person
{
	private:
		int rollNumber;
	
	public:
		void setRollNo(int rollNumber) 
		{
			this->rollNumber = rollNumber;
		}
		
		void studentDisplay()
		{
			displayPerson();
			cout<<"Rollnumber:   "<<rollNumber;
		}
};

int main()
{
	student s1;
	
	s1.setPerson("Anwar","ShamShad Khan", 19);
	s1.setRollNo(666);
	
	
	s1.studentDisplay();
	
	return 0;
}
