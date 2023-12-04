#include "Addons.h"
#include "Visitor.h"

Visitor::Visitor(Hierarchial_tree* tree)
{
    this->apnaData = nullptr;
    this->relData = nullptr;
    this->allData = tree;           //pointing to hierarchial tree to get all the prisoners data
}

void Visitor::getPrisoner()
{
    Prisoners* prisoner = this->allData->searchGrade(allData->root, this->relData);
    if(prisoner->relative_1->equal(this->apnaData) || prisoner->relative_2->equal(this->apnaData))
    {
        switch (prisoner->root->ID[0])
        {
            case 'D':
            {
                cout<<"\nYou can visit on Monday from 9 am to 12 pm";
                break;
            }
            case 'E':
            {
                cout<<"\nYou can visit on Tuesday from 9 am to 12 pm";
                break;
            }
            case 'F':
            {
                cout<<"\nYou can visit on Wednesday from 9 am to 12 pm";
                break;
            }
            case 'G':
            {
                cout<<"\nYou can visit on Thursday from 9 am to 12 pm";
                break;
            }
        }
    }
    else
    {
        cout<<"\nCredentials do not match!!";
    }
}

void Visitor::visitor_UI()
{
    cout<<"\n\t\t\tInput Visitor Information\n\n";
    this->apnaData->input();
    cout<<"\n\t\t\tInput Prisoner Information\n\n";
    this->relData->input();
    this->getPrisoner();
}
