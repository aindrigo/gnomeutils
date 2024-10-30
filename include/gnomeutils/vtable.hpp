#pragma once

#include <cstdint>

#ifdef _WIN32
#include <Windows.h>
#elif __unix__
#include <unistd.h>
typedef unsigned long long DWORD;
#endif

class VTable
{
public:
    VTable(void** object) : mObject(object), mTable(*reinterpret_cast<uintptr_t**>(*object))
    {}

    template<typename T>
    T* getFunction(uint16_t index)
    {
        return reinterpret_cast<T*>(mTable[index]);
    }

    template <typename T>
    void setFunction(uint16_t index, T* funcPtr)
    {
        unprotect(index);
        mTable[index] = reinterpret_cast<uintptr_t>(funcPtr);
        protect(index);
    }

    void* getObject()
    {
        return *mObject;
    }

private:
    void protect(uint16_t index)
    {
#ifdef _WIN32
        VirtualProtect(&mTable[index], sizeof(void*), mProtection, &mProtection);
#elif __unix__
        mprotect(p, sizeof(void*), PROT_READ | PROT_WRITE);
#endif
    }

    void unprotect(uint16_t index)
    {
#ifdef _WIN32
        VirtualProtect(&mTable[index], sizeof(void*), PAGE_EXECUTE_READWRITE, &mProtection);
#elif __unix__
        mprotect(p, sizeof(void*), PROT_READ | PROT_WRITE | PROT_EXEC);
#endif
    }

    void** mObject;
    uintptr_t* mTable;
#ifdef _WIN32
    DWORD mProtection;
#endif
};