#include "Physical.h"

Physical::Physical() {
    this->next = NULL;
    this->down = NULL;
}

void Physical::execute(Message *message, bool sending) {
    if (sending)
    {
        if (next == NULL)
        {
            std::cout << "NOT CONNECTED TO A NETWORK" << std::endl;
            message->PrintMessage();
        }
        else
            this->next->execute(message, false);
    }
    else
    {
        std::cout << "Message at Physical layer of computer: " << this->computerName << std::endl;
        this->up->execute(message, false);
    }
}

Physical::~Physical() {
    if (this->next != NULL) {
        Physical* prev = this->next;
        while(prev->next != this) {
            prev = prev->next;
        }
        prev->next = this->next;
        this->next = NULL;
    }
}

void Physical::link(Layer *LinkStack) {

    Layer* nodePtr = LinkStack;

    while (nodePtr->getDown() != NULL)
        nodePtr = nodePtr->getDown();

    Physical* right = (dynamic_cast<Physical*>(nodePtr));

    if (this->next == NULL)
    {
        right->next = this;
        this->next = right;
    }
    else
    {
        right->next = this->next;
        this->next = right;
    }
}

Physical *Physical::getNext() {
    return this->next;
}

void Physical::setNext(Physical *newNext) {
    this->next = newNext;
}

void Physical::configure(config settings) {
    this->computerName = settings.computerName;
}
