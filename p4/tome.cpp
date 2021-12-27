//
// Created by Keelan Matthews on 9/28/2021.
//

#include "tome.h"
#include <iostream>
tome::tome(string name, string author)
{
    this->tomeName = name;
    this->author = author;
    this->currSpells = 0;

    for (int i = 0; i < 10; i++)
        this->references[i] = "";
}

tome::tome(string name, int tomeSize, string author, string *initialList)
{
    this->tomeName = name;
    this->author = author;
    this->currSpells = tomeSize;

    for (int i = 0; i < 10; i++)
        this->references[i] = "";

    for (int i = 0; i < this->currSpells; i++)
        this->references[i] = initialList[i];
}

tome::~tome(){}

int tome::getTomeSize() const
{
    return this->currSpells;
}

string tome::getSpell(int i) const
{
    return this->references[i];
}

string tome::getName() const
{
    return this->tomeName;
}

string tome::getAuthor() const
{
    return this->author;
}

tome tome::operator+(const string &add)
{
    if (currSpells != 10)
        for (int i = 0; i < 10; i++)
            if (this->references[i] == "")
            {
                this->references[i] = add;
                this->currSpells++;
                return *this;
            }

    return *this;
}

tome tome::operator-(const string &sub)
{
    for (int i = 0; i < 10; i++)
        if (this->references[i] == sub)
        {
            this->references[i] = "";
            this->currSpells--;
            return *this;
        }

    return *this;
}

bool tome::operator<(const tome &t)
{
    if (this->currSpells < t.currSpells)
        return true;

    return false;
}

bool tome::operator>(const tome &t)
{
    if (this->currSpells > t.currSpells)
        return true;

    return false;
}

ostream& operator<<(ostream& output, const tome& t)
{
    string reference = "";

    for (int i = 0; i < 10; i++)
        if (t.references[i] != "")
            if (i == 0)
                reference = t.references[i];
            else
                reference = reference + ", " + t.references[i];

    output << "Tome Name: " << t.tomeName << "\n";
    output << "Author: " << t.author << "\n";
    output << "References: " << reference << "\n";

    return output;
}

tome &tome::operator=(const tome &oldTome)
{
    for (int i = 0; i < 10; i++)
        this->references[i] = oldTome.references[i];

    this->tomeName = oldTome.tomeName;
    this->author = oldTome.author;
    this->currSpells = oldTome.currSpells;

    return *this;
}

bool tome::operator==(const tome &t)
{
    if (this->currSpells != t.currSpells)
        return false;

    //Sort both sets of arrays first
    string arr1[10];
    string arr2[10];
    string temp = "";

    //Assign old arrays to sorted array variables
    for (int i = 0; i < 10; i++)
    {
        arr1[i] = this->references[i];
        arr2[i] = t.references[i];
    }

    //Sort this array
    for (int i = 0; i < 10-1; i++)
        for (int j = i+1; j < 10; j++)
            if (arr1[i] > arr1[j])
            {
                temp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = temp;
            }

    //Sort array being passed into function
    for (int i = 0; i < 10-1; i++)
        for (int j = i+1; j < 10; j++)
            if (arr2[i] > arr2[j])
            {
                temp = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp;
            }

    bool equal = true;
    for (int i = 0; i < currSpells; i++)
        if (arr1[i] != arr2[i])
            equal = false;

    return equal;
}