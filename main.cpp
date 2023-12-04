#include "Addons.h"
// int c;
// cout << "Enter input: ";
//         cin >> h;
//         if (cin)
//         {
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(),'\n');
//             cout << "invlaid input\n";
//         }
//         else
//             break;

int main()
{
    Hierarchial_tree *trial= new Hierarchial_tree;
    // Admin admin(trial);
    // admin.admin_UI();
    // delete trial;
    // trial = new Hierarchial_tree;
    // abstract *tofind = new Person;
    // tofind->input();
    // Prisoners* data=trial->searchGrade(trial->root,tofind);

    // if (data==nullptr)
    //     cout << "Ye null he\n";
        
    // cout << data;
    PrisonersUi a(trial);
    a.prisonerUi();
    Admin admin(trial);
    admin.admin_UI();
    delete trial;
    trial = new Hierarchial_tree;
    a.prisonerUi();
    return 0;
}
