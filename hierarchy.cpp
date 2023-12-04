#include "Addons.h"

Hierarchy::Hierarchy()
{
    this->left = this->right = nullptr;
    this->root = nullptr;
    this->prisoner_count = 1;
}

Hierarchy::Hierarchy(char prisoner_class)
{
    this->prisoner_count = 0;              // the number of nodes in the tree
    this->prisoner_grade = prisoner_class; // we assign the class
    this->left = this->right = nullptr;    // we null the left and right pointers
    this->root = nullptr;                  // also null the root

    Person *relative1_data = nullptr, *relative2_data = nullptr;

    int credits;
    string file_name = "Prisoners Data\\", temp;  // create a string to read from the file.
    file_name = file_name + this->prisoner_grade; // storing the path in a string

    ifstream file(file_name + ".txt"); // open the file

    if (is_it_empty(file))
    {
        cout << "file is empty\n";
        return;
    }

    abstract *convict_data = new Person;

    getline(file, temp); // every file has en empty line on the top. This will remove the empty line
    if (this->prisoner_grade != 'A' && this->prisoner_grade != 'B' && this->prisoner_grade != 'C')
    {

        while (!file.eof())
        {
            // Convicted temp2;
            convict_data->read(file);
            relative1_data = new Person; // create a new person object
            relative2_data = new Person; // to store data
            file >> relative1_data;
            file >> relative2_data;
            getline(file, temp);
            credits = stoi(temp);
            add_chunk(this->root, convict_data, relative1_data, relative2_data, credits);
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
            cout << "While loop";
            convict_data->read(file);
            getline(file, temp);
            credits = stoi(temp);
            add_chunk(this->root, convict_data, relative1_data, relative2_data, credits);
        }
    }
    file.close();
    this->make_full_balanced();
}

Hierarchy::~Hierarchy()
{
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

void Hierarchy::add_chunk(Prisoners *&chunk, abstract *&data, Person *&relative_1, Person *&relative_2, int credits) // function to add chunk to tree
{
    if (chunk == nullptr)
    {
        chunk = new Prisoners(data, relative_1, relative_2, credits); // prisoners data
        this->prisoner_count++;                                       // increase the prisoner count
    }
    else if (data->less_than(chunk->root))
        this->add_chunk(chunk->left, data, relative_1, relative_2, credits);
    else
        this->add_chunk(chunk->right, data, relative_1, relative_2, credits);
}

void Hierarchy::make_full_balanced() // function to make the tree full balanced.
{
    vector<Prisoners *> temporary_storage;
    store_del_tree(this->root, temporary_storage); // this function stores the tree in a vector.

    for (auto &&i : temporary_storage)
        i->left = i->right = nullptr;

    // cout << "quick sort call kr rha hoon\n";
    quick_sort(temporary_storage, 0, temporary_storage.size() - 1);             // BKL awi dalah hai
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

void Hierarchy::write_file_in_BFS(ofstream &file)
{
    if (this->root == nullptr)
        return;
    // Create a queue for BFS
    queue<Prisoners *> que;
    que.push(this->root);

    while (!que.empty())
    {
        // Dequeue a node from the front of the queue and print its value
        Prisoners *current = que.front();
        current->write(file);
        que.pop();

        // Enqueue the left child if it exists
        if (current->left != nullptr)
            que.push(current->left);

        // Enqueue the right child if it exists
        if (current->right != nullptr)
            que.push(current->right);
    }
}

Prisoners *Hierarchy::search(Prisoners *&chunk, abstract *to_find)
{
    if (chunk == nullptr || chunk->root->equal(to_find))
    {
        return chunk;
    }
    else if (to_find->less_than(chunk->root))
    {
        cout << "Left pe jata he\n";
        return this->search(chunk->left, to_find);
    }
    else
    {
        cout << "right pe ja rha he\n";
        return this->search(chunk->right, to_find);
    }
}

Prisoners *Hierarchy::get_smallest()
{
    Prisoners *move = nullptr;
    for (move = this->root; move->left != nullptr; move = move->left)
        ;

    if (move->right == nullptr)
        return move;
    else
        return move->right;
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

ofstream &operator<<(ofstream &out, Hierarchy *data)
{
    if (data != nullptr)
    {
        // out << "Wtf is this shitty fish\n";
        out << data->left;
        data->root->write(out);
        out << data->right;
    }
    return out;
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

void Hierarchy::delete_empty_node(Prisoners *&to_del)
{
    Prisoners *move = this->root;
    while (true)
    {
        if (move->left->root->equal(to_del->root))
        {
            move->left = nullptr;
            break;
        }
        else if (move->right->root->equal(to_del->root))
        {
            move->right = nullptr;
            break;
        }
        else
            move = move->left;
    }
    delete to_del;
    to_del = nullptr;
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
        cout << "this: " << i << endl;
        add_chunk(this->root, Constants::hierarchial_classes[i]);
    }
}

ostream &operator<<(ostream &out, Hierarchial_tree *data)
{
    out << data->root << endl
        << endl;
    return out;
}

Prisoners *Hierarchial_tree::searchGrade(Hierarchy *&chunk, abstract *tofind)
{
    
    cout<<chunk->prisoner_grade <<" "<< tofind->ID[0] <<endl;
    if (chunk == nullptr)
    {
        return nullptr;
    }
    if (chunk->prisoner_grade == tofind->ID[0])
    {
        cout<<"going\n";
        return chunk->search(chunk->root, tofind);
    }
    else if (tofind->ID[0] < chunk->prisoner_grade)
    {
        return this->searchGrade(chunk->left, tofind);
    }
    else
    {
        return this->searchGrade(chunk->right, tofind);
    }
}
