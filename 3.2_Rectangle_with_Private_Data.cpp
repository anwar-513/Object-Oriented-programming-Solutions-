#include<iostream>
using namespace std;

class Rectangle {
private:
    int length;
    int width;

public:
    void setDimensions(int l, int w) {
        if(l > 0)
		{
			if( w > 0)
		  	{
	          length = l;
	          width = w;
	       	}
        }
        else {
            cout << "Invalid Entries\n";
        }
    }

    int area() {
        return length * width;
    }
};

int main() {
    Rectangle r1;

    r1.setDimensions(5, 6);     
    cout  <<"The given rectangle is "<< r1.area() << endl;

    return 0;
}
