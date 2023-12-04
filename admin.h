#pragma once
#include "Prisoners.h"
#include "hierarchy.h"

class Admin
{
private:
    Person admin;
    string code;
    Hierarchy *data;
    bool remove_user();
    bool add_prisoner();
    bool modify_data();
    bool store_from_file(Hierarchy* &data,string &prisoner_grade);
    bool generate_ID(abstract* &new_prisoner, int data, string prisoner_grade);

public:
    Admin();
    bool admin_UI();
    // ~Admin();
};