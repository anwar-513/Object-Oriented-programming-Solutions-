#include<iostream>
using namespace std;

class BankAccount 
{
private:
    double balance;

public:
    BankAccount() 
	{
        balance = 0;
    }

    void deposit(double amount) 
	{
        if(amount > 0)
            balance += amount;
    }

    void withdraw(double amount) {
        if(amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient Funds\n";
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account;

    account.deposit(5000);        
    account.withdraw(2000);       
    account.withdraw(4000);       

    cout << "Current Balance: " << account.getBalance() << endl;

    return 0;
}
