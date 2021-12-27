#ifndef A4_MESSAGE_H
#define A4_MESSAGE_H
#include <string>
#include <iostream>

class Message {
private:
    std::string data;
    std::string Destination;
    std::string Origin;
    std::string Encoding;
    int contentLength;
public:
    Message(std::string Messagedata);
    Message(Message* msg);
    std::string getData();
    std::string getDestination();
    std::string getOrigin();
    std::string getEncoding();
    std::string getDestinationIP();
    std::string getDestinationPort();
    std::string getOriginIP();
    std::string getOriginPort();
    bool setDestinationIP(std::string DestIP);
    bool setDestinationPort(std::string DestPort);
    bool setOriginIP(std::string OriginIP);
    bool setOriginPort(std::string OriginPort);
    void setEncoding(std::string Encoding);
    void PrintMessage();
    ~Message();
    int getContentLength();
    void setContentLength(int contentLength);
};


#endif
