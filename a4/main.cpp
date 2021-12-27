#include "Message.h"
#include "Application.h"
#include "Transport.h"

using namespace std;

int main()
{
    Application* stack1 = new Application();
    Application* stack2 = new Application();
    Application* stack3 = new Application();
    Application* stack4 = new Application();
    Application* stack5 = new Application();
    Application* stack6 = new Application();
    Application* stack7 = new Application();
    Application* stack8 = new Application();
    Application* stack9 = new Application();
    Application* stack10 = new Application();
    Application* stack11 = new Application();
    
    config cfg1 = config();
    config cfg2 = config();
    config cfg3 = config();
    config cfg4 = config();
    config cfg5 = config();
    config cfg6 = config();
    config cfg7 = config();
    config cfg8 = config();
    config cfg9 = config();
    config cfg10 = config();
    config cfg11 = config();

    cfg1.computerName = "Computer 1"; // message sent from computer 1 be sent to computer 10
    cfg1.encoding = "UTF-8";
    cfg1.ip = "127.0.0.1";
    cfg1.port = "300";
    cfg1.DestIP = "143.9.7.0";
    cfg1.DestPort = "6347";

    cfg2.computerName = "Computer 2"; // message sent from computer 2 should be sent to computer 5 but turn up with a destPort error
    cfg2.encoding = "UTF-8";
    cfg2.ip = "127.0.0.2";
    cfg2.port = "300";
    cfg2.DestIP = "192.168.0.2"; 
    cfg2.DestPort = "500";

    cfg3.computerName = "Computer 3"; // message sent from computer 3 be sent to computer 1, should turn up with encoding error
    cfg3.encoding = "ASCII";
    cfg3.ip = "192.168.0.1";
    cfg3.port = "400";
    cfg3.DestIP = "127.0.0.1";
    cfg3.DestPort = "300";

    cfg4.computerName = "Computer 4"; // message sent from computer 4 be sent to computer 3
    cfg4.encoding = "ASCII";
    cfg4.ip = "768.0.0.4"; // should result in origin IP error from Message.h
    cfg4.port = "800";
    cfg4.DestIP = "192.168.0.1";
    cfg4.DestPort = "400";

    cfg5.computerName = "Computer 5"; // message sent from computer 5 be sent to computer 8
    cfg5.encoding = "UTF-16";
    cfg5.ip = "192.168.0.2";
    cfg5.port = "555";
    cfg5.DestIP = "78.88.3.0";
    cfg5.DestPort = "675";

    cfg6.computerName = "Computer 6"; // message sent from computer 6 will retun to itself
    cfg6.encoding = "UTF-32";
    cfg6.ip = "142.4.2.4";
    cfg6.port = "200";
    cfg6.DestIP = "224.212.45.01";
    cfg6.DestPort = "909";

    cfg7.computerName = "Computer 7"; // message sent from computer 7 be sent to computer 2
    cfg7.encoding = "UTF-8";
    cfg7.ip = "224.42.255.9";
    cfg7.port = "0";
    cfg7.ip = "143.9.7.0"; // if two stacks have the same IP, the message will be sent to the first stack in the list with that IP
    cfg7.port = "6347";
    cfg7.DestIP = "127.0.0.2";
    cfg7.DestPort = "300";

    cfg8.computerName = "Computer 8"; // message sent from computer 8 to no computer // does it need to print an error message?
    cfg8.encoding = "UTF-16";
    cfg8.ip = "78.88.3.0";
    cfg8.port = "675";
    cfg8.DestIP = "";
    cfg8.DestPort = "";

    cfg9.computerName = "Computer 9"; // message sent from computer 9 be sent to computer 8
    cfg9.encoding = "UTF-16";
    cfg9.ip = "";
    cfg9.port = "";
    cfg9.DestIP = "78.88.3.0";
    cfg9.DestPort = "675";

    cfg10.computerName = "Computer 10"; // message sent from computer 10 be sent to computer 1
    cfg10.encoding = "UTF-8";
    cfg10.ip = "143.9.7.0";
    cfg10.port = "6347";
    cfg10.DestIP = "127.0.0.1";
    cfg10.DestPort = "300";

    cfg11.computerName = "Computer 11"; // message sent from computer 11 be sent to computer 2
    cfg11.encoding = "UTF-8";
    cfg11.ip = "143.9.7.69";
    cfg11.port = "6969";
    cfg11.DestIP = "127.0.0.2";
    cfg11.DestPort = "300";

    stack1->configure(cfg1);
    stack2->configure(cfg2);
    stack3->configure(cfg3);
    stack4->configure(cfg4);
    stack5->configure(cfg5);
    stack6->configure(cfg6);
    stack7->configure(cfg7);
    stack8->configure(cfg8);
    stack9->configure(cfg9);
    stack10->configure(cfg10);
    stack11->configure(cfg11);

    stack1->link(stack2);
    stack2->link(stack3);
    stack3->link(stack4);
    stack4->link(stack5);
    stack5->link(stack6);
    Transport* linkFromTransport = (Transport*) (stack7->getDown()->getDown());
    stack6->link(linkFromTransport);
    stack7->link(stack8);
    stack8->link(stack9);
    stack9->link(stack10);
    stack10->link(stack11);
    

    string message = "Test message, from beginning to end";

    stack1->execute(message, message.length());
    cout << "===========================================\n\n";

    stack9->link(stack10);
    stack1->execute(message, message.length());
    cout << "===========================================\n\n";

    message = "Something something something";
    stack4->execute(message, message.length());
    cout << "\n===========================================\n\n";

//    cfg4.ip = "200.0.0.4";
//    stack4->configure(cfg4);
//    stack4->execute(message, 23); // inducing a content length error
//    cout << "\n===========================================\n\n";

    stack4->execute(message, message.length());
    cout << "\n===========================================\n\n";

    cfg4.encoding = "UTF-8";
    stack4->configure(cfg4);
    stack4->execute(message, message.length());
    cout << "\n===========================================\n\n";
    
    cfg4.encoding = "ASCII";
    stack4->configure(cfg4);
    stack4->execute(message, message.length());
    cout << "\n===========================================\n\n";

    message = "Empty IP and port";
    stack9->execute(message, message.length());
    cout << "\n===========================================\n\n";

    message = "Empty DestIP and DestPort";
    stack8->execute(message, message.length());
    cout << "\n===========================================\n\n";

    message = "OriginPort is 0";
    stack7->execute(message, message.length());
    cout << "\n===========================================\n\n";

    message = "Loop da Loop";
    stack6->execute(message, message.length());
    cout << "\n===========================================\n\n";

    message = "DestPort error";
    stack2->execute(message, message.length());
    cout << "\n===========================================\n\n";

    message = "But if transport?";
    stack11->execute(message, message.length());
    cout << "\n===========================================\n\n";

    delete stack1;
    delete stack2;
    delete stack3;
    delete stack4;
    delete stack5;
    delete stack6;
    delete stack7;
    delete stack8;
    delete stack9;
    delete stack10;
}

