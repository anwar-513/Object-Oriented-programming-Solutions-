#include<iostream>
using namespace std;

class vehicle
{
	private:
		int id;
		double parkingFee;
		string ownerName;
	
	protected:
		void displayinfo(int id, double parkingFee, string ownerName)
		{
			cout<<"~~~~~~~~~~~Simple Parking~~~~~~~~~~"<<endl;
			cout<<"ID               "<<id<<endl;
			cout<<"Parking Fee      "<<parkingFee<<endl;
			cout<<"Owner Name       "<<ownerName<<endl;
		}
};

class vipVehicle : public vehicle
{
	string vipLevel;
	
	public:
		using vehicle::displayinfo;
		
		void displayinfo(int id, double parkingFee, string ownerName, string vipLevel)
		{
			cout<<"~~~~~~~~~~~VIP Parking~~~~~~~~~~"<<endl;
			cout<<"ID               "<<id<<endl;
			cout<<"Parking Fee      "<<parkingFee<<endl;
			cout<<"Owner Name       "<<ownerName<<endl;
			cout<<"VIP Level        "<<vipLevel<<endl;
		}
};

int main()
{
	vipVehicle vehicle1;
	
	vehicle1.displayinfo(123, 350.5, "Anwar", "Gold");	
	vehicle1.displayinfo(132, 250.5, "Shayan");
	vehicle1.displayinfo(134, 350.5, "Hamad", "platinum");
	vehicle1.displayinfo(136, 250.5, "Abbas");
	
	return 0;

}



