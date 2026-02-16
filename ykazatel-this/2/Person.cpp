#include "Person.h"
#include <cstring>
using namespace std;

// Инициализация статического поля
int Person::count = 0;

// Функция копирования строки в динамическую память
void Person::copyString(char*& dest, const char* src) {
    dest = new char[strlen(src) + 1];
    strcpy(dest, src);
}

// Конструктор с параметрами (список инициализации)
Person::Person(int id,
    const char* surname,
    const char* name,
    const char* patronymic,
    Date birthDate)
    : id(id), birthDate(birthDate)
{
    copyString(this->surname, surname);
    copyString(this->name, name);
    copyString(this->patronymic, patronymic);

    count++; // увеличиваем счётчик объектов
}

// Делегирующий конструктор по умолчанию
Person::Person()
    : Person(0, "Неизвестно", "Неизвестно", "Неизвестно", Date())
{
}

// Конструктор копирования (глубокое копирование!)
Person::Person(const Person& other)
    : id(other.id), birthDate(other.birthDate)
{
    copyString(surname, other.surname);
    copyString(name, other.name);
    copyString(patronymic, other.patronymic);

    count++;
}

// Деструктор (освобождаем память)
Person::~Person() {
    delete[] surname;
    delete[] name;
    delete[] patronymic;

    count--; // уменьшаем счётчик
}

// Статическая функция получения количества объектов
int Person::getCount() {
    return count;
}

// Сеттеры (перевыделяем память)
void Person::setSurname(const char* surname) {
    delete[] this->surname;
    copyString(this->surname, surname);
}

void Person::setName(const char* name) {
    delete[] this->name;
    copyString(this->name, name);
}

void Person::setPatronymic(const char* patronymic) {
    delete[] this->patronymic;
    copyString(this->patronymic, patronymic);
}

// Геттеры
const char* Person::getSurname() const { return surname; }
const char* Person::getName() const { return name; }
const char* Person::getPatronymic() const { return patronymic; }

// Вывод информации о человеке
void Person::print() const {
    cout << "\nID: " << id << endl;
    cout << "ФИО: "
        << surname << " "
        << name << " "
        << patronymic << endl;

    cout << "Дата рождения: ";
    birthDate.print();
    cout << endl;
}
