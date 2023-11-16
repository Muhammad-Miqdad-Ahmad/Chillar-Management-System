#include "Addons.h"

Admin::Admin()
{
    this->admin.ID="BSCE010307";
    this->admin.name="Muhammad Waleed Tahir";
    this->code="grandu";
}

bool Admin::add_prisoner()
{
    string prisoner_grade;
    Convicted new_prisoner;
    cout << "Enter the grade of the prisoner: ";
    cin >> prisoner_grade;
    cin >> new_prisoner;
}

bool Admin::admin_UI()
{
    Person admin;
    string password, choice;
    cin >> admin;
    cout << "Enter the password: ";
    cin >> password;
    if(admin!=this->admin||password!=this->code)
        return false;
    cout << "Welcome Mr." << this->admin.name << endl;
}
