#include "Addons.h"

/* This function is used in the quick sort This makes one index the piviot of the array
And then it sorts the array such that the smaller ones are on the left of the piviot and
the bigger ones are on the right side of the piviot and then it returns the piviot */
int partition(vector<Prisoners*> &array, int first, int last)
{
    cout << "yhaan partition honi he\n";
    Prisoners* piviot = array[last];
    int j = first - 1;
    for (int i = first; i < last; i++)
    {
        /*yaar main ni khelta yaar ye kya chawal he mujh se ni hora ye code theek kya L he ye sara 😭😭😭😭😭😭😭*/
        cout << "yhi bta do agar calll ho rha hee toooo 😭😭😭😭😭😭\n";
        if (array[j]->root <= piviot->root)
        {
            cout << "If k andar aara he?\n";
            j++;
            swap(array[j], array[i]);
        }
    }
    cout << "Khaan lore lg re hain beeee\n";
    swap(array[j], array[last]);
    piviot=nullptr;
    return j + 1;
}
/*AB YE BHEEN KI TKKI SORTING GND KR RI HEEE IS KIII L PE MERE
LORA MERA. FUCK THIS SHIT FUCK THIS CODE. ITS 10 in THE NIGHT AND I HAVE BEEN ATIT SINCE
8 IN THE FUCKING MORNING*/
void quick_sort(vector<Prisoners*> &array, int first, int last)
{
    cout << "Ye sort ka function he\n";
    if (first < last)
    {
        int mid = partition(array, first, last); // ye function hmeen mid point deta he
        quick_sort(array, first, mid - 1);       // mid se left pe recurse kro
        quick_sort(array, mid + 1, last);        // mid se right pe recurse kro
    }
}

// template <typename datatype>
// void quick_swap(datatype &a, datatype &b)
// {
//     datatype temp = a;
//     b = a;
//     a = temp;
// }
