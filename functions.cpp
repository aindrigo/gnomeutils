#include <cstdio>

#if defined(_WIN32)
#include <Windows.h>
#elif defined(__unix__)
#include <sys/mman.h>
#endif
#include "gnomeutils/functions.h"

namespace GnomeUtils
{
    void message(const char* title, const char* msg, ...)
    {
#ifdef _WIN32
        MessageBoxA(NULL, title, msg, MB_ICONINFORMATION);
#endif
        printf("%s: %s", title, msg);
    }

    void Protect(void* address, unsigned long protection) // protection ignored on unix
    {
#ifdef _WIN32
        VirtualProtect(address, sizeof(void*), protection, &protection);
#elif __unix__
        mprotect(p, sizeof(void*), PROT_READ | PROT_WRITE);
#endif
    }

    unsigned long UnProtect(void* address)
    {
#ifdef _WIN32
        PDWORD prot;
        VirtualProtect(address, sizeof(void*), PAGE_EXECUTE_READWRITE, prot);
        return *prot;
#elif __unix__
        return mprotect(p, sizeof(void*), PROT_READ | PROT_WRITE | PROT_EXEC);
#endif
    }
}