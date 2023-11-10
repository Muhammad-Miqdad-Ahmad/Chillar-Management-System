#include "Prisoners.h"
class Hierarchy
{
private:
    char data;              // variable to store the name of the class
    Prisoners *root; // The root of the prisoner class. The tree formed will the one holding the data of the prisoners
    int node_count;
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

    // friend functions
    template <typename data_type_1, typename data_type_2> // the function is template so that any class that needs to make a tree can use this function
    friend void add_chunk(data_type_1 *&chunk, data_type_2 data);
    
    template <typename datatype>
    friend ostream &operator<<(ostream &out, const datatype *&chunk);

    friend Prisoners* operator%(Hierarchy* &chunk, string data);
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

    // friend functions
    template <typename data_type_1, typename data_type_2> // the function is template so that any class that needs to make a tree can use this function
    friend void add_chunk(data_type_1 *&chunk, data_type_2 data);

    template <typename datatype>
    friend ostream &operator<<(ostream &out, const datatype *&chunk);

    
    // // void add_chunk(Hierarchy* &chunk, int index); // dont un comment it. I am just eaving it here for research purposes ( ;

    // operator overloads
};
