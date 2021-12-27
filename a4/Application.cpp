#include "Application.h"
#include "Presentation.h"

Application::Application() {
   this->down = new Presentation();
   this->down->setUp(this);
}

void Application::execute(Message *message, bool sending) {
    if (sending)
        this->down->execute(message, sending);
    else
    {
        std::cout << "Computer " << this->computerName << " Received message: " << message->getData() << std::endl;
    }
}

void Application::execute(std::string data, int contentLength) {
    Message* newMessage = new Message(data);
    newMessage->setContentLength(contentLength);
    this->down->execute(newMessage, true);
}
