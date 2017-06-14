#include "EventPusher.h"

void EventPusher::addListener(Listener* listener) {
    _listeners.push_back(listener);
}

void EventPusher::notifyListeners(std::string message) {
    for (const auto& listener : _listeners) {
        listener->notify(message);
    }
}
