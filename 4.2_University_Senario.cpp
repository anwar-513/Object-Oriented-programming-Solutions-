#include<iostream>
using namespace std;

class university
{
	protected:
		string name;
		string fatherName;
		double cnic;
		double contactNumber;
		short age;
		string gender;
	
	public:
		university(string name, string fatherName, double cnic, double contactNumber, short age, string gender)
		{
			this->age = age;
			this->cnic = cnic;
			this->contactNumber = contactNumber;
			this->fatherName = fatherName;
			this->gender = gender;
			this->name = name;
			
		}
		
		virtual void display()
		{
			cout<<"Name           "<<name<<endl;
			cout<<"Father Name    "<<fatherName<<endl;
			cout<<"CNIC           "<<cnic<<endl;
			cout<<"Contact Number  "<<contactNumber<<endl;
			cout<<"Gender         "<<gender<<endl;
			cout<<"Age            "<<name<<endl;
		}
};

class lecturer : public university
{
		private:
			string qualification;
			string department;
			string office;
			int numberOfClasses;
		public:
			lecturer(string name, string fatherName, double cnic, double contactNumber, short age, string gender, 
			string qualification, string department, string office, int numberOfClasses) 
			: university(name, fatherName, cnic, contactNumber, age, gender)
			{
				this->qualification = qualification;
				this->department = department;
				this->office = office;
				this->numberOfClasses = numberOfClasses;
			}
			
			void display() override
			{
				cout<<"\n~~~~~~~~~Lecturer Info~~~~~~~~~~~~"<<endl;
				university::display();
				cout<<"Qualificatio     "<<qualification<<endl;
				cout<<"Department      "<<department<<endl;
				cout<<"Office          "<<office<<endl;
				cout<<"Number of Classes     "<<numberOfClasses<<endl;
			}
};

class student : public university
{
	private:
		long rollNumber;
		float gpa;
		string major;
		string batch;
	
	public:
		student(string name, string fatherName, double cnic, double contactNumber, short age, string gender,
		long rollNumber, float gpa, string major, string batch) : university(name, fatherName, cnic, contactNumber, age, gender)
		{
			this->rollNumber = rollNumber;
			this->gpa = gpa;
			this->major = major;
			this->batch = batch;
		}
		
		void display() override
		{
			cout<<"\n~~~~~~~~Student~~~~~~~~~~~"<<endl;
			university::display();
			cout<<"Roll Number   "<<rollNumber<<endl;
			cout<<"GPA	         "<<gpa<<endl;
			cout<<"Major         "<<major<<endl;
			cout<<"Batch         "<<batch<<endl;
			
		}
};
int main()
{
	lecturer l1("Khan","Jan", 21231223, 03343234, 45, "male", "PHD", "Computing", "SF04", 5);
	student s1("Anwar", "Shamshad", 212022321312, 3338389513, 19, "male", 2550696, 3.19, "Computer Science", "2025-29");
	
	
	l1.display();
	s1.display();
	return 0;
}
