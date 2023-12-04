#pragma once
#include "hierarchy.h"

class Visitor{
    abstract* apnaData;
    abstract* relData;
    Hierarchial_tree* allData;

    Visitor(Hierarchial_tree*);
    friend istream &operator>>(istream &in, Visitor &visitor);
};

