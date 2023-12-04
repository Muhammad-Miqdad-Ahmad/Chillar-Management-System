#include "Addons.h"

PrisonersUi::PrisonersUi(Hierarchial_tree* ht) {
    this->mainTree = ht;
    find = nullptr;
}

void PrisonersUi::signIn() {
    find = new Person;
    re:
    find->input();
    
    this->prisoner = this->mainTree->searchGrade(this->mainTree->root, find);
    cout<<"damn nigga\n";
    if (prisoner == nullptr)
    {
        cout<<"Prisoner not Found.\n Enter Again: \n";
        goto re;
    }
    find = nullptr;
}

void PrisonersUi::turnIn() {
    if (prisoner->workDone == true)
    {
        cout<< "Your today's work quota has been reached!!!\n";
        return;
    }
    cout<<"Trun in Successful.\n";
    prisoner->workDone = true;
    prisoner->credits = prisoner->credits + 10;
}

void PrisonersUi::viewData() {
    cout<<"Prisone Name: "<<prisoner->root->name<<endl;
    cout<<"Prisoner ID: "<<prisoner->root->ID<<endl;
    cout<<"Earned Credits: "<<prisoner->credits<<endl;
    cout<<"Today's work status: "<<prisoner->workDone ? "Completed\n" : "Pending\n";
}