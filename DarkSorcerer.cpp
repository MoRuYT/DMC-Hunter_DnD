#include "DarkSorcerer.h"
using namespace std;

DarkSorcerer::DarkSorcerer()
{
    cout << "== Класс Призыватель ==" << endl;
    name = "V";
    health = 80;
    damage = 30;
}

DarkSorcerer::DarkSorcerer(string name, unsigned int health, float damage)
{
    this->name = name;
    this->health = health;
    this->damage = damage;
}

void DarkSorcerer::GetInfo() 
{
    DemonHunter::GetInfo();
    cout << "Интеллект: " << intellect << endl;
    cout << "Доступные фамильяры: ";
    for (int i = 0; i < lvl; i++)
    {
        cout << spells[i];
        if (i < lvl - 1) cout << ", ";
    }
    cout << endl;
}

void DarkSorcerer::CastSpell()
{
    cout << name << " призывает " << spells[lvl - 1] << endl;
}

void DarkSorcerer::Create()
{
    cout << "Призыватель демонических фамильяров." << endl;
    cout << "Введите имя персонажа: ";
    cin >> name;
    GetInfo();
    CastSpell();
}

//Перегрузка оператора + для объединения магов
DarkSorcerer DarkSorcerer::operator+(const DarkSorcerer& ds) const
{
    return DarkSorcerer
    (this->name,
        (this->health + ds.health),
        (this->damage + ds.damage)
    );
}

DarkSorcerer::~DarkSorcerer()
{
    cout << name << " растворяется в тени... (Призыватель исчезает)" << endl;
}
