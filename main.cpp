#include "Addons.h"
//! check the constrcuctor of the hirarchy class.

int main(int argc, char const *argv[])
{
   // current date and time on the current system
   time_t now = time(0);
   int liq;
   double yada;
    cout << typeid(now).name() << endl;
    cout << typeid(liq).name() << endl;
    cout << typeid(yada).name() << endl;

   // convert now to string form
   char* date_time = ctime(&now);

   cout << "The current date and time is: " << date_time << endl;

}
