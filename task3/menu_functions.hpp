#pragma once

#include "menu.hpp"

namespace ioa {
    const MenuItem* show_menu(const MenuItem* current);

    const MenuItem* exit(const MenuItem* current);

    // const MenuItem* institutes_spbu(const MenuItem* current);
    const MenuItem* institutes_itmo(const MenuItem* current);
    const MenuItem* institutes_spbstu(const MenuItem* current);
    const MenuItem* institutes_etu(const MenuItem* current);
    const MenuItem* institutes_go_back(const MenuItem* current);

    const MenuItem* spbu_amcp(const MenuItem* current);
    const MenuItem* spbu_math(const MenuItem* current);
    const MenuItem* spbu_ling(const MenuItem* current);
    const MenuItem* spbu_go_back(const MenuItem* current);
}