#include<iostream>
using namespace std;

class rectangle
{
	public:
		float length;
		float width;
		
		rectangle(float l, float w)
		{
			length = l;
			width = w;

		}
		
		void display()
		{
			cout<<"\nLength: "<<length<<"    width: "<<width<<endl;
			cout<<"Area of rectangle is: "<<length * width<<endl;
		}
};

int main()
	
{
	rectangle r1(3.4,8);
	r1.display();
	
	rectangle r2(7, 3);
	r2.display();
	
	rectangle r3(6.5, 5);
	r3.display();
	
	rectangle r4(4, 6);
	r4.display();

	return 0;
}
