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
    Admin a(trial);
    a.admin_UI();
    // cout << trial;
    abstract *tofind = new Person;
    tofind->input();
    Prisoners* data=trial->searchGrade(trial->root,tofind);

    if (data==nullptr)
        cout << "Ye null he\n";
        
    cout << data;
    return 0;
}
