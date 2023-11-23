#include "Addons.h"

Admin::Admin()
{
    this->admin.ID = "BSCE010307";
    this->admin.name = "Muhammad Waleed Tahir";
    this->code = "grandu";
}

bool Admin::admin_UI(Hierarchial_tree Thana)
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
        cout << "Enter the thing u want: ";
        cin >> choice;
        switch (choice)
        {
        case 'a':
            if (!this->add_prisoner(Thana))
                cout << "The process did not work as intended\n";
            break;

        case 'x':
            return true;

        default:
            cout << "invald input: ";
            break;
        }
    }
}

bool Admin::remove_user()
{
    vector<Convicted> data;
    string prisoner_grade, prisoner_name, prisoner_ID;
    cout << "Enter the grade of the prisoner: ";
    cin >> prisoner_grade;
    prisoner_grade = "Prisoners Data\\" + prisoner_grade;
    ifstream file(prisoner_grade + ".txt", ios::in);
    if (!file.is_open())
        return false;

    while (!file.eof())
    {
        Convicted temp;
        file >> temp;
        data.push_back(temp);
    }
    file.close();
    if (file.is_open())
        return false;

    cout << "Enter the name of the convicted to remove: ";
    cin >> prisoner_name;
    cout << "Enter the ID of the convicted to remove: ";
    cin >> prisoner_ID;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].ID == prisoner_ID && data[i].name == prisoner_name)
        {
            ofstream file_id("Prisoners Data\\Removed_IDs.txt", ios::out | ios::app);
            ofstream file_data("Prisoners Data\\Removed_Prisoners.txt", ios::out | ios::app);

            if (!file_id.is_open() || !file_data.is_open())
                return false;

            file_id << data[i].ID << endl;
            file_data << data[i];
            //! try and input also the released date of the prisoner
            file_id.close();
            file_data.close();

            if (file_id.is_open() || file_data.is_open())
                return false;

            data.erase(data.begin() + i);
            ofstream file(prisoner_grade + ".txt", ios::out | ios::trunc);

            if (!file.is_open())
                return false;

            for (auto &&i : data)
                file << i;

            file.close();
            if (file.is_open())
                return false;
            else
                return true;
        }
    }
    cout << "The convict was not found in the data base\n";
    return false;
}

bool Admin::add_prisoner(Hierarchial_tree Thana)
{
    vector<Convicted> data;
    Convicted new_prisoner;
    Person *relative_1 = nullptr, *relative_2 = nullptr;
    string prisoner_grade, file_name;
    cout << "Enter the grade of the prisoner: ";
    cin >> prisoner_grade;
    file_name = "Prisoners Data\\" + prisoner_grade;
    ifstream file(file_name + ".txt", ios::in);
    if (!file.is_open())
        return false;
    if (prisoner_grade == "A" || prisoner_grade == "B" || prisoner_grade == "C")
    {
        relative_1=new Person;
        relative_2=new Person;
        while (!file.eof())
        {
            Convicted temp;
            //! yhan pe read from file ka function aana he
            //! us main change kr. paremetes km kr and this use kr
            //!relative bhi andr wale use kr.
            data.push_back(temp);
            delete relative_1;
            delete relative_2;
        }
    }
    else
    {
        while (!file.eof())
        {
            Convicted temp;
            file >> temp;
            data.push_back(temp);
        }
    }
    file.close();
    if (file.is_open())
        return false;

    cin >> new_prisoner;
    generate_ID(new_prisoner, data, prisoner_grade);
    return true;
}

bool Admin::generate_ID(Convicted &new_prisoner, vector<Convicted> data, string prisoner_grade)
{
    ifstream file_1("Prisoners Data\\Removed_IDs.txt", ios::in);
    if (!file_1.is_open())
    {
        cout << "oooohhhhhhhhhhhf cuk\n\n\n";
        return false;
    }

    if (!is_it_empty(file_1))
    {
        cout << "\nthe file was not empty\n";
        vector<string> unused_IDs;
        while (!file_1.eof())
        {
            string temp;
            getline(file_1, temp);
            unused_IDs.push_back(temp);
        }
        new_prisoner.ID = unused_IDs[0];
        unused_IDs.erase(unused_IDs.begin());
        file_1.close();
        ofstream file("Removed_IDs.txt", ios::out | ios::trunc);
        for (auto &&i : unused_IDs)
            file << i << endl;
        unused_IDs.clear();
        file.close();
    }
    else
    {
        cout << "\nthe file was empty\n";
        string new_id;
        new_id = to_string(data.size());
        new_prisoner.ID = prisoner_grade + new_id;
        cout << new_id << endl
             << endl;
    }
    return true;
}