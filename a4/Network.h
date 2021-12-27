#ifndef A4_NETWORK_H
#define A4_NETWORK_H
#include "Layer.h"

class Network : public Layer {
private:
    std::string  ip;
    std::string DestIP;
public:
    Network();
    void execute(Message* message, bool sending = true);
    void configure(config settings);
};


#endif
