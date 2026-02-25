#include<iostream>
using namespace std;

class Age 
{
private:
    int age;

public:
    void setAge(int a) {
        if(a >= 0 && a <= 120)
            age = a;
        else
            cout << "Invalid Age!" << endl;
    }

    int getAge() 
	{
        return age;
	}
};

int main()
{
	Age person1;
	
	person1.setAge(16);
	cout<<"The given age is "<<person1.getAge();
	
	return 0;
}
