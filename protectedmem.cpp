#include "gnomeutils/protectedmem.h"
#include "gnomeutils/functions.h"

namespace GnomeUtils
{
    ProtectedMemory::ProtectedMemory(void* data)
    {
        this->mData = data;
    }

    void* ProtectedMemory::GetCopy()
    {
        void* copy;
        memcpy(copy, this->mData, sizeof(void*));
        return copy;
    }

    void ProtectedMemory::UnProtect()
    {
        auto val = GnomeUtils::UnProtect(&mData);

        #if defined(_WIN32)
        this->mProtection = (unsigned long)val;
        #endif
    }

    void ProtectedMemory::Protect()
    {
        GnomeUtils::Protect(
            &mData, 
#if defined(_WIN32)
            this->mProtection
#else
            nullptr
#endif
        );

        
    }

    void ProtectedMemory::Set(void* data)
    {
        UnProtect();
        *(void**)this->mData = data;
        Protect();
    }

    void* ProtectedMemory::Get()
    {
        return this->mData;
    }
}