#include "gnomeutils/hooks.h"
#include "include/gnomeutils/protectedmem.h"

namespace GnomeUtils
{
    Hook::Hook(void* source, void* payload) : mProt(&source), mSource(mProt.GetCopy()), mPayload(payload)
    {}

    void Hook::Init()
    {
        this->mProt.Set(mPayload);
    }

    void* Hook::GetSource()
    {
        return mSource;
    }
}