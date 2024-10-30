#pragma once

#include "gnomeutils/protectedmem.h"

namespace GnomeUtils
{
    class Hook
    {
    public:
        Hook();

        void Init(void* source, void* payload); // if returnSourceValue is on then the value of source is returned and not payload
        void* GetSource();
    private:
        ProtectedMemory mProt;
        void* mSource;
        void* mPayload;
    };
}