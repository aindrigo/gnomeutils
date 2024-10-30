#include <gnomeutils/vtable.h>

namespace GnomeUtils
{
    void* VTable::getObject()
    {
        return *mObject;
    }

    void VTable::protect(uint16_t index)
    {
    #ifdef _WIN32
        VirtualProtect(&mTable[index], sizeof(void*), mProtection, &mProtection);
#elif __unix__
        mprotect(p, sizeof(void*), PROT_READ | PROT_WRITE);
#endif
    }

    void VTable::unprotect(uint16_t index)
    {
#ifdef _WIN32
        VirtualProtect(&mTable[index], sizeof(void*), PAGE_EXECUTE_READWRITE, &mProtection);
#elif __unix__
        mprotect(p, sizeof(void*), PROT_READ | PROT_WRITE | PROT_EXEC);
#endif
    }
}