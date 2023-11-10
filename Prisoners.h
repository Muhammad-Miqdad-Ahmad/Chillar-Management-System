#pragma once
#include <iostream>
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
    bool operator== (Person &data);

    //stream operators overload
    friend ostream &operator << (ostream &out, Person &data);
    friend istream &operator >> (istream &in, Person &data);
};
class Prisoners
{
private:
    Person data;
    Person Relative_1;
    Person Relative_2;
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
    friend Prisoners* operator%(Prisoners* &chunk, string data);
};

//// class Prisoners_tree
//// {
//// private:
////     Prisoners *root;
//// public:
////     Prisoners_tree(/* args */);
////     ~Prisoners_tree();
//// };