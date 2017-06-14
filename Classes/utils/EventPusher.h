#ifndef __EVENT_PUSHER__H
#define __EVENT_PUSHER__H

#include <vector>
#include <string>
#include "Listener.h"

class EventPusher {

public:
    void addListener(Listener* listener);

    void notifyListeners(std::string message);

private:
    std::vector<Listener*> _listeners;
};

#endif // __EVENT_PUSHER__H
