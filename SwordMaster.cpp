#include "SwordMaster.h"
using namespace std;

SwordMaster::SwordMaster() 
{
    cout << "== Класс Мастер Меча ==" << endl;
    name = "Данте";
    health = 150;
    damage = 25;
}

SwordMaster::SwordMaster(string name, unsigned int health, float damage)
{
    cout << "Мастер Меча явился!" << endl;
    this->name = name;
    this->health = health;
    this->damage = damage;
}

void SwordMaster::GetWeapons()
{
    cout << name << " взял в руки " << weapons[lvl - 1] << endl;
}

void SwordMaster::GetInfo() 
{
    DemonHunter::GetInfo();
    cout << "Сила:  " << strength << endl;
    cout << "Оружие: ";
    for (int i = 0; i < lvl; i++)
    {
        cout << weapons[i];
        if (i < lvl - 1) cout << ", ";
    }
    cout << endl;
}

void SwordMaster::Create()
{
    cout << "\n=== Мастер Меча ===" << endl;
    cout << "Мастера ближнего боя вошел в агенство!" << endl;
    cout << "Введите имя охотника\t";
    cin >> name;
    GetInfo();
    GetWeapons();
}

// Перегрузка оператора сравнения
bool SwordMaster::operator==(const SwordMaster& sm) const
{
    return ((sm.damage == this->damage) &&
        (sm.health == this->health) &&
        (sm.strength == this->strength));
}

SwordMaster::~SwordMaster()
{
    cout << name << " - Jackpot! (Мастер меча покинул место)" << endl;
}
