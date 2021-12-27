#include "Message.h"
#include <sstream>

Message::Message(std::string Messagedata) {
    this->contentLength = Messagedata.length();
    this->Encoding = "";
    this->data = Messagedata;
    this->Destination = "";
    this->Origin = "";
}

Message::Message(Message *msg) {
    this->data = msg->data;
}

std::string Message::getData() {
    return this->data;
}

std::string Message::getDestination() {

    if (this->Destination == "" || getDestinationIP() == "ERROR: IPV4 NOT SET" || getDestinationPort() == "ERROR: PORT NOT SET")
        return "ERROR: INCOMPLETE ADDRESS";

    return this->Destination;
}

std::string Message::getOrigin() {
    if (this->Origin == "" || getOriginIP() == "ERROR: IPV4 NOT SET" || getOriginPort() == "ERROR: PORT NOT SET")
        return "ERROR: INCOMPLETE ADDRESS";

    return this->Origin;
}

std::string Message::getEncoding() {
    if (this->Encoding == "")
        return "";

    return this->Encoding;
}

std::string Message::getDestinationIP() {
    std::string ip;
    std::stringstream ss(Destination);

    getline(ss,ip,':');

    if (ip == "")
        return "ERROR: IPV4 NOT SET";

    return ip;
}

std::string Message::getDestinationPort() {
    std::string port;
    std::string ip;
    std::stringstream ss(Destination);
    getline(ss,ip,':');
    getline(ss, port);

    //port = Destination;
    //port.erase(0,ip.length()+1);

    if (port == "")
        return "ERROR: PORT NOT SET";

    return port;
}

std::string Message::getOriginIP() {
    std::string ip;
    std::stringstream ss(Origin);

    getline(ss,ip,':');

    if (ip == "")
        return "ERROR: IPV4 NOT SET";

    return ip;
}

std::string Message::getOriginPort() {
    std::string port;
    std::string ip;
    std::stringstream ss(Origin);
    getline(ss,ip,':');
    getline(ss, port);

    //port = Origin;
   // port.erase(0,ip.length()+1);

    if (port == "")
        return "ERROR: PORT NOT SET";

    return port;
}

bool Message::setDestinationIP(std::string DestIP) {
    std::stringstream ss(DestIP);
    std::string num;
    int dotCount = 0;

    //Make sure all characters are valid
    for (int i = 0; i < DestIP.length(); i++)
        if (DestIP[i] == '.')
        {
            dotCount++;
        }
        else if (!std::isdigit(DestIP[i])) return false;

    //Make sure IP has 3 dots
    if (dotCount != 3) return false;

    //Make sure int range is valid
    while (getline(ss,num,'.'))
    {
        std::stringstream convert(num);
        int iNum;
        convert >> iNum;

        if (iNum < 0 || iNum > 255) return false;
    }

    //Make sure IP has not been set
    if (getDestinationIP() != "ERROR: IPV4 NOT SET") return false;

    if (Destination == "")
        this->Destination = DestIP;
    else
        this->Destination = DestIP + Destination;

    return true;
}

bool Message::setDestinationPort(std::string DestPort) {
    std::stringstream convert(DestPort);
    int iNum;

    //Make sure all characters are valid
    for (int i = 0; i < DestPort.length(); i++)
        if (!std::isdigit(DestPort[i])) return false;

    //Make sure int range is valid
    convert >> iNum;
    if (iNum < 0 || iNum > 65535) return false;

    //Make sure port has not been set
    if (getDestinationPort() != "ERROR: PORT NOT SET") return false;

    this->Destination = Destination + ":" + DestPort;

    return true;
}

bool Message::setOriginIP(std::string OriginIP) {
    std::stringstream ss(OriginIP);
    std::string num;
    int dotCount = 0;

    //Make sure all characters are valid
    for (int i = 0; i < OriginIP.length(); i++)
        if (OriginIP[i] == '.')
        {
            dotCount++;
        }
        else if (!std::isdigit(OriginIP[i])) return false;

    //Make sure IP has 3 dots
    if (dotCount != 3) return false;
    //Make sure int range is valid
    while (getline(ss,num,'.'))
    {
        std::stringstream convert(num);
        int iNum;
        convert >> iNum;
        if (iNum < 0 || iNum > 255) return false;
    }

    //Make sure IP is not set
    if (getOriginIP() != "ERROR: IPV4 NOT SET") return false;

    if (Origin == "")
        this->Origin = OriginIP;
    else
        this->Origin = OriginIP + Origin;

    return true;
}

bool Message::setOriginPort(std::string OriginPort) {
    std::stringstream convert(OriginPort);
    int iNum;

    //Make sure all characters are valid
    for (int i = 0; i < OriginPort.length(); i++)
        if (!std::isdigit(OriginPort[i])) return false;

    //Make sure int range is valid
    convert >> iNum;
    if (iNum < 0 || iNum > 65535) return false;

    //Make sure port has not been set
    if (getOriginPort() != "ERROR: PORT NOT SET") return false;

    this->Origin = Origin + ":" + OriginPort;

    return true;
}

void Message::setEncoding(std::string Encoding) {
    this->Encoding = Encoding;
}

void Message::PrintMessage() {
    std::cout << "Data: " << getData() << std::endl;
    std::cout << "Destination: " << getDestination() << std::endl;
    std::cout << "Destination IPV4: " << getDestinationIP() << std::endl;
    std::cout << "Destination Port: " << getDestinationPort() << std::endl;
    std::cout << "Origin: " << getOrigin() << std::endl;
    std::cout << "Origin IPV4: " << getOriginIP() << std::endl;
    std::cout << "Origin Port: " << getOriginPort() << std::endl;
    std::cout << "Encoding: " << getEncoding() << std::endl;
}

Message::~Message() {
    std::cout << "Deleted message containing: " << data << std::endl;
}

int Message::getContentLength() {
    return this->contentLength;
}

void Message::setContentLength(int contentLength) {
    this->contentLength = contentLength;
}
