//
// Created by Keelan Matthews on 9/28/2021.
//

#ifndef P4_TOME_H
#define P4_TOME_H
#include <string>
using namespace std;

class tome;
ostream& operator<<(ostream& output, const tome& t);

class tome
{
private:
    string references[10];
    string tomeName;
    string author;
    int currSpells;
public:
    tome(string name, string author);
    tome(string name, int tomeSize, string author, string* initialList);
    ~tome();
    int getTomeSize() const;
    string getSpell(int i) const;
    string getName() const;
    string getAuthor() const;

    friend ostream& operator<<(ostream& output, const tome& t);
    tome operator+(const string& add);
    tome operator-(const string& sub);
    tome& operator=(const tome& oldTome);
    bool operator>(const tome& t);
    bool operator<(const tome& t);
    bool operator==(const tome& t);
};
#endif //P4_TOME_H
