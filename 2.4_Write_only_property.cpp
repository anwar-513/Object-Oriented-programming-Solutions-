#include<iostream>
using namespace std;

class Password 
{
private:
    string pass;

public:
    void setPassword(string p) 
	{
        pass = p;
    }

    string getPassword() 
	{
        return pass;
    }
};

int main()
{
    Password p1;

    p1.setPassword("'Anwar..'");      
    cout<<"The password is "<<p1.getPassword();       

    return 0;
}
