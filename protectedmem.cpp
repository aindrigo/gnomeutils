#include "gnomeutils/protectedmem.h"
#include "gnomeutils/functions.h"

namespace GnomeUtils
{
    ProtectedMemory::ProtectedMemory(void* data)
    {
        this->mData = data;
    }

    void* ProtectedMemory::getCopy()
    {
        void* copy;
        memcpy(copy, this->mData, sizeof(void*));
        return copy;
    }

    void ProtectedMemory::unprotect()
    {
        auto val = GnomeUtils::unprotect(&mData);

        #if defined(_WIN32)
        this->mProtection = val;
        #endif
    }

    void ProtectedMemory::protect()
    {
        #if defined(_WIN32)
        GnomeUtils::protect(&mData, reinterpret_cast<uint64_t>(this->mProtection));
        #else
        GnomeUtils::protect(&mData, nullptr);
        #endif
    }

    void ProtectedMemory::set(void* data)
    {
        unprotect();
        *(void**)this->mData = data;
        protect();
    } 
}