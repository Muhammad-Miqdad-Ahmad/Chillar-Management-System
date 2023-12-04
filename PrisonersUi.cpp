#pragma once
#include "Addons.h"

PrisonersUi::PrisonersUi(Hierarchial_tree* data){
    this->mainTree = data;
    prisonerName = id = grade = "";
}

bool PrisonersUi::signIn(){
    cout << "Enter your Name: ";
    getline(cin, prisonerName);
    cout << "\nEnter your ID: ";
    cin >> id;
    cout << endl;
    grade = id[0];
    
    //!yaha searching ho gi k jo data input kiya hai wo theak hai ya galat hai,
    //!agr galat hai to prisoner dubara input kare ga. 

    
}

void PrisonersUi::turnIn(){
    
}