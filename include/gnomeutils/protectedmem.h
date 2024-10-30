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

        void Protect();
        void UnProtect();

        void* GetCopy();
        void* Get();
        void Set(void* value);
    private:
        void* mData;
    #ifdef _WIN32
        unsigned long mProtection;
    #endif
    };
}