/*

Message at Physical layer of computer: Computer 2
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 3
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 4
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 5
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 6
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 7
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 8
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 9
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 1
Message at Datalink layer
Message has been returned to sender without finding the destination
Data: Test message, from beginning to end
Destination: 143.9.7.0:6347
Destination IPV4: 143.9.7.0
Destination Port: 6347
Origin: 127.0.0.1:300
Origin IPV4: 127.0.0.1
Origin Port: 300
Encoding: UTF-8
===========================================

Message at Physical layer of computer: Computer 2
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 3
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 4
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 5
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 6
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 7
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 8
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 9
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 10
Message at Datalink layer
Message at Network layer
Message at Transport layer
Message at Presentation layer on computer: Computer 10
Computer Computer 10 Received message:  Test message, from beginning to end
===========================================

ERROR OCCURED WITH ORIGIN IP

===========================================

Message at Physical layer of computer: Computer 5
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 6
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 7
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 8
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 9
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 10
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 1
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 2
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 3
Message at Datalink layer
Message at Network layer
Content Length error
Data: Something something something
Destination: 192.168.0.1:400
Destination IPV4: 192.168.0.1
Destination Port: 400
Origin: 200.0.0.4:800
Origin IPV4: 200.0.0.4
Origin Port: 800
Encoding: ASCII

===========================================

Message at Physical layer of computer: Computer 5
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 6
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 7
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 8
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 9
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 10
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 1
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 2
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 3
Message at Datalink layer
Message at Network layer
Message at Transport layer
Message at Presentation layer on computer: Computer 3
Computer Computer 3 Received message:  Something something something

===========================================

Message at Physical layer of computer: Computer 5
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 6
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 7
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 8
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 9
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 10
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 1
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 2
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 3
Message at Datalink layer
Message at Network layer
Message at Transport layer
Encoding type mismatch on computer: Computer 3 Expected: ASCII
Data: Something something something
Destination: 192.168.0.1:400
Destination IPV4: 192.168.0.1
Destination Port: 400
Origin: 200.0.0.4:800
Origin IPV4: 200.0.0.4
Origin Port: 800
Encoding: UTF-8

===========================================

Message at Physical layer of computer: Computer 5
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 6
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 7
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 8
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 9
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 10
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 1
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 2
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 3
Message at Datalink layer
Message at Network layer
Message at Transport layer
Message at Presentation layer on computer: Computer 3
Computer Computer 3 Received message:  Something something something

===========================================

ERROR OCCURED WITH ORIGIN PORT

===========================================

ERROR OCCURED WITH DESTINATION PORT

===========================================

Message at Physical layer of computer: Computer 8
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 9
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 10
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 1
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 2
Message at Datalink layer
Message at Network layer
Message at Transport layer
Message at Presentation layer on computer: Computer 2
Computer Computer 2 Received message:  OriginPort is 0

===========================================

Message at Physical layer of computer: Computer 7
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 8
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 9
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 10
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 1
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 2
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 3
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 4
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 5
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 6
Message at Datalink layer
Message has been returned to sender without finding the destination
Data: Loop da Loop
Destination: 224.212.45.01:909
Destination IPV4: 224.212.45.01
Destination Port: 909
Origin: 142.4.2.4:200
Origin IPV4: 142.4.2.4
Origin Port: 200
Encoding: UTF-32

===========================================

Message at Physical layer of computer: Computer 3
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 4
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Computer 5
Message at Datalink layer
Message at Network layer
Message sent to wrong port
Data: DestPort error
Destination: 192.168.0.2:500
Destination IPV4: 192.168.0.2
Destination Port: 500
Origin: 127.0.0.2:300
Origin IPV4: 127.0.0.2
Origin Port: 300
Encoding: UTF-8

===========================================

*/