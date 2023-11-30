#include <iostream>
#include <vector>
using namespace std;

class abstract
{
public:
    string ID;
    string name;

    // functions
    virtual void input() = 0;
    virtual void modify() = 0;
    virtual void display() = 0;
    virtual void read(ifstream &file) = 0;
    virtual void write(ofstream &file) = 0;

    // comparison operator overload
    virtual bool less_than(abstract &data) = 0;
    virtual bool less_than(abstract *&data) = 0;
    virtual bool less_than_equal(abstract &data) = 0;
    virtual bool less_than_equal(abstract *&data) = 0;
    virtual bool greater_than(abstract &data) = 0;
    virtual bool greater_than(abstract *&data) = 0;
    virtual bool greater_than_equal(abstract &data) = 0;
    virtual bool greater_than_equal(abstract *&data) = 0;
    virtual bool equal(abstract &data) = 0;
    virtual bool equal(abstract *&data) = 0;
    virtual bool not_equal(abstract &data) = 0;
    virtual bool not_equal(abstract *&data) = 0;

    // ipnut output functions
};
