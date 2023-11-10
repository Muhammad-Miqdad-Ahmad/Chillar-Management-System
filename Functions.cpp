#include "Addons.h"

/* This function is used in the quick sort This makes one index the piviot of the array
And then it sorts the array such that the smaller ones are on the left of the piviot and
the bigger ones are on the right side of the piviot and then it returns the piviot */
template <typename datatype>
int partition(vector<datatype> &array, int first, int last)
{
    datatype piviot = array[last];
    datatype j = first - 1;
    for (int i = first; i < last; i++)
    {
        if (array[j] <= piviot)
        {
            j++;
            swap(array[j], array[i]);
        }
    }
    swap(array[j], array[last]);
    return j + 1;
}

template <typename datatype>
void quick_sort(vector<datatype> &array, int first, int last)
{
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
