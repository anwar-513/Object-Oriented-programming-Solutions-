#include<iostream>
using namespace std;

#include <iostream>
using namespace std;

class library
{
protected:
    string title;
    string authorName;
    int id;

public:
    library(string tite, string authorName, int id)
    {
        this->title = title;
        this->authorName = authorName;
        this->id = id;
    }

    virtual void display()
    {
        cout<<"ID----> "<<id<<endl;
        cout<<"Title----> "<<title<<endl;
        cout<<"Author Name----> "<<authorName<<endl;
    }
};

class book : public library
{
private:
    int NoOfPage;
    string genre;

public:
    book(string title, string author, string genre, int id, int pageNo)
        : library(title, author, id)
    {
        this->authorName  = author;
        this->NoOfPage = pageNo;
    }

    void display() override
    {
        cout << "~~~~~ BOOK ~~~~~~\n";
        library::display();  
        cout << "Genre----> "<<genre<<endl;
        cout << "No of Pages----> "<<NoOfPage<<endl;
    }
};

class Magazine : public library
{
private:
    int issueNumber;
    string MonthOfPub;

public:
    Magazine(string tite, string authorName, int id, int issue, string month)
        : library(tite, authorName, id)
    {
        issueNumber = issue;
        MonthOfPub = month;
    }

    void display() override
    {
        cout << "\n\n~~~~~ MAGAZINE ~~~~~\n";
        library::display();
        cout<<"Issue Number----> "<<issueNumber<<endl;
        cout<<"Month of Publication----> "<<MonthOfPub<<endl;
    }
};

class AudioBook : public library
{
private:
    double duration;
    string narratorName;

public:
    AudioBook(string tite, string authorName, int id, double d, string narrator)
        : library(tite, authorName, id)
    {
        duration = d;
        narratorName = narrator;
    }

    void display() override
    {
        cout << "~~~~~ AUDIO BOOK ~~~~~\n";
        library::display();
        cout<<"Duration----> "<<duration<<" mintes"<<endl;
        cout<<"Narrator Name----> "<<narratorName<<endl;
    }
};


int main()
{
    book b1("book1", "author1", "Education", 101, 510);
    book b2("book2", "author2", "Education", 102, 402);
    
    Magazine m1("magazine1", "anwar", 201, 1232, "January");
    Magazine m2("magazine2", "Ali", 202, 1231, "march");
    
    

    AudioBook a1("Atomic Habits", "James Clear", 301, 35.5, "John Smith");
    AudioBook a2("Atomic Habits3", "James Clear3", 301, 23.5, "John Smith1");
	
	b1.display();
    b2.display();

    m1.display();
    m1.display();

    
    a1.display();
    a2.display();
    
    return 0;
}

