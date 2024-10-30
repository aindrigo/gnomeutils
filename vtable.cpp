#include "include/gnomeutils/hooks.h"
#include <gnomeutils/vtable.h>
#include <gnomeutils/functions.h>

namespace GnomeUtils
{
    void* VTable::getObject()
    {
        return *mObject;
    }

    Hook VTable::createHook(uint16_t index, void* payload)
    {
        Hook hook(&mTable[index], payload);
        hook.Init();

        return hook;
    }
}