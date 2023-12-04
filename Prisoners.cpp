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

Prisoners::Prisoners(abstract *data, Person *data1, Person *data2)
{
    this->left = this->right = nullptr;
    this->root = data;
    this->relative_1 = data1;
    this->relative_2 = data2;
}

Prisoners::~Prisoners()
{
    cout << "\t\t\tis this called\n\n\n";
    if (this->left != nullptr)
        delete left;
    if (this->right != nullptr)
        delete right;
    left = right = nullptr;
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
    if (this->relative_1 != nullptr)
        out << this->relative_1;
    if (this->relative_2 != nullptr)
        out << this->relative_2;
}

void Prisoners::give_space(string check)
{
    if (check == "A" || check == "B" || check == "C")
    {
        this->relative_1 = new Person;
        this->relative_2 = new Person;
    }
}
