#pragma once

#include "hierarchy.h"
#include <windows.h>
#include "Visitor.h"
#include <typeinfo>
#include <fstream>
#include "admin.h"
#include <string>
#include <limits>
#include <queue>
#include <ctime>
//// template <typename datatype>
//// ostream &operator<<(ostream &out, const datatype *&chunk);

// global functions
char *get_time();
bool is_it_empty(ifstream &pFile);
int partition(vector<Prisoners *> &array, int first, int last);
void quick_sort(vector<Prisoners *> &array, int first, int last);

// The namespace that will contain all constants
namespace Constants
{
    static const char hierarchial_classes[] = "DBFACEG";
    
    static const string monthNames[12] = {"January",
                                          "February",
                                          "March",
                                          "April",
                                          "May",
                                          "June",
                                          "July",
                                          "August",
                                          "Spetember",
                                          "October",
                                          "November",
                                          "December"};
} // namespace Constants
