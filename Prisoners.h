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

    //functions
    void cal_expected_date(Capture_date cap_on, string sentence);

    // stream operators overload
    friend ostream &operator<<(ostream &out, Capture_date &data);
    friend ofstream &operator<<(ofstream &out, Capture_date &data);
    friend istream &operator>>(istream &in, Capture_date &data);
    friend ifstream &operator>>(ifstream &in, Capture_date &data);
};

class abstract
{
public:
    string ID;
    string name;
    virtual void display() = 0;
    virtual void read(ifstream &file) = 0;
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

class Person : public abstract
{
public:
    // data stored

    // constructors
    Person();
    Person(string ID, string name);

    // destructor
    ~Person();

    // functions
    void display() override;
    void read(ifstream &file) override;

    // comparison operator overload
    bool operator<(abstract &data) override;
    bool operator<(abstract *&data) override;
    bool operator<=(abstract &data) override;
    bool operator<=(abstract *&data) override;
    bool operator>(abstract &data) override;
    bool operator>(abstract *&data) override;
    bool operator>=(abstract &data) override;
    bool operator>=(abstract *&data) override;
    bool operator==(abstract &data) override;
    bool operator==(abstract *&data) override;
    bool operator!=(abstract &data) override;
    bool operator!=(abstract *&data) override;

    // stream operators overload
    //  void display(Person* &data);
    // friend functions
    friend ostream &operator<<(ostream &out, Person &data);
    friend ofstream &operator<<(ofstream &out, Person &data);
    friend istream &operator>>(istream &in, Person &data);
    friend ifstream &operator>>(ifstream &in, Person &data);
    friend ostream &operator<<(ostream &out, Person *&data);
    friend ofstream &operator<<(ofstream &out, Person *&data);
    friend istream &operator>>(istream &in, Person *&data);
    friend ifstream &operator>>(ifstream &in, Person *&data);
};

class Convicted : public abstract
{
private:
    string age, height, weight, sentence, crime, height_ft, height_in;
    Capture_date captured_on, expected_release;
    Person *relative_1, *relative_2;

public:
    Convicted();
    // ~Convicted();

    // functions
    void display() override;
    void give_space(string yada);
    void read(ifstream &file) override;

    // comparison operator overload
    bool operator<(abstract &data) override;
    bool operator<(abstract *&data) override;
    bool operator<=(abstract &data) override;
    bool operator<=(abstract *&data) override;
    bool operator>(abstract &data) override;
    bool operator>(abstract *&data) override;
    bool operator>=(abstract &data) override;
    bool operator>=(abstract *&data) override;
    bool operator==(abstract &data) override;
    bool operator==(abstract *&data) override;
    bool operator!=(abstract &data) override;
    bool operator!=(abstract *&data) override;

    // operators overloaded
    friend ostream &operator<<(ostream &out, Convicted &data);
    friend ofstream &operator<<(ofstream &out, Convicted &data);
    friend istream &operator>>(istream &in, Convicted &data);
    friend ifstream &operator>>(ifstream &in, Convicted &data);
    friend ostream &operator<<(ostream &out, Convicted *&data);
    friend ofstream &operator<<(ofstream &out, Convicted *&data);
    friend istream &operator>>(istream &in, Convicted *&data);
    friend ifstream &operator>>(ifstream &in, Convicted *&data);
};

class Prisoners
{
private:
    abstract *root;
    Person *relative_1;
    Person *relative_2;

    // directions to form a tree
    Prisoners *left, *right;

public:
    // constructors
    Prisoners();
    Prisoners(abstract *data);
    // Prisoners(Convicted *data);

    // destructors
    ~Prisoners();

    // friend classes
    friend class Hierarchy;

    //functions
    void re_write(string file_name);

    // friend functions
    friend int partition(vector<Prisoners *> &array, int first, int last);
    friend void quick_sort(vector<Prisoners *> &array, int first, int last);
    friend ostream &operator<<(ostream &out, Prisoners *data);
    // friend Prisoners *operator%(Prisoners *&chunk, string data); // this is the % operator overload that is basically the search function.
};