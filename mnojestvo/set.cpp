#include "head.h"
#include <iostream>

using namespace std;

// Проверка существования элемента
bool Set::exists(int value) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == value) return true;
    }
    return false;
}

// Очистка памяти
void Set::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
}

// Копирование данных
void Set::copyFrom(const Set& other) {
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

// Конструктор по умолчанию
Set::Set() : data(nullptr), size(0) {}

// Конструктор с параметрами
Set::Set(int arr[], int n) : data(nullptr), size(0) {
    for (int i = 0; i < n; i++) {
        add(arr[i]);
    }
}

// Конструктор копирования
Set::Set(const Set& other) : data(nullptr), size(0) {
    copyFrom(other);
}

// Деструктор
Set::~Set() {
    clear();
}

// Проверка принадлежности элемента
bool Set::contains(int value) const {
    return exists(value);
}

// Добавление элемента
Set& Set::add(int value) {
    if (!exists(value)) {
        int* newData = new int[size + 1];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        newData[size] = value;
        delete[] data;
        data = newData;
        size++;
    }
    return *this;
}

Set Set::operator+(int value) const {
    Set result(*this);
    result.add(value);
    return result;
}

Set& Set::operator+=(int value) {
    return add(value);
}

// Объединение множеств
Set& Set::merge(const Set& other) {
    for (int i = 0; i < other.size; i++) {
        add(other.data[i]);
    }
    return *this;
}

Set Set::operator+(const Set& other) const {
    Set result(*this);
    result.merge(other);
    return result;
}

Set& Set::operator+=(const Set& other) {
    return merge(other);
}

// Удаление элемента
Set& Set::remove(int value) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            index = i;
            break;
        }
    }
    
    if (index != -1) {
        int* newData = new int[size - 1];
        for (int i = 0; i < index; i++) {
            newData[i] = data[i];
        }
        for (int i = index + 1; i < size; i++) {
            newData[i - 1] = data[i];
        }
        delete[] data;
        data = newData;
        size--;
    }
    return *this;
}

Set Set::operator-(int value) const {
    Set result(*this);
    result.remove(value);
    return result;
}

Set& Set::operator-=(int value) {
    return remove(value);
}

// Разность множеств
Set& Set::difference(const Set& other) {
    for (int i = size - 1; i >= 0; i--) {
        if (other.contains(data[i])) {
            remove(data[i]);
        }
    }
    return *this;
}

Set Set::operator-(const Set& other) const {
    Set result(*this);
    result.difference(other);
    return result;
}

Set& Set::operator-=(const Set& other) {
    return difference(other);
}

// Пересечение множеств
Set& Set::intersection(const Set& other) {
    Set result;
    for (int i = 0; i < size; i++) {
        if (other.contains(data[i])) {
            result.add(data[i]);
        }
    }
    *this = result;
    return *this;
}

Set Set::operator*(const Set& other) const {
    Set result;
    for (int i = 0; i < size; i++) {
        if (other.contains(data[i])) {
            result.add(data[i]);
        }
    }
    return result;
}

Set& Set::operator*=(const Set& other) {
    return intersection(other);
}

// Присваивание
Set& Set::operator=(const Set& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

// Сравнение множеств
bool Set::operator==(const Set& other) const {
    if (size != other.size) return false;
    
    for (int i = 0; i < size; i++) {
        if (!other.contains(data[i])) return false;
    }
    return true;
}

// Потоковый вывод
ostream& operator<<(ostream& os, const Set& s) {
    os << "{";
    for (int i = 0; i < s.size; i++) {
        os << s.data[i];
        if (i < s.size - 1) os << ", ";
    }
    os << "}";
    return os;
}

// Потоковый ввод
istream& operator>>(istream& is, Set& s) {
    s.clear();  // Очищаем текущее множество
    
    int n;
    cout << "Введите количество элементов: ";
    is >> n;
    
    cout << "Введите " << n << " элементов: ";
    for (int i = 0; i < n; i++) {
        int val;
        is >> val;
        s.add(val);
    }
    
    return is;
}
