#include "Addons.h"
#include "Visitor.h"

istream &operator>>(istream &in, Visitor &visitor)
{
    cout<<"\n\t\t\tInput Visitor Information\n\n";
    visitor.apnaData->input();
    cout<<"\n\t\t\tInput Prisoner Information\n\n";
    visitor.relData->input();
}

Visitor::Visitor(Hierarchial_tree* tree)
{
    this->apnaData = nullptr;
    this->relData = nullptr;
    this->allData = tree;           //pointing to hierarchial tree to get all the prisoners data
}
