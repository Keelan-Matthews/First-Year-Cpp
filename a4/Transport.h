#ifndef A4_TRANSPORT_H
#define A4_TRANSPORT_H
#include "Layer.h"
#include <iostream>

class Transport : public Layer {
private:
    std::string port;
    std::string DestPort;
public:
    Transport();
    void execute(Message* message, bool sending = true);
    void configure(config settings);
};


#endif
