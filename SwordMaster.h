#pragma once
#include "DemonHunter.h"

using namespace std;

class SwordMaster : virtual public DemonHunter
{
protected:
    unsigned short strength{ 35 };
    string weapons[4] = { "Мятежник", "Аластор", "Ямато", "Спарда" };

public:
    SwordMaster();
    SwordMaster(string name, unsigned int health, float damage);
    void GetWeapons();
    void GetInfo() override;
    void Create() override;

    //Перегрузка оператора ==
    bool operator==(const SwordMaster& sm) const;

    ~SwordMaster();
};