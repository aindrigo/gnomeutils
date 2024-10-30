#pragma once

#include "gnomeutils/protectedmem.h"

namespace GnomeUtils
{
    class Hook
    {
    public:
        Hook(void* source, void* payload);

        void Init(); // if returnSourceValue is on then the value of source is returned and not payload
        void* GetSource();
    private:
        ProtectedMemory mProt;
        void* mSource;
        void* mPayload;
    };
}