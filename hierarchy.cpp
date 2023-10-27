#include "Addons.h"

Hierarchial_tree::Hierarchial_tree()
{
    for (int i = 0; i < 7; i++)
        this->add_hierarchy(this->hierarchial_root,i);
}

void Hierarchial_tree::add_hierarchy(Hierarchy* &chunk, int index)
{
    if(chunk==nullptr)
        chunk=new Hierarchy(Constants::hierarchial_classes[index]);
    else if(Constants::hierarchial_classes[index]>chunk->prisoner_class)
        add_hierarchy(chunk->right, index);
    else if(Constants::hierarchial_classes[index]<chunk->prisoner_class)
        add_hierarchy(chunk->left, index);
}