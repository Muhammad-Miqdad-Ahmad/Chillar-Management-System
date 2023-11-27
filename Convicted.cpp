#include "Addons.h"

bool Convicted::operator==(abstract &data)
{
    if (this->ID == data.ID)
        if (this->name == data.name)
            return true;
    return false;
}

bool Convicted::operator!=(abstract &data)
{
    if (this->ID != data.ID)
        if (this->name != data.name)
            return true;
    return false;
}

bool Convicted::operator<(abstract &data)
{
    if (this->ID < data.ID)
        return true;
    return false;
}

bool Convicted::operator<=(abstract &data)
{
    if (this->ID <= data.ID)
    {
        return true;
    }
    return false;
}

bool Convicted::operator>(abstract &data)
{
    if (this->ID > data.ID)
        return true;
    return false;
}

bool Convicted::operator>=(abstract &data)
{
    if (this->ID >= data.ID)
        return true;
    return false;
}

bool Convicted::operator==(abstract *&data)
{
    if (this->ID == data->ID)
        if (this->name == data->name)
            return true;
    return false;
}

bool Convicted::operator!=(abstract *&data)
{
    if (this->ID != data->ID)
        if (this->name != data->name)
            return true;
    return false;
}

bool Convicted::operator<(abstract *&data)
{
    if (this->ID < data->ID)
        return true;
    return false;
}

bool Convicted::operator<=(abstract *&data)
{
    if (this->ID <= data->ID)
    {
        return true;
    }
    return false;
}

bool Convicted::operator>(abstract *&data)
{
    if (this->ID > data->ID)
        return true;
    return false;
}

bool Convicted::operator>=(abstract *&data)
{
    if (this->ID >= data->ID)
        return true;
    return false;
}

Convicted::Convicted()
{
    this->relative_1 = nullptr;
    this->relative_2 = nullptr;
    this->ID = "";
    this->name = "";
    this->age = "";
    this->weight = "";
    this->height_ft = "";
    this->height_in = "";
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
    cout << "Enter the name of the convicted: ";
    getline(in, data.name);
    cout << "Enter the age of the convicted: ";
    in >> data.age;
    if (data.relative_1)
        in >> *data.relative_1;
    if (data.relative_2)
        in >> *data.relative_2;
    cout << "Enter the height in feet of the convicted: ";
    in >> data.height_ft;
    cout << "Enter the height in inches of the convicted: ";
    in >> data.height_in;
    data.height = data.height_ft + "'" + data.height_in + "\"";
    cout << "Enter the weight of the convicted in lbs: ";
    in >> data.weight;
    data.weight = data.weight + " lbs";
    cout << "Enter the sentence of the convicted: ";
    cin.ignore();
    getline(in, data.sentence);
    cout << "When was the convicted captured: ";
    in >> data.captured_on;
    cout << "What was the crime: ";
    cin.ignore();
    getline(in, data.crime);
    return in;
}

istream &operator>>(istream &in, Convicted* &data)
{
    cout << "Enter the name of the convicted: ";
    getline(in, data->name);
    cout << "Enter the age of the convicted: ";
    in >> data->age;
    if (data->relative_1)
        in >> *data->relative_1;
    if (data->relative_2)
        in >> *data->relative_2;
    cout << "Enter the height in feet of the convicted: ";
    in >> data->height_ft;
    cout << "Enter the height in inches of the convicted: ";
    in >> data->height_in;
    data->height = data->height_ft + "'" + data->height_in + "\"";
    cout << "Enter the weight of the convicted in lbs: ";
    in >> data->weight;
    data->weight = data->weight + " lbs";
    cout << "Enter the sentence of the convicted: ";
    cin.ignore();
    getline(in, data->sentence);
    cout << "When was the convicted captured: ";
    in >> data->captured_on;
    cout << "What was the crime: ";
    cin.ignore();
    getline(in, data->crime);
    return in;
}

ifstream &operator>>(ifstream &in, Convicted &data)
{
    getline(in, data.ID);
    getline(in, data.name);
    if (data.relative_1)
        in >> *data.relative_1;
    if (data.relative_2)
        in >> *data.relative_2;
    getline(in, data.age);
    getline(in, data.height);
    getline(in, data.weight);
    getline(in, data.sentence);
    in >> data.captured_on;
    in >> data.expected_release;
    getline(in, data.crime);
    return in;
}

