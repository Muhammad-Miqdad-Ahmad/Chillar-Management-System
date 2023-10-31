#include "Addons.h"

Person::Person()
{
}

Person::~Person()
{
}

Prisoners::Prisoners()
{
    left=right=nullptr;
}

Prisoners::Prisoners(Person data)
{
    left=right=nullptr;
    this->data=data;
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
