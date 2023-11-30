#include "Addons.h"

Admin::Admin()
{
    this->admin.ID = "BSCE010307";
    this->admin.name = "Muhammad Waleed Tahir";
    this->code = "grandu";
}

bool Admin::admin_UI()
{
    Person admin;
    string password;
    char choice;
    cin >> admin;
    cout << "Enter the password: ";
    cin >> password;
    if (admin.name != this->admin.name || admin.ID != this->admin.ID || password != this->code)
        return false;
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
    if (prisoner_grade != "A" || prisoner_grade != "B" || prisoner_grade != "C")
    {
        while (!file.eof()) // agar file open ho gai he to end of file tk loop chle ga.
        {
            temp = new Convicted;
            temp->read(file);
            relative_1 = new Person;
            file >> relative_1;
            relative_2 = new Person;
            file >> relative_2;
            data->add_chunk(data->root, temp, relative_1, relative_2);
            relative_1 = relative_2 = nullptr;
            temp = nullptr;
        }
    }
    else
    {
        temp = new Convicted;
        temp->read(file);
        data->add_chunk(data->root, temp, relative_1, relative_2);
        temp = nullptr;
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
    Hierarchy *data = nullptr;
    abstract *input = new Person;
    string prisoner_grade, prisoner_name, prisoner_ID;
    cout << "Enter the grade of the prisoner: ";
    cin >> prisoner_grade;
    string file_name = prisoner_grade;

    if (!this->store_from_file(data, file_name))
        return false;

    input->input();

    Prisoners *to_del = data->search(data->root, input);

    if (to_del == nullptr)
    {
        cout << "The convict was not found in the data base\n";
        return false;
    }

    Prisoners *smallest = data->get_smallest();
    swap(to_del->root, smallest->root);
    swap(to_del->relative_1, smallest->relative_1);
    swap(to_del->relative_2, smallest->relative_2);
    ofstream file1("Prisoners Data\\Removed_IDs.txt", ios::out | ios::app), file2("Prisoners Data\\Removed_Prisoners.txt", ios::out | ios::app);

    if (!file1.is_open() || !file1.is_open())
        return false;
        
    smallest->write(file2);
    file1 << endl
          << smallest->root->ID;
    file1.close();
    file2.close();

    if (file1.is_open() || file1.is_open())
        return false;

    delete smallest;
    smallest = to_del = nullptr;
    data->make_full_balanced();
    ofstream file(file_name + ".txt", ios::out | ios::trunc);
    if (!file.is_open())
        return false;
    data->write_file_in_BFS(data->root, file);
    file.close();
    return true;
}

bool Admin::add_prisoner()
{
    string prisoner_grade, file_name;
    cout << "Enter the grade of the prisoner: ";
    cin >> prisoner_grade;
    file_name = prisoner_grade;
    Hierarchy *data = new Hierarchy;
    abstract *new_prisoner = new Convicted;
    Person *r1, *r2;

    // ye function hmeen store kr k de deta he sb ik vector main.
    //  agar ye sahi ni chla to false return kr dega.
    if (!this->store_from_file(data, file_name))
        return false;

    new_prisoner->input();
    if (prisoner_grade != "A" || prisoner_grade != "B" || prisoner_grade != "C")
    {
        r1 = new Person;
        r2 = new Person;
        cin >> r1;
        cin >> r2;
    }

    data->add_chunk(data->root, new_prisoner, r1, r2);
    data->make_full_balanced();
    ofstream file(file_name + ".txt", ios::out | ios::trunc);
    data->write_file_in_BFS(data->root, file);
    file.close();
    delete r1;
    delete r2;
    delete new_prisoner;
    r1 = r2 = nullptr;
    new_prisoner = nullptr;
    return true;
}

bool Admin::generate_ID(Convicted &new_prisoner, int number, string prisoner_grade)
{
    // we open the file that contains all the removed IDs
    ifstream file_1("Prisoners Data\\Removed_IDs.txt", ios::in);
    if (!file_1.is_open())
        return false;

    // this is a function that tells us if a file is empty or not.
    if (!is_it_empty(file_1))
    {
        // returns false if the file is not empty
        queue<string> unused_IDs;
        // loop to iterate through the entre file.
        while (!file_1.eof())
        {
            string temp;
            getline(file_1, temp);
            unused_IDs.push(temp);
        }
        new_prisoner.ID = unused_IDs.front();
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
        new_prisoner.ID = prisoner_grade + new_id;
        cout << new_id << endl
             << endl;
    }
    return true;
}

bool Admin::modify_data()
{
    Hierarchy *data;
    string prisoner_grade, file_name;
    cout << "Enter the grade of the prisoner: ";
    cin >> prisoner_grade;
    file_name = prisoner_grade;
    if (!this->store_from_file(data, file_name))
        return false;
    Person *input = new Person;
    input->input();
    Prisoners *to_modify = data->search(data->root, input);
    char choice;
    to_modify->root->modify();
    ofstream file(file_name + ".txt", ios::out | ios::trunc);
    data->write_file_in_BFS(data->root, file);
    file.close();
    return true;
}