ifstream &operator>>(ifstream &in, Convicted* &data)
{
    getline(in, data->ID);
    getline(in, data->name);
    if (data->relative_1)
        in >> *data->relative_1;
    if (data->relative_2)
        in >> *data->relative_2;
    getline(in, data->age);
    getline(in, data->height);
    getline(in, data->weight);
    getline(in, data->sentence);
    in >> data->captured_on;
    in >> data->expected_release;
    getline(in, data->crime);
    return in;
}

ostream &operator<<(ostream &out, Convicted &data)
{
    out << "The name of the convicted is: " << data.name << endl;
    out << "The ID of the convicted is: " << data.ID << endl;
    if (data.relative_1)
        out << *data.relative_1;
    if (data.relative_2)
        out << *data.relative_2;
    out << "The age of the convicted is: " << data.age << endl;
    out << "The height of the convicted is: " << data.height << endl;
    out << "The weight of the convicted is: " << data.weight << endl;
    out << "The sentence of the convicted is: " << data.sentence << endl;
    out << "The convicted was captured on: " << data.captured_on << endl;
    out << "The convicted is expected to be released on: " << data.expected_release << endl;
    out << "The crimpe of the conviceted is: " << data.crime << endl
        << endl;
    return out;
}

ostream &operator<<(ostream &out, Convicted* &data)
{
    out << "The name of the convicted is: " << data->name << endl;
    out << "The ID of the convicted is: " << data->ID << endl;
    if (data->relative_1)
        out << *data->relative_1;
    if (data->relative_2)
        out << *data->relative_2;
    out << "The age of the convicted is: " << data->age << endl;
    out << "The height of the convicted is: " << data->height << endl;
    out << "The weight of the convicted is: " << data->weight << endl;
    out << "The sentence of the convicted is: " << data->sentence << endl;
    out << "The convicted was captured on: " << data->captured_on << endl;
    out << "The convicted is expected to be released on: " << data->expected_release << endl;
    out << "The crimpe of the conviceted is: " << data->crime << endl
        << endl;
    return out;
}

ofstream &operator<<(ofstream &out, Convicted &data)
{
    out << data.name << endl;
    out << data.ID << endl;
    if (data.relative_1)
        out << *data.relative_1;
    if (data.relative_2)
        out << *data.relative_2;
    out << data.age << endl;
    out << data.height << endl;
    out << data.weight << endl;
    out << data.sentence << endl;
    out << data.captured_on << endl;
    out << data.expected_release << endl;
    out << data.crime << endl;
    return out;
}

ofstream &operator<<(ofstream &out, Convicted* &data)
{
    out << data->name << endl;
    out << data->ID << endl;
    if (data->relative_1)
        out << *data->relative_1;
    if (data->relative_2)
        out << *data->relative_2;
    out << data->age << endl;
    out << data->height << endl;
    out << data->weight << endl;
    out << data->sentence << endl;
    out << data->captured_on << endl;
    out << data->expected_release << endl;
    out << data->crime << endl;
    return out;
}

void Convicted::display()
{
    cout << "The name of the convicted is: " << this->name << endl;
    cout << "The ID of the convicted is: " << this->ID << endl;
    if (this->relative_1)
        cout << *this->relative_1;
    if (this->relative_2)
        cout << *this->relative_2;
    cout << "The age of the convicted is: " << this->age << endl;
    cout << "The height of the convicted is: " << this->height << endl;
    cout << "The weight of the convicted is: " << this->weight << endl;
    cout << "The sentence of the convicted is: " << this->sentence << endl;
    cout << "The convicted was captured on: " << this->captured_on << endl;
    cout << "The convicted is expected to be released on: " << this->expected_release << endl;
    cout << "The crimpe of the conviceted is: " << this->crime << endl
        << endl;
}

void Convicted::read(ifstream &in)
{
    getline(in, this->ID);
    getline(in, this->name);
    getline(in, this->age);
    getline(in, this->height);
    getline(in, this->weight);
    getline(in, this->sentence);
    in >> this->captured_on;
    in >> this->expected_release;
    getline(in, this->crime);
}


void Convicted::give_space(string yaan)
{
    if (yaan == "A" || yaan == "B" || yaan == "C")
    {
        this->relative_1 = new Person;
        this->relative_2 = new Person;
    }
}

