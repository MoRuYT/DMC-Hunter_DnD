#pragma once
#include "SwordMaster.h"
#include "DarkSorcerer.h"

using namespace std;

class DevilBreaker : public SwordMaster, public DarkSorcerer
{
public:
    DevilBreaker();
    void GetInfo() override;
    void Create() override;
    ~DevilBreaker();
};