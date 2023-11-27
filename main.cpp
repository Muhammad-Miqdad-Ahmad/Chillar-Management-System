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
    ifstream file("G.txt", ios::in);
    if(!file.is_open())
        cout << "Shit happenned\n";
    Person* data1=new Person;
    Person* data2=new Person;
    abstract *liq;
    Hierarchy *root=new Hierarchy;
    // while(!file.eof())
    // {
        string name,id,height,weight,age,sentence,crime,empty;
        Capture_date captured_on,release;
        getline(file,id);
        getline(file,name);
        getline(file,age);
        getline(file,height);
        getline(file,weight);
        getline(file,sentence);
        file >> captured_on;
        file >> release;
        getline(file,crime);
        getline(file,empty);
        liq=new Convicted;
        liq->read(file);
        file>>data1;
        cout << data1;
        file>>data2;
        cout << data2;
        getline(file,temp);
        root->add_chunk(root->root,liq,data1,data2);
    // }
    cout << name << endl << id << endl << age << endl << height << endl << weight << endl << sentence << endl << captured_on << endl << release << endl << crime << endl << empty << endl <<"yhan tk\n" << endl ;
    file.close();
    cout << root;
    
}
