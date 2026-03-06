#include<iostream>
using namespace std;

class delivery
{
	protected:
		int id;
		double cost;
		string costumerName;
	
	public:
		
		void displayinfo(int id, double cost, string costumerName)
		{
			cout<<"~~~~~~~~~~~Simple Delivery~~~~~~~~~~~"<<endl;
			cout<<"ID               "<<id<<endl;
			cout<<"Delivery Cost    "<<cost<<endl;
			cout<<"Costumer Name    "<<costumerName<<endl;
		}
		
};

class expressDelivery : public delivery
{
	string priorityLevel;
	
	public:
	using delivery::displayinfo;
	
	void displayinfo(int id, double cost, string costumerName, string priorityLevel)
	{
		cout<<"~~~~~~~~~~~Express Delivery~~~~~~~~~~~"<<endl;
		cout<<"ID               "<<id<<endl;
		cout<<"Delivery Cost    "<<cost<<endl;
		cout<<"Costumer Name    "<<costumerName<<endl;
		cout<<"Priority Lever   "<<priorityLevel<<endl;
	}	
};

int main()
{
	expressDelivery del1;
	
	del1.displayinfo(101, 230.95, "Anwar");
	del1.displayinfo(102, 330.5, "Bilal", "Low");
	del1.displayinfo(103, 220.7, "Ahmad");
	return 0;
}
