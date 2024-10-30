#include <cstdint>
#include <cstdio>

#include <gnomeutils/functions.h>

#if defined(_WIN32)
#include <Windows.h>
#endif

namespace GnomeUtils
{
    void message(const char* title, const char* msg, ...)
    {
#if defined(_WIN32)
        MessageBoxA(NULL, title, msg, MB_ICONINFORMATION);
#endif
        printf("%s: %s", title, msg);
    }

    void protect(void* address, uintptr_t protection) // protection ignored on unix
    {
    #ifdef _WIN32
        VirtualProtect(address, sizeof(void*), protection, nullptr);
#elif __unix__
        mprotect(p, sizeof(void*), PROT_READ | PROT_WRITE);
#endif
    }

    void* unprotect(void* address)
    {
#ifdef _WIN32
        PDWORD prot;
        VirtualProtect(address, sizeof(void*), PAGE_EXECUTE_READWRITE, prot);
        return prot;
#elif __unix__
        mprotect(p, sizeof(void*), PROT_READ | PROT_WRITE | PROT_EXEC);
        return nullptr;
#endif
    }
}