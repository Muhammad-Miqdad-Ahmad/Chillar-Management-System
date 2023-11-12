#include "Addons.h"

Person::Person()
{
    this->ID = "";
    this->name = "";
}

Person::~Person()
{
}

bool Person::operator==(Person &data)
{
    if (this->ID == data.ID)
        if (this->name == data.name)
            return true;
    return false;
}

bool Person::operator<(Person &data)
{
    if (this->ID < data.ID)
        return true;
    return false;
}

bool Person::operator<=(Person &data)
{
    cout << "ye call ni hota ???\n";
    if (this->ID <= data.ID)
    {
        cout << "true de re hm";
        return true;
    }
    cout << "false aaya he";
    return false;
}

bool Person::operator>(Person &data)
{
    if (this->ID > data.ID)
        return true;
    return false;
}

bool Person::operator>=(Person &data)
{
    if (this->ID >= data.ID)
        return true;
    return false;
}

ostream &operator<<(ostream &out, Person &data)
{
    out << "The name of the person is: " << data.name << endl;
    out << "The Id of the person is: " << data.ID << endl
        << endl;
    return out;
}

istream &operator>>(istream &in, Person &data)
{
    cout << "Enter the name of the person is";
    in >> data.name;
    cout << "Enter the Id of the person";
    in >> data.ID;
    return in;
}
