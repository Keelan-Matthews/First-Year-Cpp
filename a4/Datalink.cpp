#include "Datalink.h"
#include "Physical.h"

Datalink::Datalink() {
    this->down = new Physical();
    this->down->setUp(this);
}

void Datalink::execute(Message *message, bool sending) {
    if (sending)
        this->down->execute(message, true);
    else
    {
        std::cout << "Message at Datalink layer" << std::endl;
        this->up->execute(message, false);
    }
}
