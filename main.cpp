#include <windows.h>
#include "DevilBreaker.h"
#include "DarkSorcerer.h"
#include "SwordMaster.h"
#include "HunterManager.h"
#include "InputValidator.h"
#include "SaveSystem.h"
#include <ctime>
#include "DemonBoss.h"

using namespace std;

/*void TakeDamage(DemonHunter& dh, float damage)
{
    float* tempHealth = new float;//добавить свойство (броня) и ввести его в формулу
    *tempHealth = (float)dh.health - damage;
    if (tempHealth < 0)
    {
        dh.health = 0;
        cout << "Вы погибли!" << endl; //вызвать метод(функцию), который перезагрузит игру
    }
    else
    {
        dh.health = *tempHealth;
    }
    delete tempHealth;
    tempHealth = nullptr;
}*/


int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned int)time(0));

    cout << "DEVIL MAY CRY: HUNTERS" << endl;

    /* Демонстрация перегрузки операторов
    SwordMaster* sm1 = new SwordMaster();
    DarkSorcerer* ds1 = new DarkSorcerer();*/
    //поработать с враги и боссами
    DemonBoss* Boss1 = new DemonBoss("Уризен Сидячий", 500, 40);
    DemonBoss* Boss2 = new DemonBoss("Уризен Ходячий", 750, 55);
    DemonBoss* Boss3 = new DemonBoss("Вергилий", 1000, 70);
    //проработать массив злодеев
    const int ENEMY_COUNT = 10;
    DemonBoss* enemies[ENEMY_COUNT];
    string enemyNames[ENEMY_COUNT] = {
        "Empusa", "Hell Caina", "Antenora", "Fury", "Proto Angelo",
        "Death Scissors", "Nobodies", "Riot", "Behemoth", "Baphomet"
    };
    for (int i = 0; i < ENEMY_COUNT; i++)
    {
        enemies[i] = new DemonBoss(enemyNames[i], 80 + i * 15, 10 + i * 3);
    }
    // Основная игра
    DemonHunter* player = nullptr;
    HunterManager* manager = new HunterManager();
    SaveSystem* saveSystem = new SaveSystem();

    cout << "\nПривет, путник!\nПрисядь у костра и расскажи о себе" << endl;
    cout << "Ты впервые тут?\n\t1 - Новый персонаж\n\t2 - Загрузить\n";
    unsigned short choice = InputValidator::GetChoice(1, 2);
    unsigned short classChoice = 0;

    if (choice == 1)
    {
        cout << "\nРасскажи о своих навыках:\n";
        cout << "\t1 - Мастер Меча (Данте)\n";
        cout << "\t2 - Темный призыватель (V)\n";
        cout << "\t3 - Разрушитель демонов (Неро)\n";

        classChoice = InputValidator::GetChoice(1, 3);

        switch (choice)
        {
        case 1:
            player = new SwordMaster();
            break;
        case 2:
            player = new DarkSorcerer();
            break;
        case 3:
            player = new DevilBreaker();
            break;
        }

        if (player)
        {
            manager->Create(player);
        }
    }
    else
    {
        // Загрузка сохранения
        if (!saveSystem->Load(player))
        {
            cout << "\nСохранение не найдено. Создаем нового персонажа...\n" << endl;

            // Выбор класса после неудачной загрузки
            cout << "\nРасскажи о своих навыках:\n";
            cout << "\t1 - Мастер Меча (Данте)\n";
            cout << "\t2 - Темный призыватель (V)\n";
            cout << "\t3 - Разрушитель демонов (Неро)\n";

            classChoice = InputValidator::GetChoice(1, 3);

            switch (classChoice)
            {
            case 1:
                player = new SwordMaster();
                break;
            case 2:
                player = new DarkSorcerer();
                break;
            case 3:
                player = new DevilBreaker();
                break;
            }

            if (player)
            {
                manager->Create(player);
            }
        }
        else
        {
            // Загрузка успешна
            player->GetInfo();
        }
    }
        }
    }
    /* ??????
    if (!player)
    {
        cout << "Ошибка создания персонажа!" << endl;

        // Очистка памяти
        for (int i = 0; i < ENEMY_COUNT; i++)
            delete enemies[i];
        delete Boss1;
        delete Boss2;
        delete Boss3;
        delete manager;
        delete saveSystem;

        return -1;
    }*/


    //Основной сюжет

    cout << "Появились новые задания, за которые платят немаленькие деньги. Выбирай:";
    cout << "\t1 - Ракун Сити\n";
    cout << "\t2 - Клипот\n";
    cout << "\t3 - Россия\n";

    choice = TestChoice(3, "Ты уверен? Выбери снова: ");

    string location;
    switch (choice)
    {
    case 1:
        location = "Ракун Сити";
        break;
    case 2:
        location = "Клипот";
        break;
    case 3:
        location = "Россия";
        break;
    }

    cout << "ПУТЕШЕСТВИЕ В " << location << endl;
 
      for (int i = 0; i < 10; i++)
    {
        Sleep(500);
        cout << "Вы преодолели " << (i + 1) * 10 << "% пути" << endl;

        // Случайная встреча с врагом (60% шанс)
        if (rand() % 100 > 40)
        {
            int enemyIndex = rand() % ENEMY_COUNT;
            cout << "\nНа вас напал " << enemies[enemyIndex]->GetName() << "!" << endl;
            enemies[enemyIndex]->GetInfo();
            // Охотник получает урон
            player->TakeDamage((float)enemies[enemyIndex]->GetDamage());
            // Проверка смерти
            if (player->GetHealth() == 0)
            {
                cout << "GAME OVER" << endl;
                // Очистка памяти
                for (int j = 0; j < ENEMY_COUNT; j++)
                    delete enemies[j];
                delete Boss1;
                delete Boss2;
                delete Boss3;
                delete player;
                delete manager;
                delete saveSystem;

                return 0;
            }
            cout << endl;
        }
      }
        }
        cout << "Вы добрались до пункта назначения\n";
        // Встреча с боссом
        cout << "ПОЯВИЛСЯ БОСС!" << endl;

        DemonBoss* currentBoss = nullptr;
        switch (choice)
        {
        case 1:
            currentBoss = Boss1;
            break;
        case 2:
            currentBoss = Boss2;
            break;
        case 3:
            currentBoss = Boss3;
            break;
        }

        if (currentBoss)
        {
            currentBoss->GetInfo();
            currentBoss->Roar();

            cout << "\n" << player->GetName() << " вступает в бой с боссом!" << endl;
            player->TakeDamage((float)currentBoss->GetDamage());
        }

    }
    // Сохранение игры
    if (player->GetHealth() > 0)
    {
        cout << "\n\n=== КОНТРОЛЬНАЯ ТОЧКА ===" << endl;
        cout << "Сделаем остановку тут?\n\t1 - Сохранить игру\n\t2 - Продолжить\n";
        choice = InputValidator::GetChoice(1, 2);

        if (choice == 1)
        {
            if (saveSystem->Save(player))
            {
                cout << "\nИгра сохранена! Прогресс " << player->GetName() << " записан." << endl;
            }
            else
            {
                cout << "\nОшибка сохранения!" << endl;
            }
        }
        else
        {
            cout << "\nИгра продолжается! Удачи, охотник!" << endl;
        }
    }

    // Очистка памяти
    for (int i = 0; i < ENEMY_COUNT; i++)
        delete enemies[i];

    delete Boss1;
    delete Boss2;
    delete Boss3;
    delete player;
    delete manager;
    delete saveSystem;

    return 0;
}