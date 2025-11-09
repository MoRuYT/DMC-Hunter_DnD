#pragma once
#include <fstream>
#include <iostream>

class SaveSystem
{
private:
    const std::string saveFile = "dmc_save.bin";

public:
    bool Save(DemonHunter* hunter)
    {
        std::ofstream file(saveFile, std::ios::binary);

        if (!file.is_open())
        {
            std::cout << "Ошибка сохранения!\nПортал в Devil May Cry недоступен." << std::endl;
            return false;
        }

        size_t nameLen = hunter->name.length();
        file.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen));
        file.write(hunter->name.c_str(), nameLen);
        file.write(reinterpret_cast<const char*>(&(hunter->health)), sizeof(hunter->health));
        file.write(reinterpret_cast<const char*>(&(hunter->damage)), sizeof(hunter->damage));
        file.write(reinterpret_cast<const char*>(&(hunter->lvl)), sizeof(hunter->lvl));

        file.close();
        std::cout << "Игра сохранена!" << std::endl;
        return true;
    }

    bool Load(DemonHunter* hunter)
    {
        std::ifstream file(saveFile, std::ios::binary);

        if (!file.is_open())
        {
            std::cout << "Ошибка загрузки!\nПортал в Devil May Cry недоступен." << std::endl;
            return false;
        }

        size_t nameLen;
        file.read(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));

        char* buffer = new char[nameLen + 1];
        file.read(buffer, nameLen);
        buffer[nameLen] = '\0';
        hunter->name = buffer;
        delete[] buffer;

        file.read(reinterpret_cast<char*>(&(hunter->health)), sizeof(hunter->health));
        file.read(reinterpret_cast<char*>(&(hunter->damage)), sizeof(hunter->damage));
        file.read(reinterpret_cast<char*>(&(hunter->lvl)), sizeof(hunter->lvl));

        file.close();
        std::cout << "Сохранение загружено! Добро пожаловать, " << hunter->name << "!" << std::endl;
        return true;
    }
};