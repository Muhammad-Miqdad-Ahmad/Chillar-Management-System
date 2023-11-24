#pragma once
#include "Prisoners.h"

class Admin
{
private:
    Person admin;
    string code;
public:
    Admin();
    bool remove_user();
    bool admin_UI();
    bool add_prisoner();
    bool modify_data();
    bool store_from_file(vector<Convicted> &data,string &prisoner_grade);
    bool generate_ID(Convicted &new_prisoner, vector<Convicted> data, string prisoner_grade);
    // ~Admin();
};