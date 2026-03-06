#ifndef SET_H
#define SET_H

#include <iostream>

class Set {
private:
    int* data;      // Указатель на динамический массив
    int size;       // Текущее количество элементов

public:
    // Конструкторы
    Set();                                      // По умолчанию (пустое множество)
    Set(int arr[], int n);                      // С параметрами (из массива)
    Set(const Set& other);                      // Копирования
    
    // Деструктор
    ~Set();

    // Проверка принадлежности элемента
    bool contains(int value) const;

    // Добавление элемента
    Set& add(int value);
    Set operator+(int value) const;
    Set& operator+=(int value);

    // Объединение множеств
    Set& merge(const Set& other);
    Set operator+(const Set& other) const;
    Set& operator+=(const Set& other);

    // Удаление элемента
    Set& remove(int value);
    Set operator-(int value) const;
    Set& operator-=(int value);

    // Разность множеств
    Set& difference(const Set& other);
    Set operator-(const Set& other) const;
    Set& operator-=(const Set& other);

    // Пересечение множеств
    Set& intersection(const Set& other);
    Set operator*(const Set& other) const;
    Set& operator*=(const Set& other);

    // Присваивание
    Set& operator=(const Set& other);

    // Сравнение
    bool operator==(const Set& other) const;

    // Потоковый ввод/вывод
    friend std::ostream& operator<<(std::ostream& os, const Set& s);
    friend std::istream& operator>>(std::istream& is, Set& s);

private:
    // Вспомогательные методы
    bool exists(int value) const;               // Проверка наличия элемента
    void copyFrom(const Set& other);            // Копирование данных
    void clear();                                // Очистка памяти
};

#endif
