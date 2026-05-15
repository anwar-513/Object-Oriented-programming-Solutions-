#include<iostream>
using namespace std;

class Employee
{
    private:
        int salary;

    public:
        Employee(int sal): salary(sal) {

        }

        friend void displaySalary(Employee emp1);
};



void displaySalary(Employee emp)
{
    cout<<"Salary: "<<emp.salary<<endl;
}

int main()
{
    Employee emp1(50000);
    displaySalary(emp1);
    return 0;
}