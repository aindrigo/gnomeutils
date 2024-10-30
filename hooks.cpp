#include "gnomeutils/hooks.h"
#include "include/gnomeutils/protectedmem.h"

namespace GnomeUtils
{
    void Hook::Init(void* source, void* payload)
    {
        this->mProt = new ProtectedMemory(&source);
        this->mSource = mProt.getCopy();

        this->mProt.set(payload);

        this->mPayload = payload;
    }

    void* Hook::GetSource()
    {
        return mSource;
    }
}