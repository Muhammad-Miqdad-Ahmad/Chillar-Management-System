#pragma once
#include "Prisoners.h"

class Admin: Person
{
private:
    string code;
public:
    Admin();
    bool add_prisoner(Hierarchial_tree Thana);
    bool admin_UI(Hierarchial_tree Thana);
    // ~Admin();
};