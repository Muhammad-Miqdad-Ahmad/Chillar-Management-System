#pragma once
#include "hierarchy.h"

class PrisonersUi
{
private:
    Hierarchial_tree *mainTree;
    Prisoners *prisoner;
    abstract *find;

    void signIn();
    void turnIn();
    void viewData();

public:
    PrisonersUi(Hierarchial_tree *ht);
    void prisonerUi();
};