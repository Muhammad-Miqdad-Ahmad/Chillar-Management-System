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

bool Person::operator!=(Person &data)
{
    if (this->ID != data.ID)
        if (this->name != data.name)
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
    if (this->ID <= data.ID)
        return true;
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

ofstream &operator<<(ofstream &out, Person &data)
{
    out << data.name << endl;
    out << data.ID << endl;
    return out;
}

istream &operator>>(istream &in, Person &data)
{
    cout << "Enter the name of the person: ";
    getline(in, data.name);
    cout << "Enter the Id of the person: ";
    in >> data.ID;
    return in;
}

ifstream &operator>>(ifstream &in, Person &data)
{
    getline(in, data.name);
    getline(in, data.ID);
    return in;
}

Convicted::Convicted() : Person()
{
    this->age = "";
    this->weight = "";
    this->crime = "";
    this->height = "";
}

// ofstream &operator<<(ofstream &out, Convicted &data)
// {
//     out << data.ID << endl;
//     out << data.name << endl;
//     return out;
// }

istream &operator>>(istream &in, Convicted &data)
{
    // in >> data;
    cout << "Enter the name of the convicted: ";
    cin.ignore();
    getline(cin,data.name);
    cout << "Enter the age of the convicted: ";
    in >> data.age;
    cout << "Enter the height in feets of the convicted: ";
    in >> data.height_ft;
    cout << "Enter the height in inches of the convicted: ";
    in >> data.height_in;
    data.height=data.height_ft+"'"+data.height_in+"\"";
    cout << "Enter the weight of the convicted: ";
    cin.ignore();
    getline(in, data.weight);
    cout << "Enter the sentence of the convicted: ";
    cin.ignore();
    getline(in,data.sentence);
    in >> data.captured_on;
    in >> data.expected_release;
    cout << "What was the crime: ";
    cin.ignore();
    getline(in, data.crime);
    return in;
}

ifstream &operator>>(ifstream &in, Convicted &data)
{
    in >> data;
    getline(in, data.age);
    getline(in, data.height);
    getline(in, data.weight);
    getline(in, data.sentence);
    in >> data.captured_on;
    in >> data.expected_release;
    getline(in, data.crime);
    return in;
}

ostream &operator<<(ostream &out, Convicted &data)
{
    out << data;
    out << "The age of the convicted is: " << data.age << endl;
    out << "The height of the convicted is: " << data.height << endl;
    out << "The weight of the convicted is: " << data.weight << endl;
    out << "The sentence of the convicted is: " << data.sentence << endl;
    out << "The convicted was captured on: " << data.captured_on << endl;
    out << "The convicted is expected to be released on: " << data.expected_release << endl;
    out << "The crime of the conviceted is: " << data.crime << endl
        << endl;
    return out;
}

ofstream &operator<<(ofstream &out, Convicted &data)
{
    out << endl;
    out << data.name << endl;
    out << data.ID << endl;
    out << data.age << endl;
    out << data.height << endl;
    out << data.weight << endl;
    out << data.sentence << endl;
    out << data.captured_on << endl;
    out << data.expected_release << endl;
    out << data.crime << endl;
    return out;
}

Capture_date::Capture_date()
{
    this->date="";
    this->month="";
    this->year="";
}

ostream &operator<<(ostream &out, Capture_date &data)
{
    out << data.month << " " <<data.date << ", " << data.year << endl;
    return out;
}

istream &operator>>(istream &in, Capture_date &data)
{
    cout << "Enter the month of capture: ";
    in >> data.month;
    cout << "Enter the date of the capture: ";
    in >> data.date;
    cout << "Enter the year of the capture: ";
    in >> data.year;
    return in;
}

ofstream &operator<<(ofstream &out, Capture_date &data)
{
    out << data.month << " " <<data.date << ", " << data.year;
    return out;
}

ifstream &operator>>(ifstream &in, Capture_date &data)
{
    in >> data.month;
    in >> data.date;
    in >> data.year;
    return in;
}
