#include <iostream>
#include <vector>
using namespace std;

class abstract
{
public:
    string ID;
    string name;

    // functions
    virtual void display() = 0;
    virtual void write(ofstream &file) =0;
    virtual void read(ifstream &file) = 0;

    // comparison operator overload
    virtual bool operator<(abstract &data) = 0;
    virtual bool operator<(abstract *&data) = 0;
    virtual bool operator<=(abstract &data) = 0;
    virtual bool operator<=(abstract *&data) = 0;
    virtual bool operator>(abstract &data) = 0;
    virtual bool operator>(abstract *&data) = 0;
    virtual bool operator>=(abstract &data) = 0;
    virtual bool operator>=(abstract *&data) = 0;
    virtual bool operator==(abstract &data) = 0;
    virtual bool operator==(abstract *&data) = 0;
    virtual bool operator!=(abstract &data) = 0;
    virtual bool operator!=(abstract *&data) = 0;
};
