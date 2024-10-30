#include "gnomeutils/hooks.h"
#include "include/gnomeutils/protectedmem.h"
#include <cstring>

namespace GnomeUtils
{
    void Hook::Init(void* source, void* payload)
    {
        memcpy(this->mSource, source, sizeof(source));
        
        this->mPayload = payload;

        this->mProt = new ProtectedMemory(&source);
        this->mProt.set(payload);
    }
}