#include "Addons.h"

Person::Person()
{
    this->ID = "";
    this->name = "";
}

Person::~Person()
{
}
// all the comparison operatos have been overloaded for the objects of the class
bool Person::operator==(abstract &data)
{
    if (this->ID == data.ID)
        if (this->name == data.name)
            return true;
    return false;
}

bool Person::operator!=(abstract &data)
{
    if (this->ID != data.ID)
        if (this->name != data.name)
            return true;
    return false;
}

bool Person::operator<(abstract &data)
{
    if (this->ID < data.ID)
        return true;
    return false;
}

bool Person::operator<=(abstract &data)
{
    if (this->ID <= data.ID)
    {
        return true;
    }
    return false;
}

bool Person::operator>(abstract &data)
{
    if (this->ID > data.ID)
        return true;
    return false;
}

bool Person::operator>=(abstract &data)
{
    if (this->ID >= data.ID)
        return true;
    return false;
}
// all the operators have been overloaded for the pointers of the class.
bool Person::operator==(abstract *&data)
{
    if (this->ID == data->ID)
        if (this->name == data->name)
            return true;
    return false;
}

bool Person::operator!=(abstract *&data)
{
    if (this->ID != data->ID)
        if (this->name != data->name)
            return true;
    return false;
}

bool Person::operator<(abstract *&data)
{
    if (this->ID < data->ID)
        return true;
    return false;
}

bool Person::operator<=(abstract *&data)
{
    if (this->ID <= data->ID)
    {
        return true;
    }
    return false;
}

bool Person::operator>(abstract *&data)
{
    if (this->ID > data->ID)
        return true;
    return false;
}

bool Person::operator>=(abstract *&data)
{
    if (this->ID >= data->ID)
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

ostream &operator<<(ostream &out, Person *&data)
{
    out << "The name of the person is: " << data->name << endl;
    out << "The Id of the person is: " << data->ID << endl
        << endl;
    return out;
}

ofstream &operator<<(ofstream &out, Person &data)
{
    out << data.name << endl;
    out << data.ID << endl;
    return out;
}

ofstream &operator<<(ofstream &out, Person *&data)
{
    out << data->name << endl;
    out << data->ID << endl;
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

istream &operator>>(istream &in, Person *&data)
{
    cout << "Enter the name of the person: ";
    getline(in, data->name);
    cout << "Enter the Id of the person: ";
    in >> data->ID;
    return in;
}

ifstream &operator>>(ifstream &in, Person &data)
{
    getline(in, data.name);
    getline(in, data.ID);
    return in;
}

ifstream &operator>>(ifstream &in, Person *&data)
{
    getline(in, data->name);
    getline(in, data->ID);
    return in;
}

void Person::display()
{
    cout << "The name of the person is: " << this->name << endl;
    cout << "The Id of the person is: " << this->ID << endl
         << endl;
}

Capture_date::Capture_date()
{
    this->date = "";
    this->month = "";
    this->year = "";
}

ostream &operator<<(ostream &out, Capture_date &data)
{
    out << data.month << " " << data.date << " " << data.year;
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
    out << data.month << " " << data.date << ", " << data.year << endl;
    return out;
}

ifstream &operator>>(ifstream &in, Capture_date &data)
{
    string temp;
    in >> data.month;
    in >> data.date;
    // in >> data.year;
    getline(in, data.year);
    return in;
}

void Person::read(ifstream &file)
{
    string ID, name, temp;
    getline(file, name); // Prisoner name
    getline(file, ID);   // prisoner ID
    this->ID = ID;
    this->name = name;
    // now to ignore the rest of the file
    getline(file, temp); // age
    getline(file, temp); // height
    getline(file, temp); // weight
    getline(file, temp); // sentence
    getline(file, temp); // captured on
    getline(file, temp); // expected release
    getline(file, temp); // crime
    // getline(file, temp); // empty line
}

void Capture_date::cal_expected_date(Capture_date cap_on, string sentence)
{
    double num = stod(sentence); // ye string s double m number change kar k de ga
    int size = sentence.size();  // ye string ka size hai;
    string yearOrmonth;

    for (int i = 0; i < size; i++)
    {
        if (sentence[i] == 'y' || sentence[i] == 'Y') // agr sentence years m hai to yaha s year ah jai ga
        {
            yearOrmonth = "year";
            break;
        }
        if (sentence[i] == 'm' || sentence[i] == 'M') // agr sentence month m hai to yaha s month ah jai ga
        {
            yearOrmonth = "month";
            break;
        }
    }

    if (yearOrmonth == "year")
    {
        num = num * 12.0;
    }

    int monthCap;
    int yearCap = stoi(cap_on.year); // captured on wala year

    for (int i = 0; i < 12; i++)
    {
        if (Constants::monthNames[i] == cap_on.month)
        {
            monthCap = i + 1;
            break;
        }
    }

    monthCap += static_cast<int>(num);
    if (monthCap > 12)
    {
        yearCap += monthCap / 12;
        monthCap %= 12;
    }
    this->date = cap_on.date;
    this->month = Constants::monthNames[monthCap - 1];
    this->year = to_string(yearCap);
}
