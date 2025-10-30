#pragma once
#include "DemonHunter.h"

using namespace std;

class DarkSorcerer : virtual public DemonHunter
{
protected:
    unsigned short intellect = 40;
    string spells[4] = { "Тень", "Гриффон", "Кошмар", "Фантом" };

public:
    DarkSorcerer();
    DarkSorcerer(string name, unsigned int health, float damage);
    void GetInfo() override;
    void CastSpell();
    void Create() override;

    //Перегрузка оператора + для слияния магов
    DarkSorcerer operator+(const DarkSorcerer& ds) const;

    ~DarkSorcerer();
};