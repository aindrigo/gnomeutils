#pragma once

namespace GnomeUtils
{
    void message(const char* title, const char* msg, ...);
    void Protect(void* address, unsigned long protection);
    unsigned long UnProtect(void* address);
}