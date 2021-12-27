#ifndef A4_APPLICATION_H
#define A4_APPLICATION_H
#include "Message.h"
#include "Layer.h"

class Application : public Layer {
public:
    Application();
    void execute(Message* message, bool sending = true);
    void execute(std::string data, int contentLength);
};


#endif
