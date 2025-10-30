#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class DemonHunter
{
public:
    string name{ "Охотник на демонов" };
    unsigned int health{ 100 };
    float damage{ 15 };
    unsigned short lvl{ 1 };

public:
    DemonHunter();
    virtual void GetInfo();
    virtual void Create() = 0;
    virtual ~DemonHunter();
};
