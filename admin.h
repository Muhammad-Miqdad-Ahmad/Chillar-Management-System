#pragma once
#include "Prisoners.h"

class Admin
{
private:
    Person admin;
    string code;
public:
    Admin();
    bool admin_UI(Hierarchial_tree Thana);
    bool add_prisoner(Hierarchial_tree Thana);
    bool remove_user();
    // ~Admin();
};