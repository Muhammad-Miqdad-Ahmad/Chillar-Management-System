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
    cout<<"here\n";
    auto* wank = new Hierarchial_tree;
    cout<<"here3\n";

    PrisonersUi ui(wank);
    cout<<"here4\n";
    
    ui.prisonerUi();
    return 0;
}
