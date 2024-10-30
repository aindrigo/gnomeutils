#pragma once

#include "gnomeutils/protectedmem.h"

#if defined(_WIN32)
#include <Windows.h>
#elif defined(__unix__)
#include <dlfcn.h>
#endif

namespace GnomeUtils
{
    class SharedObject
    {
    public:
        SharedObject(const char* modulePath);
        ProtectedMemory GetProcAddress(const char* symbolName);
#if defined(__unix__)
        void Close();
#endif
    private:
        const char* mPath;
#if defined(_WIN32)
        HMODULE mHandle;
#elif defined(__unix__)
        void* mHandle;
#endif
    };
}