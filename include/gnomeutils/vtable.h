#pragma once

#include <cstdint>

#include "gnomeutils/hooks.h"

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

        Hook createHook(uint16_t index, void* payload);
        
        void* getObject();
    private:
        void** mObject;
        uintptr_t* mTable;
    };
}