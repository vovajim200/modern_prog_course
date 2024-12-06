#pragma once

namespace ioa {
    struct MenuItem {
        const char* const title;
        void (*func)();
    };
}