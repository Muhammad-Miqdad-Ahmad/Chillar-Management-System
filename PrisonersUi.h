#pragma once
#include "hierarchy.h"

class PrisonersUi
{
public:
    Hierarchial_tree* mainTree;
    Prisoners* prisoner;
    abstract* find;
    PrisonersUi(Hierarchial_tree* ht);

    void signIn();
    void turnIn();
    void viewData();

}; 