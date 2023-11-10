#include "Addons.h"

Prisoners::Prisoners()
{
    left=right=nullptr;
    this->relative_1=this->relative_2=nullptr;
}

Prisoners::Prisoners(Person data)
{
    left=right=nullptr;
    this->convict=data;
}

Prisoners::~Prisoners()
{
    if(this->left!=nullptr)
        delete left;
    if(this->right!=nullptr)
        delete right;
    left=right=nullptr;
}

Person::Person(string ID, string name)
{
    this->ID=ID;
    this->name=name;
}

Prisoners* operator%(Prisoners* &chunk, string data)
{
    if(data<chunk->convict.ID)
        return chunk->left%data;
    else if(data>chunk->convict.ID)
        return chunk->right%data;
    else
        return chunk;
}
