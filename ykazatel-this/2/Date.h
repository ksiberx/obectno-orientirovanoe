#pragma once
#ifndef DATE_H
#define DATE_H

#include <iostream>

// Класс Дата (день, месяц, год)
class Date {
private:
    int day;
    int month;
    int year;

public:
    // Конструктор с параметрами
    Date(int d = 1, int m = 1, int y = 2000)
        : day(d), month(m), year(y) {
    }

    // Вывод даты
    void print() const {
        std::cout << day << "." << month << "." << year;
    }
};

#endif
