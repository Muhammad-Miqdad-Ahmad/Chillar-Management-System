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
    Hierarchial_tree *Thana = new Hierarchial_tree;
    char choice;
    while (true)
    {
        cin >> choice;
        if(cin.fail())
        {
            cin.clear();
            choice = '-1';
        }
        switch (choice)
        {
        case 'a':
        {
            Admin admin(Thana);
            if(!admin.admin_UI())
                cout << "there was some error\n";
            delete Thana;
            Thana = new Hierarchial_tree;
            break;
        }
        case 'b':
        {
            // visitor UI
            break;
        }
        case 'c':
        {
            // Prisoner UI
            break;
        }
        case 'x':
        {
            return 0;
            break;
        }
        default:
            cout << "Invalid input" << endl;
            break;
        }
    }
}
