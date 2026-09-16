/*        PROBLEM
1. Suppose you are developing a bank account management system, and you have defined the
BankAccount class with the required constructors. You need to demonstrate the use of these
constructors in various scenarios.
a) Default Constructor Usage:
Create a default-initialized BankAccount object named account1. Print out the balance of
account1.
b) Parameterized Constructor Usage:
Create a BankAccount object named account2 with an initial balance of $1000. Print out the
balance of account2.
c) Copy Constructor Usage:
Using the account2 you created earlier, create a new BankAccount object named account3 using
the copy constructor. Deduct $200 from account3 and print out its balance. Also, print out the
balance of account2 to ensure it hasn't been affected by the transaction involving account3. Note:
assume the variables in your case and print out the details.
*/


#include<iostream>
#include<string>
using namespace std;


class Bank {
    public:
        double ammount;
        string name;

    Bank(){     
    }
    
    Bank(string name, double ammount)
    {
        this->name = name;
        this->ammount = ammount;
    }

    Bank(const Bank& account)
    {
        this->name = name;
        this->ammount = ammount;
    }

    void info(){
        cout<<"Name:      "<<name<<endl;
        cout<<"Ammount:   "<<ammount<<endl;
    }

};

int main()
{
    Bank acc1, acc2("Anwar", 1200);

    acc1.ammount = 1000;
    acc1.name = "Qais";


    Bank acc3(acc2);
    acc3.ammount -= 200;
    acc3.name = "Manan";

    
    cout << "_________Account1_____________" << endl;
    acc1.info();

    cout <<"__________Account2___________:" << endl;
    acc2.info();

    cout << "_________Account3_____________200 deducted" << endl;
    acc3.info();




    return 0; 
}