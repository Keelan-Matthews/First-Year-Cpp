#ifndef A4_PRESENTATION_H
#define A4_PRESENTATION_H
#include <iostream>
#include "Message.h"
#include "Layer.h"

class Presentation : public Layer {
private:
    std::string encoding;
public:
    Presentation();
    void execute(Message* message, bool sending = true);
    void configure(config settings);
};


#endif