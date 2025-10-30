#include "DemonBoss.h"
using namespace std;

DemonBoss::DemonBoss(string n, int h, float d, unsigned short l, bool alive)
    :name(n), health(h), damage(d), lvl(l), isAlive(alive)
{
    cout << "Демон-босс " << name << " появился из портала Ада!";
}

DemonBoss::DemonBoss() : DemonBoss("Уризен", 1000, 50, 5, true) {}

DemonBoss::DemonBoss(string n) : DemonBoss(n, 500, 20, 1, true) {}

DemonBoss::DemonBoss(string n, int h) : DemonBoss(n, h, 20, 1, true) {}

void DemonBoss::Roar()
{
    cout << name << " издает ужасающий рев!" << endl;
    cout << "Уровень угрозы: " << lvl << " lvl" << endl;
}

void DemonBoss::GetInfo()
{
    cout << "\n=== Босс Демонов ===" << endl;
    cout << "Имя: " << name << endl;
    cout << "HP: " << health << endl;
    cout << "Урон: " << damage << endl;
    cout << "Уровень: " << lvl << endl;
}

DemonBoss::~DemonBoss()
{
    cout << "Демон " << name << " повержен! Миссия Выполнена!" << endl;
}
