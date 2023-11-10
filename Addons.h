#pragma once
#include "hierarchy.h"
#include "Visitor.h"
#include <fstream>

template <typename data_type_1, typename data_type_2> // the function is template so that any class that needs to make a tree can use this function
void add_chunk(data_type_1 *&chunk, data_type_2 data);

// template <typename datatype>
// ostream &operator<<(ostream &out, const datatype *&chunk);

Prisoners* operator%(Hierarchy* &chunk, string data);
Prisoners* operator%(Prisoners* &chunk, string data);

// The namespace that will contain all constants
namespace Constants
{
    static const char hierarchial_classes[] = "DBFACEG";
} // namespace Constants
