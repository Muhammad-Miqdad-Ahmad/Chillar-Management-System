#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Person
{
public:
    //data stored
    string ID;
    string name;
    
    // constructors
    Person();
    Person(string ID, string name);
    
    //destructor
    ~Person();

    //comparison operator overload
    bool operator < (Person &data);
    bool operator > (Person &data);
    bool operator == (Person &data);

    //stream operators overload
    friend ostream &operator << (ostream &out, Person &data);
    friend istream &operator >> (istream &in, Person &data);
};

class Prisoners
{
private:
    Person convict;
    Person *relative_1;
    Person *relative_2;
    //directions to form a tree
    Prisoners *left, *right;
public:
//constructors
    Prisoners();
    Prisoners(Person data);
//destructors
    ~Prisoners();

// friend classes
    friend class Hierarchy;

//friend functions
    friend Prisoners* operator%(Prisoners* &chunk, string data); //this is the % operator overload that is basically the search function.
};

//? This is a special class that will inherit the Person class. 
//? THis will be an extended version of the same person class designed to hold the prisoner data

class Convicted:Person
{
private:
    string height, weight, sentence, captured_on, expected_release, crime;
public:
    Convicted();
    ~Convicted();
};