#include "menu_items.hpp"

#include "cstddef"

#include "menu_functions.hpp"

const ioa::MenuItem ioa::INSTITUTES_SPBU = {
    "1 - СПБГУ", ioa::institutes_spbu, &ioa::SEE_INSTITUTES
};
const ioa::MenuItem ioa::INSTITUTES_ITMO = {
    "2 - ИТМО", ioa::institutes_itmo, &ioa::SEE_INSTITUTES
};
const ioa::MenuItem ioa::INSTITUTES_SPBSTU = {
    "3 - Политех", ioa::institutes_spbstu, &ioa::SEE_INSTITUTES
};
const ioa::MenuItem ioa::INSTITUTES_ETU = {
    "4 - ЛЭТИ", ioa::institutes_etu, &ioa::SEE_INSTITUTES
};
const ioa::MenuItem ioa::INSTITUTES_GO_BACK = {
    "0 - Выйти в главное меню", ioa::institutes_go_back, &ioa::SEE_INSTITUTES
};

namespace {
    const ioa::MenuItem* const institutes_children[] = {
        &ioa::INSTITUTES_GO_BACK,
        &ioa::INSTITUTES_SPBU,
        &ioa::INSTITUTES_ITMO,
        &ioa::INSTITUTES_SPBSTU,
        &ioa::INSTITUTES_ETU
    };
    const int institutes_size = sizeof(institutes_children) / sizeof(institutes_children[0]);
}

const ioa::MenuItem ioa::SEE_INSTITUTES = {
    "1 - Посмотреть университеты Санкт-Петербурга", ioa::show_menu, &ioa::MAIN, institutes_children, institutes_size
};

const ioa::MenuItem ioa::EXIT = {
    "0 - Я уже студент", ioa::exit, &ioa::MAIN
};

namespace {
    const ioa::MenuItem* const main_children[] = {
        &ioa::SEE_INSTITUTES,
        &ioa::EXIT
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const ioa::MenuItem ioa::MAIN = {
    nullptr, ioa::show_menu, nullptr, main_children, main_size
};