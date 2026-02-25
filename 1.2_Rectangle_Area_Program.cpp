#include<iostream>
using namespace std;

class rectangle
{
	public:
		float length;
		float width;
		
		void area()
		{
			int area;
			
			area = length * width;
			
			cout<<"The area of ractangle by  the value  "<<area<<endl;
		}
};

int main()
{
	rectangle rec1;
	
	cout<<"Enter the length for rectangle---> ";
	cin>>rec1.length;
	
	cout<<"Enter the width for rectangle---> ";
	cin>>rec1.width;
	
	rec1.area();
	
	
	
	return 0;
}