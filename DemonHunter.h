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
    float armor{ 0 };

    //геттеры
public:
    string GetName() const;
    unsigned int GetHealth() const;
    float GetDamage() const;
    unsigned short GetLvl() const;
    float GetArmor() const;

    //методы
    virtual void GetInfo();
    virtual void Create() = 0;
    void TakeDamage(float damageAmount);
    virtual ~DemonHunter();
   

    // Дружественная функция (глобальная версия для совместимости)
    friend void ApplyDamage(DemonHunter& hunter, float damage);
};

// Глобальная дружественная функция (объявление вне класса)
void ApplyDamage(DemonHunter& hunter, float damage);