#include "include/gnomeutils/protectedmem.h"
#include <gnomeutils/sharedobject.h>
#include <stdexcept>

namespace GnomeUtils
{
    SharedObject::SharedObject(const char* modulePath)
    {
#if defined(_WIN32)
        this->mHandle = LoadLibraryA(modulePath);
#elif defined(__unix__)
        this->mHandle = dlopen(modulePath, RTLD_LAZY);
#endif
        if (!this->mHandle)
        {
            char msg[21] = "Invalid module path ";
            strcat_s(msg, modulePath);
            throw std::runtime_error(msg);
        }
    }

    ProtectedMemory SharedObject::GetProcAddress(const char* symbolName)
    {
#if defined(_WIN32)
        void* proc = reinterpret_cast<void*>(::GetProcAddress(this->mHandle, symbolName));
#elif defined(__unix__)
        void* proc = dlsym(this->mHandle, symbolName);
#endif
        if (!proc)
        {
            char msg[34] = "Attempted to load invalid symbol ";
            strcat_s(msg, symbolName);
            throw std::runtime_error(msg);
        }

        return new ProtectedMemory(proc);
    }

#if defined(__unix__)
    void SharedObject::Close()
    {
        dlclose(this->mHandle);
    }
#endif
}