#include "Addons.h"

Hierarchy::Hierarchy()
{
    Person data;
    add_chunk(this->root,data);
    this->left=this->right=nullptr;
    this->root=nullptr;
}

Hierarchy::Hierarchy(char prisoner_class)
{
    this->data = prisoner_class;
    this->left=this->right=nullptr;
    this->root=nullptr;
}

Hierarchy::~Hierarchy()
{
    /*  first we delete the root of the prisoners tree. 
    With this the tree inside each node that depiicts a grade
    will be destroyed   */
    if(this->root)
        delete root;
    root = nullptr;

    /*  Then we delete the original tree. The one with the 
    Prisoner grades.    */
    if(this->right)
        delete right;
    if(this->left)
        delete left;
    left=right=nullptr;
}

Hierarchial_tree::~Hierarchial_tree()
{
    if(this->hierarchial_root)
        delete this->hierarchial_root;
}

Hierarchial_tree::Hierarchial_tree()
{
    for (int i = 0; i < 7; i++)
    {
        this->add_chunk(this->hierarchial_root, Constants::hierarchial_classes[i]);
    }
}

// // void Hierarchial_tree::add_chunk(Hierarchy *&chunk, int index)
// // {
//     // if (chunk == nullptr)
// //         chunk = new Hierarchy(Constants::hierarchial_classes[index]);
// //     else if (Constants::hierarchial_classes[index] > chunk->prisoner_class)
// //         add_chunk(chunk->right, index);
// //     else if (Constants::hierarchial_classes[index] < chunk->prisoner_class)
// //         add_chunk(chunk->left, index);
// // }


// Its a template function that is written in the hirarchy class
// It can be inherited and used anywhere because the add node function is the same
// for every tree.
template<typename data_type_1, typename data_type_2>
void Hierarchy::add_chunk(data_type_1* &chunk, data_type_2 data)
{
    if (chunk == nullptr)   // if chunk is null then make a new node
        chunk = new data_type_1(data);
    else if (chunk->data > data)    //else search
        add_chunk(chunk->right, data);
    else if (chunk->data < data)
        add_chunk(chunk->left, data);
}
