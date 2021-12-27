#include "Network.h"
#include "Datalink.h"

Network::Network() {
    this->down = new Datalink();
    this->down->setUp(this);
}

void Network::execute(Message *message, bool sending) {
    if (sending)
    {
        bool error = message->setOriginIP(this->ip);
        if (!error)
        {
            std::cout << "ERROR OCCURRED WITH ORIGIN IP" << std::endl;
            return;
        }

        bool error2 = message->setDestinationIP(this->DestIP);
        if (!error2)
        {
            std::cout << "ERROR OCCURRED WITH DESTINATION IP" << std::endl;
            return;
        }

        this->down->execute(message, true);
    }
    else
    {
        if (message->getDestinationIP() == this->ip)
        {
            std::cout << "Message at Network layer" << std::endl;
            this->up->execute(message, false);
        }
        else if (message->getOriginIP() == this->ip)
        {
            std::cout << "Message has been returned to sender without finding the destination" << std::endl;
            message->PrintMessage();
        }
        else
        {
            std::cout << "Message at Network layer" << std::endl;
            this->down->execute(message, true);
        }
    }
}

void Network::configure(config settings) {
    this->ip = settings.ip;
    this->DestIP = settings.DestIP;
    Layer::configure(settings);
}
