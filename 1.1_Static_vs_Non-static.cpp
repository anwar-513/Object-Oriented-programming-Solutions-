#include <iostream>
using namespace std;

class Subway
{
public:
    int score;
    int coin;

    static int highestScore; // inside class
    static int totalCoin;    // inside class

    void game()
    {
        cout << "Score---> ";
        cin >> score;
        cout << "Coin---> ";
        cin >> coin;

        totalCoin = totalCoin + coin;

        if (score > highestScore)
        {
            highestScore = score;
        }
    }

    void display()
    {
        cout << "Total Coin    :   " << totalCoin << endl;
        cout << "Highest Score :   " << highestScore << endl;
    }
};

// define static variables outside
int Subway::highestScore = 0;
int Subway::totalCoin = 0;

int main()
{
    Subway s1, s2, s3;

    cout << "````Game 1````````" << endl;
    s1.game();
    s1.display();

    cout << "````Game 2````````" << endl;
    s2.game();
    s2.display();

    cout << "````Game 3````````" << endl;
    s3.game();
    s3.display();

    return 0;
}