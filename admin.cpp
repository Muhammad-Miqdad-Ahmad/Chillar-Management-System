#include "Addons.h"

Admin::Admin()
{
    this->admin.ID = "BSCE010307";
    this->admin.name = "Muhammad Waleed Tahir";
    this->code = "grandu";
    this->data = nullptr;
}

bool Admin::admin_UI()
{
    // Person admin;
    // string password;
    char choice;
    // cin >> admin;
    // cout << "Enter the password: ";
    // cin >> password;
    // if (admin.name != this->admin.name || admin.ID != this->admin.ID || password != this->code)
    //     return false;

    Sleep(10);
    cout << "Welcome Mr." << this->admin.name << endl;
    while (true)
    {
        cout << "Enter the thing u want\nEnter 'a' to add a prisoner\nEnter 'b' to remove a prisoner\nEnter 'c' to modify some data\nEnter your input here: ";
        cin >> choice;
        switch (choice)
        {
        case 'a':
            if (!this->add_prisoner())
            {
                cout << "There was some error while adding. PLease recheck\n";
                return false;
            }
            break;
        case 'b':
            if (!this->remove_user())
            {
                cout << "There was some error while removing. PLease recheck\n";
                return false;
            }
            break;
        case 'c':
            if (!this->modify_data())
            {
                cout << "There was some error while modifying. PLease recheck\n";
                return false;
            }
            break;

        case 'x':
            return true;

        default:
            cout << "invald input: ";
            break;
        }
    }
}
// ye function hmeen bs file se sb utha k ik vector main store kr k de deta he
bool Admin::store_from_file(Hierarchy *&data, string &prisoner_grade)
{
    string garbage, file_name = "Prisoners Data\\" + prisoner_grade; // yhan pe main file ka naam grade k hisab se string main store kr deta hoon
    ifstream file(file_name + ".txt", ios::in);                      // file open krta hoon
    if (!file.is_open())                                             // agar file open nhi hoi to function false return kr dega
        return false;

    Person *relative_1 = nullptr, *relative_2 = nullptr;
    abstract *temp; // ik convicted ka temp var bnao
    getline(file, garbage);

    if (prisoner_grade != "A" && prisoner_grade != "B" && prisoner_grade != "C")
    {
        while (!file.eof()) // agar file open ho gai he to end of file tk loop chle ga.
        {
            temp = new Convicted;
            temp->read(file);
            relative_1 = new Person;
            file >> relative_1;
            relative_2 = new Person;
            file >> relative_2;
            if (temp->is_empty())
                delete temp;
            else
                data->add_chunk(data->root, temp, relative_1, relative_2);
            relative_1 = relative_2 = nullptr;
            temp = nullptr;
        }
    }
    else
    {
        while (!file.eof())
        {
            temp = new Convicted;
            temp->read(file);

            if (temp->is_empty())
                delete temp;
            else
                data->add_chunk(data->root, temp, relative_1, relative_2);

            temp = nullptr;
        }
    }
    file.close(); // file close kr de and prisonewr garde ko file name k equal kr de ta k asal code main bhi file ka name chala jae and bar bar bnana na pre.
    prisoner_grade = file_name;
    if (file.is_open()) // agar close krne k bad file open he to false
        return false;
    else // ni to sb sahi hoa he true
        return true;
}
// this is the function to simply remove some data from the system
bool Admin::remove_user()
{
    system("clear");
    this->data = new Hierarchy;
    this->input = new Person;
    string prisoner_grade, prisoner_name, prisoner_ID;
    cout << "Enter the grade of the prisoner: ";
    cin >> prisoner_grade;
    string file_name = prisoner_grade;

    if (!this->store_from_file(data, file_name)) // this will return a tree
        return false;

    input->input(); // get the input in the person to find the person to delete

    Prisoners *to_del = data->search(data->root, input); // search and return a prisoner pointer

    if (to_del == nullptr) // if the person is not found then this
    {
        cout << "The convict was not found in the data base\n";
        return false;
    }

    Prisoners *smallest = data->get_smallest(); // we will locate the smallest node in the tree
    // then we swap the data of the smallest with the one to delete
    if (smallest == nullptr)
    {
        cout << "Smallest was nul\n";
        exit(-1);
    }

    swap(to_del->root, smallest->root);
    swap(to_del->relative_1, smallest->relative_1);
    swap(to_del->relative_2, smallest->relative_2);
    // we open the file to store the removed IDs and the data of the removed prisoners.
    ofstream file1("Prisoners Data\\Removed_IDs.txt", ios::out | ios::app), file2("Prisoners Data\\Removed_Prisoners.txt", ios::out | ios::app);

    if (!file1.is_open() || !file1.is_open())
        return false;

    smallest->write(file2);                       // we write the smallest value (That has been swapped by the one to delete so technically the value we want to delete is in the smallest) in the file
    file2 << "\nTime of release: " << get_time(); // we also write the time when the data was removed from our data base.
    file1 << endl
          << smallest->root->ID; // we write the ID of the prisoner in the removed IDs file so that it can be used again.

    file1.close(); // close the files
    file2.close();

    if (file1.is_open() || file1.is_open())
        return false;

    this->data->delete_empty_node(smallest); // delete the data to be removed.
    smallest = to_del = nullptr;             // we null all the pointers

    data->make_full_balanced();                               // balance the tree again
    ofstream file(file_name + ".txt", ios::out | ios::trunc); // we open the file again to re write the file

    if (!file.is_open())
        return false;

    data->write_file_in_BFS(file); // we write the file using BFS
    file.close();

    delete this->data;
    delete input;
    input = nullptr;
    this->data = nullptr;
    return true;
}

