#include "Addons.h"

Admin::Admin()
{
    this->admin.ID="BSCE010307";
    this->admin.name="Muhammad Waleed Tahir";
    this->code="grandu";
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

    cin << new_prisoner;
    ifstream file("Removed_IDs.txt", ios::in);
    if(!is_empty(file))
    {
        vector<string> unused_IDs;
        while(!file.eof())
        {
            string temp;
            getline(file,temp);
            unused_IDs.push_back(temp);
        }
        new_prisoner.ID=unused_IDs[0];
    }
}