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
    cout << "Уровень: " << lvl << endl;
}

DemonHunter::~DemonHunter()
{
    
}