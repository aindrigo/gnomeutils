#pragma once

#include <map>
#include <vector>
#include <cstdint>

#define MAX_CALLBACKS 0xFFFF
namespace GnomeUtils
{
    typedef void EventCallback(const char* name, std::vector<void*> args);
    typedef uint16_t EventHandle;

    class EventSystem
    {
    public:
        void Broadcast(const char* name, std::vector<void*> args);
        EventHandle AddCallback(const char* name, EventCallback* callback);
        void RemoveCallback(EventHandle handle);
    private:
        std::map<EventHandle, EventCallback*> callbacks;
    };
}