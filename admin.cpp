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
        cout << "Enter the thing u want: ";
        cin >> choice;
        switch (choice)
        {
        case 'a':
            if (!this->add_prisoner())
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

// ye function hmeen bs file se sb utha k ik vector main store kr k de deta he
bool Admin::store_from_file(vector<Convicted> &data, string &prisoner_grade)
{
    string file_name = "Prisoners Data\\" + prisoner_grade; // yhan pe main file ka naam grade k hisab se string main store kr deta hoon
    ifstream file(file_name + ".txt", ios::in);             // file open krta hoon
    if (!file.is_open())                                    // agar file open nhi hoi to function false return kr dega
        return false;

    while (!file.eof()) // agar file open ho gai he to end of file tk loop chle ga.
    {
        Convicted temp;                  // ik convicted ka temp var bnao
        temp.give_space(prisoner_grade); // ye function bs yeh krta he k agar hmara prisoner garde A, B, C nhi he to wo Convicted class main relatives ko space de deta he
        file >> temp;                    // baqi sb operator overloading main likha he
        data.push_back(temp);            // vector main push back kr de sb
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
    vector<Convicted> data;
    string prisoner_grade, prisoner_name, prisoner_ID;
    cout << "Enter the grade of the prisoner: ";
    cin >> prisoner_grade;
    string file_name = prisoner_grade;

    if (!this->store_from_file(data, file_name))
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
            ofstream file(file_name + ".txt", ios::out | ios::trunc);

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

bool Admin::add_prisoner()
{
    vector<Convicted> data;
    Convicted new_prisoner;
    string prisoner_grade, file_name;
    cout << "Enter the grade of the prisoner: ";
    cin >> prisoner_grade;
    file_name = prisoner_grade;

    // ye function hmeen store kr k de deta he sb ik vector main.
    //  agar ye sahi ni chla to false return kr dega.
    if (!this->store_from_file(data, file_name))
        return false;

    cin >> new_prisoner; // nae prisoner ka data input krwa liya he.

    // ye function basically check krta he agr grade ABC ni he to relatives k pointers ko space de deta he
    new_prisoner.give_space(prisoner_grade);

    generate_ID(new_prisoner, data, prisoner_grade);
    return true;
}

bool Admin::generate_ID(Convicted &new_prisoner, vector<Convicted> data, string prisoner_grade)
{
    // we open the file that contains all the removed IDs
    ifstream file_1("Prisoners Data\\Removed_IDs.txt", ios::in);
    if (!file_1.is_open())
        return false;

    //this is a function that tells us if a file is empty or not.
    if (!is_it_empty(file_1))
    {
        // returns false if the file is not empty
        vector<string> unused_IDs;
        //loop to iterate through the entre file. 
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
        //returns true if the file is empty
        string new_id;
        new_id = to_string(data.size());
        new_prisoner.ID = prisoner_grade + new_id;
        cout << new_id << endl
             << endl;
    }
    return true;
}

bool modify_data()
{
    return true;
}
