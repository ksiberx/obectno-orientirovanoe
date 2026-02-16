#pragma once
#ifndef PERSON_H
#define PERSON_H

#include "Date.h"
#include <iostream>

class Person {
private:
    int id;                 // идентификационный номер
    char* surname;          // фамилия (динамически)
    char* name;             // имя (динамически)
    char* patronymic;       // отчество (динамически)
    Date birthDate;         // дата рождения

    static int count;       // количество созданных объектов

    // Вспомогательная функция копирования строки
    void copyString(char*& dest, const char* src);

public:
    // Конструктор с параметрами
    Person(int id,
        const char* surname,
        const char* name,
        const char* patronymic,
        Date birthDate);

    // Конструктор по умолчанию (делегирование)
    Person();

    // Конструктор копирования
    Person(const Person& other);

    // Деструктор
    ~Person();

    // Статическая функция получения количества объектов
    static int getCount();

    // Сеттеры
    void setSurname(const char* surname);
    void setName(const char* name);
    void setPatronymic(const char* patronymic);

    // Геттеры
    const char* getSurname() const;
    const char* getName() const;
    const char* getPatronymic() const;

    // Вывод информации
    void print() const;
};

#endif
