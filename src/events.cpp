#include "gnomeutils/events.h"

namespace GnomeUtils
{
    void EventSystem::Broadcast(const char* name, std::vector<void*> args)
    {
        for (auto const& [key, value] : callbacks)
        {
            std::vector<void*> copy(args);

            value(name, copy);
        }
    }

    EventHandle EventSystem::AddCallback(const char* name, EventCallback* callback)
    {
        for (int i = 1; i < MAX_CALLBACKS; i++)
        {
            if (!callbacks.contains(i))
            {
                EventHandle handle = i;
                callbacks[handle] = callback;

                return handle;
            }
        }

        return 0; // 0 is reserved for null callbacks
    }

    void EventSystem::RemoveCallback(EventHandle handle)
    {
        if (!callbacks.contains(handle))
        {
            return;
        }

        callbacks[handle] = nullptr;
    }
}