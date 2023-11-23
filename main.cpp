#include "Addons.h"

//! check the constrcuctor of the hirarchy class.



int main(int argc, char const *argv[])
{
    // Hierarchial_tree *yada=new Hierarchial_tree;
    // display(yada);
    // cout << yada << endl;
    // yada=nullptr;
    vector <Convicted> data;
    ifstream file("Prisoners Data\\test.txt", ios::in);
    if(!file.is_open())
    {
        cout << "Shit";
        return -1;
    }
    while (!file.eof())
    {
        cout << "is this called\n";
        Convicted temp;
        file >> temp;
        data.push_back(temp);
    }
    cout << "yhaan aat ahe ??";
    Convicted new_p;
    cin >> new_p;
    Admin temp;
    temp.generate_ID(new_p,data,"test");
    cout << new_p;
    return 0;
}
