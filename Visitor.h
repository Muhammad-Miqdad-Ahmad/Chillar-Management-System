#pragma once
#include "hierarchy.h"

class Visitor{
    abstract* apnaData;
    abstract* relData;
    Hierarchial_tree* allData;

    Visitor(Hierarchial_tree*);
    void getPrisoner();
    bool visitor_UI();
    friend istream &operator>>(istream &in, Visitor &visitor);
};

