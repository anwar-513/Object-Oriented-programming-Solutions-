#include<iostream>
using namespace std;

class account
{
protected:
    double balance;

public:
    account(double bal) : balance(bal)
    {
    }

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void displayBalance() = 0;

    virtual ~account()
    {
    }
};


class savingAccount : public account
{
public:
    savingAccount(double bal) : account(bal)
    {
    }

    void deposit(double amount) override
    {
        balance += amount;
        cout << "Deposited in Saving Account: " << amount << endl;
    }

    void withdraw(double amount) override
    {
        if(amount > balance)
        {
            cout << "Insufficient balance in Saving Account!" << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrawn from Saving Account: " << amount << endl;
        }
    }

    void displayBalance() override
    {
        cout << "Saving Account Balance: " << balance << endl;
    }
};

class currentAccount : public account
{
public:
    currentAccount(double bal) : account(bal)
    {
    }

    void deposit(double amount) override
    {
        balance += amount;
        cout << "Deposited in Current Account: " << amount << endl;
    }

    void withdraw(double amount) override
    {
        if(amount > balance)
        {
            cout << "Insufficient balance in Current Account!" << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrawn from Current Account: " << amount << endl;
        }
    }

    void displayBalance() override
    {
        cout << "Current Account Balance: " << balance << endl;
    }
};

int main()
{
    
    account* acc1;
    account* acc2;

    
    savingAccount s(5000);
    currentAccount c(10000);

    acc1 = &s;
    acc2 = &c;

    cout << "===== Saving Account =====" << endl;
    acc1->deposit(2000);
    acc1->withdraw(1000);
    acc1->displayBalance();

    cout << endl;

    cout << "<===== Current Account =====>"<<endl;
    acc2->deposit(3000);
    acc2->withdraw(4000);
    acc2->displayBalance();

    return 0;
}