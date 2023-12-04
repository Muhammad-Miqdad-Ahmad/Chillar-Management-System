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
    abstract *tofind=new Person;
    tofind->input();
    trial->searchGrade(trial->root,tofind);
    // Admin admin(trial);
    // admin.admin_UI();
    return 0;
}
