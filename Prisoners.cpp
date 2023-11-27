#include "Addons.h"

Prisoners::Prisoners()
{
    left = right = nullptr;
    this->relative_1 = this->relative_2 = nullptr;
}

// Prisoners::Prisoners(Person *data)
// {
//     left = right = nullptr;
//     this->root = data;
// }

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

// Prisoners *Prisoners::search(Prisoners *chunk, string data)
// {
//     if (data < this->root.ID)
//         return this->search(chunk->left, data);
//     else if (data > this->root.ID)
//         return this->search(chunk->right, data);
//     else
//         return chunk;
// }

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

void Prisoners::re_write(string file_name)
{
    ifstream file(file_name+".txt", ios::in);
}
