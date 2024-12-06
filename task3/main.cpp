#include <clocale>
#include <iostream>

#include "menu.hpp"
#include "menu_functions.hpp"

int main()
{
    std::setlocale(LC_ALL, "");

    ioa::MenuItem institute_spbu = { "1 - СПБГУ", ioa::institute_spbu };
    ioa::MenuItem institute_itmo = { "2 - ИТМО", ioa::institute_itmo };
    ioa::MenuItem institute_spbstu = { "3 - Политех", ioa::institute_spbstu };
    ioa::MenuItem institute_etu = { "4 - ЛЭТИ", ioa::institute_etu };
    ioa::MenuItem institute_back = { "0 - Выйти в главное меню", ioa::institute_back };

    ioa::MenuItem* institute_children[] = {
        &institute_back,
        &institute_spbu,
        &institute_itmo,
        &institute_spbstu,
        &institute_etu
    };
    const int institute__size = sizeof(institute_children) / sizeof(institute_children[0]);

    ioa::MenuItem see_institutes = { "1 - посмотерть университеты Санкт-Петербурга", ioa::show_menu, institute_children, institute__size };
    ioa::MenuItem exit = { "0 - Я уже студент", ioa::exit };
    
    ioa::MenuItem* main_children[] = { &exit, &see_institutes };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);

    ioa::MenuItem main = { nullptr, ioa::show_menu, main_children, main_size };

    main.func(&main);
    int user_input;
    do {
        std::cin >> user_input;
        std::cout << std::endl;

        main.children[user_input]->func(main.children[user_input]);
    } while (true);

    return 0;
}