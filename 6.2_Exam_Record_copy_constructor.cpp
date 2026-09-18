/*          PROBLEM STATEMENT
Create a C++ class named "Exam" designed to manage student exam records,
complete with a shallow copy implementation. Define attributes such as student name,
exam date, and score within the class, and include methods to set these attributes
and display exam details. As part of this exercise, intentionally omit the
implementation of the copy constructor and copy assignment operator. Afterward,
create an instance of the "Exam" class, generate a shallow copy, and observe
any resulting issues. Then solve the issue using any OOP technique.
*/

#include <iostream>
#include <string>
using namespace std;

// -------------------------------------------------------
// STEP 1: Exam class WITHOUT a copy constructor
// This will use the default shallow copy given by C++
// -------------------------------------------------------
class Exam
{
    private:
        string name;
        string date;
        int* score;   // pointer, so shallow copy will cause a problem

    public:

        // default constructor
        Exam()
        {
            score = nullptr;
        }

        // normal constructor
        Exam(string iname, string idate, int iscore)
        {
            name = iname;
            date = idate;
            score = new int;
            *score = iscore;
        }

        // destructor
        ~Exam()
        {
            delete score;
        }

        void setName(string iname)
        {
            name = iname;
        }

        void setDate(string idate)
        {
            date = idate;
        }

        void setScore(int iscore)
        {
            if (score == nullptr)
            {
                score = new int;
            }
            *score = iscore;
        }

        void display()
        {
            cout << "Name:  " << name << endl;
            cout << "Date:  " << date << endl;
            cout << "Score: " << *score << endl;
            cout << "Address of score: " << score << endl;
        }

        // NOTE: no copy constructor and no copy assignment operator
        // written here on purpose. C++ will create its own default
        // versions, and those default versions only do a SHALLOW copy.
};


// -------------------------------------------------------
// STEP 2: ExamFixed class WITH a copy constructor
// This one does a DEEP copy, so the bug is solved
// -------------------------------------------------------
class ExamFixed
{
    private:
        string name;
        string date;
        int* score;

    public:

        ExamFixed()
        {
            score = nullptr;
        }

        ExamFixed(string iname, string idate, int iscore)
        {
            name = iname;
            date = idate;
            score = new int;
            *score = iscore;
        }

        // copy constructor written by us (this is the fix)
        ExamFixed(ExamFixed &other)
        {
            name = other.name;
            date = other.date;
            score = new int;          // make a brand new int
            *score = *(other.score);  // copy the VALUE, not the address
        }

        // copy assignment operator written by us (this is the fix)
        ExamFixed& operator=(ExamFixed &other)
        {
            if (this == &other)
            {
                return *this;
            }

            delete score;              // free the memory we already had
            name = other.name;
            date = other.date;
            score = new int;
            *score = *(other.score);

            return *this;
        }

        ~ExamFixed()
        {
            delete score;
        }

        void setName(string iname)
        {
            name = iname;
        }

        void setDate(string idate)
        {
            date = idate;
        }

        void setScore(int iscore)
        {
            if (score == nullptr)
            {
                score = new int;
            }
            *score = iscore;
        }

        void display()
        {
            cout << "Name:  " << name << endl;
            cout << "Date:  " << date << endl;
            cout << "Score: " << *score << endl;
            cout << "Address of score: " << score << endl;
        }
};


int main()
{
    cout << "------------------------------------------" << endl;
    cout << "PART 1: SHALLOW COPY (the problem)" << endl;
    cout << "------------------------------------------" << endl;

    Exam student1;
    student1.setName("Anwar");
    student1.setDate("01/01/2001");
    student1.setScore(45);

    Exam student2 = student1;   // this calls the default shallow copy

    cout << endl << "Right after copying:" << endl;
    cout << "student1 -> " << endl;
    student1.display();
    cout << "student2 -> " << endl;
    student2.display();

    cout << endl << "Look at the addresses above. They are the SAME." << endl;
    cout << "That means student1 and student2 are sharing one memory box." << endl;

    cout << endl << "Now we change student2's score to 99..." << endl;
    student2.setScore(99);

    cout << "student1 -> " << endl;
    student1.display();
    cout << "student2 -> " << endl;
    student2.display();

    cout << endl << "PROBLEM: student1's score changed too, even though we";
    cout << " only changed student2!" << endl;
    cout << "Also, when the program ends, both objects will try to delete";
    cout << " the same memory, which is a bug (double free)." << endl;


    cout << endl << "------------------------------------------" << endl;
    cout << "PART 2: DEEP COPY (the fix)" << endl;
    cout << "------------------------------------------" << endl;

    ExamFixed e1;
    e1.setName("Anwar");
    e1.setDate("01/01/2001");
    e1.setScore(45);

    ExamFixed e2 = e1;   // this now calls OUR copy constructor

    cout << endl << "Right after copying:" << endl;
    cout << "e1 -> " << endl;
    e1.display();
    cout << "e2 -> " << endl;
    e2.display();

    cout << endl << "Look at the addresses now. They are DIFFERENT." << endl;
    cout << "e1 and e2 each have their own memory box." << endl;

    cout << endl << "Now we change e2's score to 99..." << endl;
    e2.setScore(99);

    cout << "e1 -> " << endl;
    e1.display();
    cout << "e2 -> " << endl;
    e2.display();

    cout << endl << "FIXED: e1 is still 45, only e2 changed to 99." << endl;

    return 0;
}