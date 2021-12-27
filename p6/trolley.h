//
// Created by Keelan Matthews on 10/18/2021.
//

#ifndef P6_TROLLEY_H
#define P6_TROLLEY_H

#include <string>
using namespace std;
class trolley {
private:
    int speed;
    string name;
public:
    trolley();
    ~trolley();
    trolley(string name);
    int getSpeed();
    void increaseSpeed(int s);
};


#endif //P6_TROLLEY_H
