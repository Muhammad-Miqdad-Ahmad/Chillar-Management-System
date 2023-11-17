#include "Addons.h"

//? jb admin ka bnana he to linked list use krni he
//? q k us ki search complexity O(n).
//? and BST plus balancing ka O(n+log n) aati he

//! check the constrcuctor of the hirarchy class.

//* system("cmd /C pause");
//* cout.flush()

int main(int argc, char const *argv[])
{
    Hierarchial_tree yada;
    Admin admin;
    if(!admin.admin_UI(yada));
        cout << "did not word";
    // display(yada);
    // cout << yada << endl;
    // yada=nullptr;
    return 0;
}
