#pragma once

#include <cstdint>

namespace GnomeUtils
{
    void message(const char* title, const char* msg, ...);
    void protect(void* address, uintptr_t protection);
    void* unprotect(void* address);
}