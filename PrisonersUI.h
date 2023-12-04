#pragma once
#include "hierarchy.h"

class PrisonersUi
{
public:
    Hierarchial_tree* mainTree;
    Prisoners* prisoner;
    string prisonerName, id, grade;
    PrisonersUi(Hierarchial_tree* data);

    bool signIn();
    void turnIn();
};