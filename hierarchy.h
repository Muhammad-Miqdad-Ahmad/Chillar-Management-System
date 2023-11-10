#pragma once
#include "Prisoners.h"
#include <string>
class Hierarchy
{
private:
    char prisoner_grade; // variable to store the name of the class
    Prisoners *root;     // The root of the prisoner class. The tree formed will the one holding the data of the prisoners
    int prisoner_count;
    Hierarchy *left, *right; // directions to form a tree. The grade determining tree
public:
    // constructors
    Hierarchy();
    Hierarchy(char prisoner_class);

    // destructors
    ~Hierarchy();

    // friend classes
    friend class Prisoners;
    friend class Hierarchial_tree;

    // function
    void make_full_balanced();
    Prisoners* balancing(vector<Prisoners*> &array, int start, int last);
    void store_del_tree(Prisoners* &chunk, vector<Prisoners*> &data);
    void add_chunk(Prisoners *&chunk, Person &data, Person *&relative_1, Person *&relative_2);

    // friend function
    friend Prisoners *operator%(Hierarchy *&chunk, string data);
};

class Hierarchial_tree
{
private:
    Hierarchy *hierarchial_root;

public:
    // constructors
    Hierarchial_tree();

    // destructors
    ~Hierarchial_tree();

    // friend classes
    friend class Prisoners;
    void add_chunk(Hierarchy *&chunk, char data);

    // friend functions

    template <typename datatype>
    friend ostream &operator<<(ostream &out, const datatype *&chunk);

    // // void add_chunk(Hierarchy* &chunk, int index); // dont un comment it. I am just eaving it here for research purposes ( ;

    // operator overloads
};
