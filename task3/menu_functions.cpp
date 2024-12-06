#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

const ioa::MenuItem* ioa::show_menu(const MenuItem* current){
    for (int i = 1; i < current->children_count; i++) {
        std::cout << current->children[i]->title << std::endl;
    }
    std::cout << current->children[0]->title << std::endl;
    std::cout << "Образовака > ";

    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;

    return current->children[user_input];
}

const ioa::MenuItem* ioa::exit(const MenuItem* current) {
    std::exit(0);
}

const ioa::MenuItem* ioa::institute_spbu(const MenuItem* current){
    //
    std::cout << current->title << std::endl;
    return current->parent;
}
const ioa::MenuItem* ioa::institute_itmo(const MenuItem* current){
    //
    std::cout << current->title << std::endl;
    return current->parent;
}
const ioa::MenuItem* ioa::institute_spbstu(const MenuItem* current){
    //
    std::cout << current->title << std::endl;
    return current->parent;
}
const ioa::MenuItem* ioa::institute_etu(const MenuItem* current){
    //
    std::cout << current->title << std::endl;
    return current->parent;
}
const ioa::MenuItem* ioa::institute_back(const MenuItem* current){
    //
    return current->parent->parent;
}