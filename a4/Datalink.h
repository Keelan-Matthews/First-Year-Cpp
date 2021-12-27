#ifndef A4_DATALINK_H
#define A4_DATALINK_H
#include "Layer.h"

class Datalink : public Layer {
public:
    Datalink();
    void execute(Message* message, bool sending = true);
};


#endif
