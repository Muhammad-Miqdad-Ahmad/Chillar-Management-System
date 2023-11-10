#pragma once
#include "hierarchy.h"
#include "Visitor.h"
#include <fstream>
#include <string>

// template <typename datatype>
// ostream &operator<<(ostream &out, const datatype *&chunk);

//global functions
template<typename datatype>
int partition(vector<datatype> &array, int first, int last);

template<typename datatype>
void quick_sort(vector<datatype> &array, int first, int last);

// global operator overloads
Prisoners* operator%(Hierarchy* &chunk, string data);
Prisoners* operator%(Prisoners* &chunk, string data);

// The namespace that will contain all constants
namespace Constants
{
    static const char hierarchial_classes[] = "DBFACEG";
} // namespace Constants
