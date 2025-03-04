#include "menu_items.hpp"

#include "cstddef"

#include "menu_functions.hpp"

const ioa::MenuItem ioa::SPBU_AMCP = {
    "1 - Факультет ПМ-ПУ", ioa::spbu_amcp, &ioa::INSTITUTES_SPBU
};
const ioa::MenuItem ioa::SPBU_MATH = {
    "2 - Факультет МатМех", ioa::spbu_math, &ioa::INSTITUTES_SPBU
};
const ioa::MenuItem ioa::SPBU_LING = {
    "3 - Лингвистический факультет", ioa::spbu_ling, &ioa::INSTITUTES_SPBU
};
const ioa::MenuItem ioa::SPBU_GO_BACK = {
    "0 - Выйти в предыдущее меню", ioa::go_back, &ioa::INSTITUTES_SPBU
};

namespace {
    const ioa::MenuItem* const spbu_children[] = {
        &ioa::SPBU_GO_BACK,
        &ioa::SPBU_AMCP,
        &ioa::SPBU_MATH,
        &ioa::SPBU_LING
    };
    const int spbu_size = sizeof(spbu_children) / sizeof(spbu_children[0]);
}

const ioa::MenuItem ioa::INSTITUTES_SPBU = {
    "1 - СПбГУ", ioa::show_menu, &ioa::SEE_INSTITUTES, spbu_children, spbu_size
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
    "0 - Выйти в главное меню", ioa::go_back, &ioa::SEE_INSTITUTES
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
        &ioa::EXIT,
        &ioa::SEE_INSTITUTES
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const ioa::MenuItem ioa::MAIN = {
    nullptr, ioa::show_menu, nullptr, main_children, main_size
};