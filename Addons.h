#pragma once
#include "hierarchy.h"
#include <windows.h>
#include "Visitor.h"
#include "admin.h"
#include <fstream>
#include <string>
// template <typename datatype>
// ostream &operator<<(ostream &out, const datatype *&chunk);

//global functions
int partition(vector<Prisoners*> &array, int first, int last);
void quick_sort(vector<Prisoners*> &array, int first, int last);

// global operator overloads
// template<typename datatype>
// ostream &operator << (ostream &out, Hierarchial_tree* &data); 
// ostream &operator << (ostream &out, Hierarchy* &data); 
// ostream &operator << (ostream &out, Person* &data); 
// ostream &operator << (ostream &out, Pris* &data); 
// void display(datatype* &data);
// void display(Person* &data);
// Prisoners* operator%(Hierarchy* &chunk, string data);
// Prisoners* operator%(Prisoners* &chunk, string data);

// The namespace that will contain all constants
namespace Constants
{
    static const char hierarchial_classes[] = "DBFACEG";
} // namespace Constants
