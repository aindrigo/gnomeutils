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
}