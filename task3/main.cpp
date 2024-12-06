#include <clocale>
#include <iostream>

#include "menu.hpp"
#include "menu_functions.hpp"

int main()
{
    std::setlocale(LC_ALL, "");

    ioa::MenuItem institute_spbu = { "1 - СПБГУ", ioa::institute_spbu};
    ioa::MenuItem institute_itmo = { "2 - ИТМО", ioa::institute_itmo};
    ioa::MenuItem institute_spbstu = { "3 - Политех", ioa::institute_spbstu};
    ioa::MenuItem institute_etu = { "4 - ЛЭТИ", ioa::institute_etu};
    ioa::MenuItem institute_back = { "0 - Выйти в главное меню", ioa::institute_back};

    ioa::MenuItem* institute_children[] = {
        &institute_back,
        &institute_spbu,
        &institute_itmo,
        &institute_spbstu,
        &institute_etu
    };
    const int study_size = sizeof(institute_children) / sizeof(institute_children[0]);

    ioa::MenuItem see_institutes = { "1 - посмотерть университеты Санкт-Петербурга", ioa::study };
    ioa::MenuItem exit = { "0 - Я уже студент", ioa::exit };
    
    ioa::MenuItem* main_children[] = { &exit, &see_institutes };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);

    int user_input;
    do {
        std::cout << "Главное меню:" << std::endl;
        for (int i = 1; i < main_size; i++) {
            std::cout << main_children[i]->title << std::endl;
        }
        std::cout << main_children[0]->title << std::endl;
        std::cout << "Образовака > ";

        std::cin >> user_input;
        main_children[user_input]->func();

        std::cout << std::endl;
    } while (true);

    return 0;
}