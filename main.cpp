#include "Addons.h"
//! check the constrcuctor of the hirarchy class.
#include <limits>
// cout << "Enter hours: ";
//         cin >> h;
//         if (h <= 0 || h > 60 || cin)
//         {
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(),'\n');
//             cout << "invlaid input\n";
//         }
//         else
//             break;

int main(int argc, char const *argv[])
{
    // time_t now = time(0);
    // // gives the time in the form of some integer.
    // // idk what that shit is. you wann a see it.
    // // cout << now << endl; // here is a cout statement. see for yourself.

    // // convert now to string form
    // char *time = ctime(&now),check[4];
    // for (int i = 0; true; i++)
    // {
    //     if (time[i] == ' ')
    //     {
    //         check[i] = '\0';
    //         break;
    //     }
    //     else
    //         check[i] = time[i];
    // }
    // cout << check;
    string temp;
    ifstream file("Prisoners Data\\G.txt", ios::in);
    if (!file.is_open())
        cout << "Shit happenned\n";
    Person *data1 = nullptr;
    Person *data2 = nullptr;
    abstract *data;
    Hierarchy *root = new Hierarchy;
    getline(file, temp);
    while (!file.eof())
    {
        data1 = new Person;
        data2 = new Person;
        data = new Convicted;
        data->read(file);
        file >> data1;
        file >> data2;
        root->add_chunk(root->root, data, data1, data2);
        data = nullptr;
        data1 = data2 = nullptr;
    }
    file.close();
    root->make_full_balanced();
    cout << root;
    ofstream file1("Prisoners Data\\G.txt", ios::out | ios::trunc);
    root->write_file_in_BFS(root->root, file1);
    file1.close();
}
