#include<iostream>
using namespace std;

class Employee 
{
private:
    int* salary;

public:
    Employee(int s) 
	{
        salary = new int;
        *salary = s;
    }

    void setSalary(int s) 
	{
        if(s > 0)
            *salary = s;
    }

    int getSalary() 
	{
        return *salary;
    }

    ~Employee() 
	{
        delete salary;
    }
};

int main() {
    Employee e1(50000);

    cout<<"Salary: "<<e1.getSalary()<<endl;

    e1.setSalary(60000);

    cout<<"Updated Salary: "<<e1.getSalary()<<endl;

    return 0;
}
