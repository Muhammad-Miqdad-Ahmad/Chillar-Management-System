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

int main(int argc, char const *argv[])
{
    Hierarchial_tree* wanker = new Hierarchial_tree;
    cout<<wanker;
    // exit(0);
    PrisonersUi data(wanker);
    data.signIn();
    data.turnIn();
    data.viewData();
    data.turnIn();
    data.viewData();
    return 0;
}