bool Admin::add_prisoner()
{
    system("clear");
    string prisoner_grade, file_name;
    cout << "Enter the grade of the prisoner: ";
    cin >> prisoner_grade;
    file_name = prisoner_grade;
    this->data = new Hierarchy;

    // ye function hmeen store kr k de deta he sb ik vector main.
    //  agar ye sahi ni chla to false return kr dega.
    if (!this->store_from_file(data, file_name))
        return false;

    Person *r1 = nullptr, *r2 = nullptr;
    this->input = new Convicted;

    input->input();

    if (prisoner_grade != "A" && prisoner_grade != "B" && prisoner_grade != "C")
    {
        r1 = new Person;
        r2 = new Person;
        cout << "Give the data of the first relative: ";
        cin >> r1;
        cout << "Give the data of the second relative: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> r2;
    }

    this->generate_ID(input, data->prisoner_count, prisoner_grade); // this function will generate the new ID of for the new prisoner
    data->add_chunk(data->root, input, r1, r2);                     // add the info of the new Prisoner in the tree
    data->make_full_balanced();                                     // balance the tree again

    ofstream file(file_name + ".txt", ios::out | ios::trunc);
    if (!file.is_open())
        return false;

    data->write_file_in_BFS(file); // write the balanced tree in the file.
    file.close();

    if (r1 != nullptr)
        delete r1;
    if (r2 != nullptr)
        delete r2;

    delete this->data;
    delete this->input;
    r1 = r2 = nullptr;
    this->data = nullptr;
    this->input = nullptr;
    return true;
}

bool Admin::generate_ID(abstract *&new_prisoner, int number, string prisoner_grade)
{
    // we open the file that contains all the removed IDs
    ifstream file_1("Prisoners Data\\Removed_IDs.txt", ios::in);
    if (!file_1.is_open())
        return false;

    // this is a function that tells us if a file is empty or not.
    if (!is_it_empty(file_1))
    // returns false if the file is not empty
    {
        string garbage;
        queue<string> unused_IDs;
        // loop to iterate through the entre file.
        getline(file_1, garbage);
        while (!file_1.eof())
        {
            string temp;
            getline(file_1, temp);
            unused_IDs.push(temp);
        }
        new_prisoner->ID = unused_IDs.front();
        unused_IDs.pop();
        file_1.close();
        ofstream file("Removed_IDs.txt", ios::out | ios::trunc);
        while (!unused_IDs.empty())
        {
            file << unused_IDs.front();
            unused_IDs.pop();
        }
        file.close();
    }
    else
    {
        // returns true if the file is empty
        string new_id;
        new_id = to_string(number);
        new_prisoner->ID = prisoner_grade + new_id;
        cout << new_id << endl
             << endl;
    }
    return true;
}

bool Admin::modify_data()
{
    system("clear");
    this->data = new Hierarchy; // give space to the Hierarchy pointer in the class to make a tree
    string prisoner_grade, file_name;
    cout << "Enter the grade of the prisoner whose data you want to modify: ";
    cin >> prisoner_grade;      // input the garde of the prisoner you want to odify.
    file_name = prisoner_grade; // we make the file name

    if (!this->store_from_file(data, file_name)) // send the file name an dit will return a tree
        return false;                            // if something goes wrong the function will return false

    this->input = new Person; // take input of the person whose data wants to be modified
    input->input();           // take input

    //! yhan se modification start hoi he aag eyhan se sb krna modify
    // cout << (data->root->left->root->ID == input->ID) << endl;
    // cout << data->root->left->root->ID << endl;
    // cout << input->ID << endl
    //      << endl;
    // cout << data->root->left->root->name.length() << endl;
    // cout << input->name.length() << endl
    //      << endl;
    // system("cmd /C pause");
    // exit(-1);
    //! yhan tk ka cod useless he debuging k liye bs

    Prisoners *to_modify = data->search(data->root, input); // function to search the data.

    if (to_modify == nullptr)
        return false;

    to_modify->root->modify(); // dunction to modify the data

    ofstream file(file_name + ".txt", ios::out | ios::trunc); // open the file to rewrite the file
    data->write_file_in_BFS(file);                            // write into the file
    file.close();                                             // close the file

    delete this->data;
    this->data = nullptr;
    delete input;
    input = nullptr;

    return true;
}
