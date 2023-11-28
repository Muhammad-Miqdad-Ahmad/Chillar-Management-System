#include "Addons.h"

Prisoners::Prisoners()
{
    left = right = nullptr;
    this->relative_1 = this->relative_2 = nullptr;
}

Prisoners::Prisoners(abstract *data)
{
    left = right = nullptr;
    this->root = data;
}

Prisoners::~Prisoners()
{
    if (this->left != nullptr)
        delete left;
    if (this->right != nullptr)
        delete right;
    left = right = nullptr;
}

Person::Person(string ID, string name)
{
    this->ID = ID;
    this->name = name;
}

/*what thw shit is wrong with the shit is the fish cake
kyaa msla hee tre ko bhens ki dum tera error ni kht m ho k de rha he wtdqjnedjneljnejbw*/
ostream &operator<<(ostream &out, Prisoners *data)
{
    if (data != nullptr)
    {
        out << data->left;
        data->root->display();
        out << data->right;
    }
    return out;
}

ofstream &operator<<(ofstream &out, Prisoners *data)
{
    out << data->root;
    out << data->relative_1;
    out << data->relative_2 << endl;
    return out;
}

void Prisoners::write(ofstream &out)
{
    this->root->write(out);
    if(relative_1)
    out << this->relative_1;
    if(relative_2)
    out << this->relative_2;
}
