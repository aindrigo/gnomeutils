#include <gnomeutils/vtable.h>
#include <gnomeutils/functions.h>

namespace GnomeUtils
{
    void* VTable::getObject()
    {
        return *mObject;
    }
}