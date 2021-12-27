#include "Presentation.h"
#include "Transport.h"

Presentation::Presentation() {
    this->down = new Transport();
    this->down->setUp(this);
}

void Presentation::execute(Message *message, bool sending) {
    if (sending)
    {
        message->setEncoding(encoding);
        this->down->execute(message, sending);
    }
    else
    {
        if (encoding == message->getEncoding())
        {
            std::cout << "Message at Presentation layer on computer: " << this->computerName << std::endl;
            this->up->execute(message, false);
        }
        else
        {
            std::cout << "Encoding type mismatch on computer: " << this->computerName << " Expected: " << this->encoding << std::endl;
            message->PrintMessage();
        }
    }
}

void Presentation::configure(config settings) {
    this->encoding = settings.encoding;
    Layer::configure(settings);
}
