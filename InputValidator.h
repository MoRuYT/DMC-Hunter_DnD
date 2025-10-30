#pragma once
#include <iostream>

class InputValidator
{
public:
    static unsigned short GetChoice(unsigned short min, unsigned short max)
    {
        unsigned short choice;
        std::cin >> choice;

        while (choice > max || choice < min)
        {
            std::cout << "Наверное ты ошибся, повтори снова: ";
            std::cin >> choice;
        }

        return choice;
    }
};