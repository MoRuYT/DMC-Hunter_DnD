#include <windows.h>
#include "DevilBreaker.h"
#include "DarkSorcerer.h"
#include "SwordMaster.h"
#include "HunterManager.h"
#include "InputValidator.h"
#include "SaveSystem.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "DEVIL MAY CRY: HUNTERS" << endl;

    // Демонстрация перегрузки операторов
    SwordMaster* sm1 = new SwordMaster();
    SwordMaster* sm2 = new SwordMaster();
    cout << "Сравнение охотников (==): " << (*sm1 == *sm2) << "\n" << endl;

    DarkSorcerer* ds1 = new DarkSorcerer();
    DarkSorcerer* ds2 = new DarkSorcerer();
    DarkSorcerer* megads = new DarkSorcerer();

    *megads = *ds1 + *ds2;
    cout << "Слияние магов (+):" << endl;
    megads->GetInfo();

    delete sm1;
    delete sm2;
    delete ds1;
    delete ds2;
    delete megads;

    // Основная игра
    DevilBreaker* hunter = new DevilBreaker();
    HunterManager* manager = new HunterManager();
    SaveSystem* saveSystem = new SaveSystem();

    cout << "\nПривет, путник!\nПрисядь у костра и расскажи о себе" << endl;
    cout << "Ты впервые тут?\n\t1 - Новый персонаж\n\t2 - Загрузить\n";
    unsigned short choice = InputValidator::GetChoice(1, 2);

    if (choice == 1)
    {
        cout << "\nРасскажи о своих навыках:\n";
        cout << "\t1 - Sword Master (Данте)\n";
        cout << "\t2 - Dark Sorcerer (V)\n";
        cout << "\t3 - Devil Breaker (Неро)\n";

        choice = InputValidator::GetChoice(1, 3);

        DemonHunter* selected = nullptr;

        switch (choice)
        {
        case 1:
            selected = new SwordMaster();
            break;
        case 2:
            selected = new DarkSorcerer();
            break;
        case 3:
            selected = hunter;
            break;
        }

        if (selected)
        {
            manager->Create(selected);
            if (choice != 3) delete selected;
        }
    }
    else
    {
        if (!saveSystem->Load(hunter))
        {
            cout << "\nСоздаем нового персонажа...\n" << endl;
            manager->Create(hunter);
        }
        else
        {
            hunter->GetInfo();
        }
    }

    cout << "\nСделаем остановку тут?\n\t1 - Сохранить игру\n\t2 - Продолжить\n";
    choice = InputValidator::GetChoice(1, 2);

    if (choice == 1)
    {
        hunter->damage = 99;
        hunter->health = 99;
        hunter->lvl = 99;
        saveSystem->Save(hunter);
    }

    delete hunter;
    delete manager;
    delete saveSystem;

    return 0;
}