#pragma once
#include "DemonHunter.h"

class HunterManager
{
public:
    void Create(DemonHunter* hunter)
    {
        hunter->Create();
    }
};