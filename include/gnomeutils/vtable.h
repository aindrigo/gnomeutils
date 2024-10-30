#pragma once

#include <cstdint>

#ifdef _WIN32
#include <Windows.h>
#elif __unix__
#include <unistd.h>
typedef unsigned long long DWORD;
#endif

namespace GnomeUtils
{
    class VTable
    {
    public:
        VTable(void** object) : mObject(object), mTable(*reinterpret_cast<uintptr_t**>(*object))
        {}

        template<typename T>
        T* getFunction(uint8_t index)
        {
            return reinterpret_cast<T*>(mTable[index]);
        }

        template <typename T>
        void setFunction(uint16_t index, T* funcPtr)
        {
            unprotect(index);
            mTable[index] = reinterpret_cast<uintptr_t>(funcPtr);
            protect(index);
        }

        
        void* getObject();
    private:
        void protect(uint16_t index);
        void unprotect(uint16_t index);

        void** mObject;
        uintptr_t* mTable;
    #ifdef _WIN32
        DWORD mProtection;
    #endif
    };
}