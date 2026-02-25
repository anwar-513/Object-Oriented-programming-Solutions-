#include<iostream>
using namespace std;

class BankAccount
{
	public:
		double accountNumber;
		string holderName;
		float balance;
	
		void deposite()
		{
			float depositeAmmount;
			cout<<"Enter the ammount to diposite---> ";
			cin>>depositeAmmount;
			
			this-> balance = balance + depositeAmmount;
			
		}
		
		void withdraw()
		{
			float withdrawalAmmount;
			cout<<"Enter the ammount to withdraw---> ";
			cin>>withdrawalAmmount;
			
			if(withdrawalAmmount > balance)
			{
				cout<<"Error..!!"<<endl;
				return;
			}
			
			this -> balance = balance -  withdrawalAmmount;
			
		}
		
		void displayAmmount()
		{
			cout<<"The account number is "<<accountNumber<<endl;
			cout<<"Account Holder Name is "<<holderName<<endl;
			cout<<"The current amount is "<<balance<<endl;
		}
};

int main()
{
	BankAccount account1;
	
	
	
	account1.accountNumber = 01020;
	account1.holderName = "Anwar";
	account1.balance = 0;
	
	cout<<"          Menu             "<<endl;
	cout<<"1. Deposite Amount        "<<endl;
	cout<<"2. Withdraw Amount        "<<endl;
	cout<<"3. Display Amount          "<<endl;
	cout<<"4. Exit                    "<<endl;

	char choice;
	cout<<"Enter your choice---> ";
	cin>>choice;

	switch (choice)
	{
	case '1':
		account1.deposite();
		break;
	
	case '2':
		account1.withdraw();
		break;
	
	case '3':
		account1.displayAmmount();
	case '4':
		return 0;
	default:
		break;
	}
	
	

	
	
	return 0;
}
