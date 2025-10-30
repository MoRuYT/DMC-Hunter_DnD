#pragma once
#include <string>
#include <iostream>

using namespace std;


class DemonBoss
{
protected:
    string name{ "Демон" };
    unsigned int health{ 500 };
    float damage{ 20 };
    unsigned short lvl{ 1 };
    bool isAlive{ true };

public:
    DemonBoss(string n, int h, float d, unsigned short l, bool alive);
    DemonBoss();
    DemonBoss(string n);
    DemonBoss(string n, int h);

    void Roar();
    void GetInfo();
    ~DemonBoss();
};