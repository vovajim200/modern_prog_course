#pragma once

#include "menu.hpp"

namespace ioa {
    const MenuItem* show_menu(const MenuItem* current);

    const MenuItem* exit(const MenuItem* current);

    const MenuItem* institute_spbu(const MenuItem* current);
    const MenuItem* institute_itmo(const MenuItem* current);
    const MenuItem* institute_spbstu(const MenuItem* current);
    const MenuItem* institute_etu(const MenuItem* current);
    const MenuItem* institute_back(const MenuItem* current);
}