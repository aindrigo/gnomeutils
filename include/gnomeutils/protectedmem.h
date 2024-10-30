#pragma once

#ifdef _WIN32
#include <Windows.h>
#endif

namespace GnomeUtils
{
    class ProtectedMemory
    {
    public:
        ProtectedMemory(void* data);

        void protect();
        void unprotect();

        void* getCopy();
        void set(void* value);
    private:
        void* mData;
    #ifdef _WIN32
        DWORD mProtection;
    #endif
    };
}