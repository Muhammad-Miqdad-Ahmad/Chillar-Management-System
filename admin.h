#pragma once
#include "Prisoners.h"
#include "hierarchy.h"

class Admin
{
private:
    Person admin;
    string code;
    abstract *input;
    Hierarchy *data;
    Hierarchial_tree *origin;
    bool remove_user();
    bool modify_data();
    bool add_prisoner();
    bool display_data();
    void credit_check();
    void search_to_del_and_rewrite(Hierarchy*&,char);
    bool store_from_file(Hierarchy* &data,string &prisoner_grade);
    bool generate_ID(abstract* &new_prisoner, int data, string prisoner_grade);

public:
    Admin(Hierarchial_tree*&);
    bool admin_UI();
    // ~Admin();
};