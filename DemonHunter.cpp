#include "DemonHunter.h"
using namespace std;

DemonHunter::DemonHunter()
{
    
}

void DemonHunter::GetInfo() 
{
    cout << "=== Профиль охотника ===" << endl;
    cout << "Имя: " << name << endl;
    cout << "Здоровье:  " << health << " HP" << endl;
    cout << "Урон:  " << damage << endl;
    cout << "Броня: " << armor << endl;
    cout << "Уровень: " << lvl << endl;
}

void DemonHunter::TakeDamage(float damageAmount)
{
    float* tempHealth = new float;//добавить свойство (броня) и ввести его в формулу
    float reducedDamage = damageAmount * (1.0f - armor / 100.0f);

    *tempHealth = (float)health - reducedDamage;
    
    if (*tempHealth < 0)
    {
        health = 0;
        cout << "Вы погибли!" << endl; //вызвать метод(функцию), который перезагрузит игру
    }
    else
    {
        health = (unsigned int)*tempHealth;
        cout << name << " получил " << reducedDamage << " урона! Осталось HP: " << health << endl;
    }
    delete tempHealth;
    tempHealth = nullptr;
}
// ================ ГЕТТЕРЫ ================

string DemonHunter::GetName() const
{
    return name;
}

unsigned int DemonHunter::GetHealth() const
{
    return health;
}

float DemonHunter::GetDamage() const
{
    return damage;
}

unsigned short DemonHunter::GetLvl() const
{
    return lvl;
}

float DemonHunter::GetArmor() const
{
    return armor;
}

// ================ ДРУЖЕСТВЕННАЯ ФУНКЦИЯ ================

// Глобальная функция с доступом к приватным полям через friend
void ApplyDamage(DemonHunter& hunter, float damage)
{
    // Прямой доступ к полям без геттеров (благодаря friend)
    float reducedDamage = damage * (1.0f - hunter.armor / 100.0f);

    if (hunter.health > reducedDamage)
        hunter.health -= (unsigned int)reducedDamage;
    else
        hunter.health = 0;

    cout << hunter.name << " получил " << reducedDamage << " урона (через friend функцию)!" << endl;
    cout << "Осталось HP: " << hunter.health << endl;
}

DemonHunter::~DemonHunter()
{
    
}