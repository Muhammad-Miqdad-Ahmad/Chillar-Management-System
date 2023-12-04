#pragma once
#include "Abstract.h"

class Capture_date
{
private:
    string month;
    string date;
    string year;

public:
    Capture_date(/* args */);

    // functions
    void cal_expected_date(Capture_date cap_on, string sentence);

    // stream operators overload
    friend ostream &operator<<(ostream &out, Capture_date &data);
    friend ofstream &operator<<(ofstream &out, Capture_date &data);
    friend istream &operator>>(istream &in, Capture_date &data);
    friend ifstream &operator>>(ifstream &in, Capture_date &data);
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
    void input() override;
    void modify() override;
    void display() override;
    bool is_empty() override;
    void read(ifstream &file) override;
    void write(ofstream &file) override;

    // comparison operator overload
    bool operator<(abstract &data);
    bool operator<(abstract *&data);
    bool operator<=(abstract &data);
    bool operator<=(abstract *&data);
    bool operator>(abstract &data);
    bool operator>(abstract *&data);
    bool operator>=(abstract &data);
    bool operator>=(abstract *&data);
    bool operator==(abstract &data);
    bool operator==(abstract *&data);
    bool operator!=(abstract &data);
    bool operator!=(abstract *&data);
    bool less_than(abstract &data) override;
    bool less_than(abstract *&data) override;
    bool less_than_equal(abstract &data) override;
    bool less_than_equal(abstract *&data) override;
    bool greater_than(abstract &data) override;
    bool greater_than(abstract *&data) override;
    bool greater_than_equal(abstract &data) override;
    bool greater_than_equal(abstract *&data) override;
    bool equal(abstract &data) override;
    bool equal(abstract *&data) override;
    bool not_equal(abstract &data) override;
    bool not_equal(abstract *&data) override;

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

public:
    Convicted();
    // ~Convicted();

    // functions
    void input() override;
    void modify() override;
    void display() override;
    bool is_empty() override;
    void give_space(string yada);
    void read(ifstream &file) override;
    void write(ofstream &file) override;

    // comparison operator overload
    bool operator<(abstract &data);
    bool operator<(abstract *&data);
    bool operator<=(abstract &data);
    bool operator<=(abstract *&data);
    bool operator>(abstract &data);
    bool operator>(abstract *&data);
    bool operator>=(abstract &data);
    bool operator>=(abstract *&data);
    bool operator==(abstract &data);
    bool operator==(abstract *&data);
    bool operator!=(abstract &data);
    bool operator!=(abstract *&data);
    bool less_than(abstract &data) override;
    bool less_than(abstract *&data) override;
    bool less_than_equal(abstract &data) override;
    bool less_than_equal(abstract *&data) override;
    bool greater_than(abstract &data) override;
    bool greater_than(abstract *&data) override;
    bool greater_than_equal(abstract &data) override;
    bool greater_than_equal(abstract *&data) override;
    bool equal(abstract &data) override;
    bool equal(abstract *&data) override;
    bool not_equal(abstract &data) override;
    bool not_equal(abstract *&data) override;

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
    Prisoners(abstract *data, Person *data1 ,Person *data2);
    // Prisoners(Convicted *data);

    // destructors
    ~Prisoners();

    // friend classes
    friend class Hierarchy;
    friend class Admin;
    // functions
    void give_space(string);
    void write(ofstream &out);

    // friend functions
    friend int partition(vector<Prisoners *> &array, int first, int last);
    friend void quick_sort(vector<Prisoners *> &array, int first, int last);
    friend ostream &operator<<(ostream &out, Prisoners *data);
    friend ofstream &operator<<(ofstream &out, Prisoners *data);
    // friend Prisoners *operator%(Prisoners *&chunk, string data); // this is the % operator overload that is basically the search function.
};