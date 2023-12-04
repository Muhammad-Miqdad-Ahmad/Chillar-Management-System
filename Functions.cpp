#include "Addons.h"

/* This function is used in the quick sort This makes one index the piviot of the array
And then it sorts the array such that the smaller ones are on the left of the piviot and
the bigger ones are on the right side of the piviot and then it returns the piviot */
int partition(vector<Prisoners*> &array, int first, int last)
{
    // cout << "yhaan partition honi he\n";
    Prisoners* piviot = array[last];
    int j = first - 1;
    for (int i = first; i < last; i++)
    {
        /*yaar main ni khelta yaar ye kya chawal he mujh se ni hora ye code theek kya L he ye sara 😭😭😭😭😭😭😭*/
        if (array[i]->root->less_than(piviot->root))
        {
            j++;
            swap(array[j], array[i]);
        }
    }
    swap(array[j+1], array[last]);
    piviot=nullptr;
    return j + 1;
}
/*AB YE BHEEN KI TKKI SORTING GND KR RI HEEE IS KIII L PE MERE
LORA MERA. FUCK THIS SHIT FUCK THIS CODE. ITS 10 in THE NIGHT AND I HAVE BEEN ATIT SINCE
8 IN THE FUCKING MORNING*/
void quick_sort(vector<Prisoners*> &array, int first, int last)
{
    if (first < last)
    {
        int mid = partition(array, first, last); // ye function hmeen mid point deta he
        quick_sort(array, first, mid - 1);       // mid se left pe recurse kro
        quick_sort(array, mid + 1, last);        // mid se right pe recurse kro
    }
}

//// template <typename datatype>
//// void quick_swap(datatype &a, datatype &b)
//// {
////     datatype temp = a;
////     b = a;
////     a = temp;
//// }

//the peek function checks the next character in the file without extracting it.
//if teh peek is equal to the end of file character then that means there are no more characters to read.
//since we are checking the first character then that means there are no characters in the file at all. 
bool is_it_empty(ifstream& pFile)
{
    return pFile.peek() == ifstream::traits_type::eof();
}

char* get_time()
{
    // current date and time on the current system
    time_t now = time(0);
    //gives the time in the form of some integer.
    // idk what that shit is. you wann a see it. 
    // cout << now << endl; // here is a cout statement. see for yourself.

   // convert now to string form
   return ctime(&now);
}
