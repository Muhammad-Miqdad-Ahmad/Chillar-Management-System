#pragma once
#include "Prisoners.h"

class Hierarchy
{
private:
public:
    char prisoner_grade; // variable to store the name of the class
    Prisoners *root;     // The root of the prisoner class. The tree formed will the one holding the data of the prisoners
    int prisoner_count;
    Hierarchy *left, *right; // directions to form a tree. The grade determining tree
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
    void write_file_in_BFS(Prisoners *chunk, ofstream &file);
    void store_del_tree(Prisoners *&chunk, vector<Prisoners *> &data);
    Prisoners *balancing(vector<Prisoners *> &array, int start, int last);
    void add_chunk(Prisoners *&chunk, abstract* &data, Person *&relative_1, Person *&relative_2);

    // friend function
    // template<typename datatype>
    // fri  end void display(Hierarchy* &data);
    friend ostream &operator<<(ostream &out, Hierarchy *data);
    // Prisoners *operator%(string data);
};

class Hierarchial_tree
{
private:
public:
    Hierarchy *root;
    // constructors
    Hierarchial_tree();

    // destructors
    ~Hierarchial_tree();

    // friend classes
    friend class Prisoners;
    void add_chunk(Hierarchy *&chunk, char data);

    // friend functions
    // template<typename datatype>
    // friend void display(Hierarchial_tree* &data);
    friend ostream &operator<<(ostream &out, Hierarchial_tree *data);

    // // void add_chunk(Hierarchy* &chunk, int index); // dont un comment it. I am just eaving it here for research purposes ( ;

    // operator overloads   
};
