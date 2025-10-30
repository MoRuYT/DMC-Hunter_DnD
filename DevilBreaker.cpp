#include "DevilBreaker.h"
using namespace std;

DevilBreaker::DevilBreaker()
{
    cout << "== Класс Разрушитель демонов ==" << endl;
    name = "Неро";
    damage = 35;
    health = 120;
    strength = 30;
}

void DevilBreaker::GetInfo() 
{
    SwordMaster::GetInfo();
    cout << "Интеллект: " << intellect << endl;
    cout << "Доступные способности: ";
    for (int i = 0; i < lvl; i++)
    {
        cout << spells[i];
        if (i < lvl - 1) cout << ", ";
    }
    cout << endl;
}

void DevilBreaker::Create()
{
    cout << "\n=== Разрушитель демонов ===" << endl;
    cout << "Мечник с демонической рукой." << endl;
    cout << "Введите имя персонажа: ";
    cin >> name;
    GetInfo();
    CastSpell();
    GetWeapons();
}

DevilBreaker::~DevilBreaker()
{
    cout << name << " - Больше никакого мертвого груза! (Разрушитель демонов покончил с нечистью) " << endl;
}
    