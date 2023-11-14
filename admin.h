#pragma once
#include "Prisoners.h"

class Admin
{
private:
    Person admin;
    string code;
public:
    Admin();
    bool add_prisoner();
    bool admin_UI();
    // ~Admin();
};