#include "Addons.h"

Admin::Admin()
{
    this->ID = "BSCE010307";
    this->name = "Muhammad Waleed Tahir";
    this->code = "grandu";
}

bool Admin::add_prisoner(Hierarchial_tree Thana)
{
    string prisoner_grade;
    Convicted new_prisoner;
    cout << "Enter the grade of the prisoner: ";
    cin >> prisoner_grade;
    prisoner_grade="Prisoners Data\\"+prisoner_grade;
    cout << prisoner_grade << endl;
    ofstream file(prisoner_grade+".txt", ios::out|ios::app);
    if(!file.is_open())
        return false;
    cin >> new_prisoner;
    file << new_prisoner;
    file.close();
    if(file.is_open())
        return false;
    else 
        return true;
}

bool Admin::admin_UI(Hierarchial_tree Thana)
{
    Person admin;
    string password, prisoner_grade;
    char choice;
    cin >> admin;
    cout << "Enter the password: ";
    cin >> password;
    if (admin.name != this->name || admin.ID!=this->ID || password != this->code)
        return false;
    Sleep(10);
    cout << "Welcome Mr." << this->name << endl;
    while (true)
    {
        cout << "Enter the thing u want: ";
        cin >> choice;
        switch (choice)
        {
        case 'a':
            if(!this->add_prisoner(Thana))
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
