#pragma once

#include <cstdint>

#include "gnomeutils/protectedmem.h"

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
            ProtectedMemory mem(&mTable[index]);
            mem.set(reinterpret_cast<void*>(funcPtr));
        }
        
        void* getObject();
    private:
        void** mObject;
        uintptr_t* mTable;
    };
}