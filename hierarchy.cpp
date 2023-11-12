#include "Addons.h"

Hierarchy::Hierarchy()
{
    this->left = this->right = nullptr;
    this->root = nullptr;
    this->prisoner_count = 0;
}

Hierarchy::Hierarchy(char prisoner_class)
{
    this->prisoner_count = 0;              // the number of nodes in the tree
    this->prisoner_grade = prisoner_class; // we assign the class
    this->left = this->right = nullptr;    // we null the left and right pointers
    this->root = nullptr;                  // also null the root

    Person convict_data, *relative1_data = nullptr, *relative2_data = nullptr;

    string file_name = "Prisoners Data\\";        // create a string to read from the file.
    file_name = file_name + this->prisoner_grade; // storing the path in a string
    ifstream file(file_name + ".txt");

    if (this->prisoner_grade != 'A' && this->prisoner_grade != 'B' && this->prisoner_grade != 'C')
    {

        while (!file.eof())
        {
            string ID, name, temp;
            relative1_data = new Person; // create a new person object
            relative2_data = new Person; // to store data
            getline(file, ID);           // prisoner ID
            getline(file, name);         // Prisoner name
            convict_data.ID = ID;
            convict_data.name = name;
            getline(file, name); // relative 1 name
            getline(file, ID);   // relative 1 id
            relative1_data->name = name;
            relative1_data->ID = ID;
            getline(file, name); // relative 2 name
            getline(file, ID);   // relative 2 id
            relative2_data->name = name;
            relative2_data->ID = ID;
            // now to ignore the rest of the file
            getline(file, temp); // age
            getline(file, temp); // height
            getline(file, temp); // weight
            getline(file, temp); // sentence
            getline(file, temp); // captured on
            getline(file, temp); // expected release
            getline(file, temp); // crime
            getline(file, temp); // empty line
            add_chunk(this->root, convict_data, relative1_data, relative2_data);
            delete relative1_data; // delete so that it can be used again
            delete relative2_data;
            relative1_data = relative2_data = nullptr; // null the pointers
        }
    }
    else
    {
        // there is no relatives in this case so we will not give new space to the relative pointers
        while (!file.eof())
        {
            string ID, name, temp;
            getline(file, ID);   // prisoner ID
            getline(file, name); // Prisoner name
            convict_data.ID = ID;
            convict_data.name = name;
            // for the class A, B and C there is no relative info.
            // now to ignore the rest of the file
            getline(file, temp); // age
            getline(file, temp); // height
            getline(file, temp); // weight
            getline(file, temp); // sentence
            getline(file, temp); // captured on
            getline(file, temp); // expected release
            getline(file, temp); // crime
            getline(file, temp); // empty line
            add_chunk(this->root, convict_data, relative1_data, relative2_data);
        }
    }
    file.close();
    this->make_full_balanced();
}

Hierarchy::~Hierarchy()
{
    cout << "is this being called anywhere\n\n\n";
    /*  first we delete the root of the prisoners tree.
    With this the tree inside each node that depiicts a grade
    will be destroyed   */
    if (this->prisoner_grade)
        delete root;
    root = nullptr;

    /*  Then we delete the original tree. The one with the
    Prisoner grades.    */
    if (this->right)
        delete right;
    if (this->left)
        delete left;
    left = right = nullptr;
}

Hierarchial_tree::~Hierarchial_tree()
{
    if (this->root)
        delete this->root;
}

Hierarchial_tree::Hierarchial_tree()
{
    this->root = nullptr;
    for (int i = 0; i < 7; i++)
    {
        add_chunk(this->root, Constants::hierarchial_classes[i]);
    }
}

void Hierarchial_tree::add_chunk(Hierarchy *&chunk, char data)
{
    if (chunk == nullptr) // if chunk is null then make a new node
        chunk = new Hierarchy(data);
    else if (chunk->prisoner_grade > data) // else search
        add_chunk(chunk->right, data);
    else if (chunk->prisoner_grade < data)
        add_chunk(chunk->left, data);
}

Prisoners *operator%(Hierarchy *&chunk, string data)
{
    if (data[0] > chunk->prisoner_grade)
        return chunk->right % data;
    else if (data[0] < chunk->prisoner_grade)
        return chunk->left % data;
    else
        return chunk->root % data;
}

void Hierarchy::add_chunk(Prisoners *&chunk, Person &data, Person *&relative_1, Person *&relative_2) // function to add chunk to tree
{
    if (chunk == nullptr)
    {
        chunk = new Prisoners;
        chunk->root = data;             // prisoners data
        chunk->relative_1 = relative_1; // relative 1 data
        chunk->relative_2 = relative_2; // relative two data
        this->prisoner_count++;         // increase the prisoner count
    }
    else if (data < chunk->root)
        this->add_chunk(chunk->left, data, relative_1, relative_2);
    else
        this->add_chunk(chunk->right, data, relative_1, relative_2);
}

void Hierarchy::make_full_balanced() // function to make the tree full balanced.
{
    vector<Prisoners *> temporary_storage;
    store_del_tree(this->root, temporary_storage); // this function stores the tree in a vector.

    for (auto &&i : temporary_storage)
        i->left = i->right = nullptr;

    // cout << "quick sort call kr rha hoon\n";
    quick_sort(temporary_storage, 0, temporary_storage.size() - 1);             // function to quick sort the vector

    this->root = balancing(temporary_storage, 0, temporary_storage.size() - 1); // the root the balancing function returns is stored in the root of class
    temporary_storage.clear();
}

void Hierarchy::store_del_tree(Prisoners *&chunk, vector<Prisoners *> &data) // this is to store the tree in a vector
{
    if (chunk != nullptr)
    {
        store_del_tree(chunk->left, data);
        data.push_back(chunk);
        store_del_tree(chunk->right, data);
    }
}

Prisoners *Hierarchy::balancing(vector<Prisoners *> &array, int start, int last) // this function is the one responsible of balancing the tree
{
    if (start > last)
        return nullptr;

    int mid = (start + last) / 2;     // we find the mid point of the rray
    Prisoners *new_root = array[mid]; // then we make it the root of the tree
    /* if(start<last)  AAAAAAhHHHHHHHHH FUCK THIS WAS THE ERROR. THt was why it was not working because it was not returning any nulll pointer
    This shitty thing it destroyed my weakend. I am sooo done with coding and DSA. Main ni khel ra */
    // {
    // new_root->left = balancing(array, start, mid - 1); // after that I sent the lower half towards the left
    // new_root->right = balancing(array, mid + 1, last); // the upper half towards the right
    // }
    new_root->left = balancing(array, start, mid - 1); // after that I sent the lower half towards the left
    new_root->right = balancing(array, mid + 1, last); // the upper half towards the right
    return new_root;                                   // we simply return the root
}

ostream &operator<<(ostream &out, Hierarchy *data)
{
    // out << "Is this called????\n";
    if (data != nullptr)
    {
        // out << "Wtf is this shitty fish\n";
        out << data->left;
        out << data->root;
        out << data->right;
    }
    return out;
}

ostream &operator<<(ostream &out, Hierarchial_tree *data)
{
    out << data->root << endl
        << endl;
    return out;
}
