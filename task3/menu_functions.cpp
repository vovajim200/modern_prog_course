#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

void ioa::show_menu(const MenuItem* current){
    for (int i = 1; i < current->children_count; i++) {
        std::cout << current->children[i]->title << std::endl;
    }
}

void ioa::exit(const MenuItem* current) {
    std::exit(0);
}

void ioa::institute_spbu(const MenuItem* current){
    //
}
void ioa::institute_itmo(const MenuItem* current){
    //
}
void ioa::institute_spbstu(const MenuItem* current){
    //
}
void ioa::institute_etu(const MenuItem* current){
    //
}
void ioa::institute_back(const MenuItem* current){
    //
}