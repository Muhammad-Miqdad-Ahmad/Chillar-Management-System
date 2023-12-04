#include "Addons.h"
//! check the constrcuctor of the hirarchy class.
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
    auto* wank = new Hierarchial_tree;
    Admin a(wank);
    a.admin_UI();
    PrisonersUi ui(wank);
    ui.prisonerUi();
    return 0;
}
