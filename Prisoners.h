#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Capture_date
{
private:
    string month;
    string date;
    string year;

public:
    Capture_date(/* args */);

    // stream operators overload
    friend ostream &operator<<(ostream &out, Capture_date &data);
    friend ofstream &operator<<(ofstream &out, Capture_date &data);
    friend istream &operator>>(istream &in, Capture_date &data);
    friend ifstream &operator>>(ifstream &in, Capture_date &data);
};

class Person
{
public:
    // data stored
    string ID;
    string name;

    // constructors
    Person();
    Person(string ID, string name);

    // destructor
    ~Person();

    // comparison operator overload
    bool operator<(Person &data);
    bool operator<=(Person &data);
    bool operator>(Person &data);
    bool operator>=(Person &data);
    bool operator==(Person &data);
    bool operator!=(Person &data);

    // stream operators overload
    //  void display(Person* &data);
    // friend functions
    friend ostream &operator<<(ostream &out, Person &data);
    friend ofstream &operator<<(ofstream &out, Person &data);
    friend istream &operator>>(istream &in, Person &data);
    friend ifstream &operator>>(ifstream &in, Person &data);
};

class Prisoners
{
private:
    Person root;
    Person *relative_1;
    Person *relative_2;
    // directions to form a tree
    Prisoners *left, *right;

public:
    // constructors
    Prisoners();
    Prisoners(Person data);
    // destructors
    ~Prisoners();

    // friend classes
    friend class Hierarchy;

    // friend functions
    //  template<typename datatype>
    //  friend void display(datatype* &data);
    friend int partition(vector<Prisoners *> &array, int first, int last);
    friend void quick_sort(vector<Prisoners *> &array, int first, int last);
    friend ostream &operator<<(ostream &out, Prisoners *data);
    friend Prisoners *operator%(Prisoners *&chunk, string data); // this is the % operator overload that is basically the search function.
};

//? This is a special class that will inherit the Person class.
//? THis will be an extended version of the same person class designed to hold the prisoner data
class Convicted : public Person
{
private:
    string age, height, weight, sentence, crime, height_ft, height_in;
    Capture_date captured_on, expected_release;
    Person *relative_1, *relative_2;
public:
    Convicted();
    // ~Convicted();

    // functions
    void file_read(ifstream &in, Convicted &data, Person* &relative_1, Person* &relative_2);
    void file_write(ofstream &out, Convicted &data, Person* &relative_1, Person* &relative_2);

    // operators overloaded
    friend ostream &operator<<(ostream &out, Convicted &data);
    friend ofstream &operator<<(ofstream &out, Convicted &data);
    friend istream &operator>>(istream &in, Convicted &data);
    friend ifstream &operator>>(ifstream &in, Convicted &data);
};