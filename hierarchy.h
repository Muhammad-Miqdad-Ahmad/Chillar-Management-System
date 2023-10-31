#include "Prisoners.h"
class Hierarchy
{
private:
    char data;               // variable to store the name of the class
    Prisoners *root;         // The root of the prisoner class. The tree formed will the one holding the data of the prisoners
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

    // functions
    template <typename data_type_1, typename data_type_2> // the function is template so that any class that needs to make a tree can use this function
    void add_chunk(data_type_1 *&chunk, data_type_2 data);
};

class Hierarchial_tree : Hierarchy
{
private:
    Hierarchy *hierarchial_root;

public:
    //constructors
    Hierarchial_tree();

    //destructors
    ~Hierarchial_tree();

    // friend classes
    friend class Prisoners;
    // // void add_chunk(Hierarchy* &chunk, int index); // dont un comment it. I am just eaving it here for research purposes ( ;
};
