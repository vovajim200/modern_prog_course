#pragma once

#include "menu.hpp"

namespace ioa {
    void show_menu(const MenuItem* current);

    void exit(const MenuItem* current);

    void institute_spbu(const MenuItem* current);
    void institute_itmo(const MenuItem* current);
    void institute_spbstu(const MenuItem* current);
    void institute_etu(const MenuItem* current);
    void institute_back(const MenuItem* current);
}