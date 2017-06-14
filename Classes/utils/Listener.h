#ifndef __LISTENER_H__
#define __LISTENER_H__

#include <string>

class Listener {

public:
    virtual void notify(std::string message);
};

#endif
