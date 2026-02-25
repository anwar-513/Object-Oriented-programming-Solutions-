#include<iostream>
using namespace std;

class Counter {
private:
    static int count;

public:
    Counter() {
        count++;
    }

    static int getCount() {
        return count;
    }
};

int Counter::count = 0;

int main() {
    Counter c1;
    Counter c2;
    Counter c3;

    cout << "Total Objects Created: " << Counter::getCount() << endl;

    return 0;
}
