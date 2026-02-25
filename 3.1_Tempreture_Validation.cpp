#include<iostream>
using namespace std;

class Temperature {
private:
    float celsius;

public:
    void setTemp(float temp)
	{
        if(temp >= -273)
            celsius = temp;
        else
            cout << "The Tempreture can never exist\n";
    }

    float getTemp() 
	{
        return celsius;
    }
};

int main() 
{
    Temperature temp1;

    temp1.setTemp(18);         
    cout << "The Temperature is  " << temp1.getTemp() << " C\n";

    temp1.setTemp(-274);        

    return 0;
}
