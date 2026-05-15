#include <iostream>
using namespace std;

class Sum
{
private:
    int sum;

public:
    friend int addFriend(Sum &s, int a, int b);
};

int addFriend(Sum &s, int a, int b)
{
    s.sum = a + b;
    return s.sum;
}

int main()
{
    int a, b;
    cout << "Enter 1st numbers---> ";
    cin >> a;
    cout << "Enter 2nd numbers---> ";
    cin >> b;

    Sum s;
    cout << "The sum of " << a << " and " << b << " is " << addFriend(s, a, b) << endl;

    return 0;
}