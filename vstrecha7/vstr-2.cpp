#include <iostream>
#include <cstring>
using namespace std;

class Airplane {
private:
    char* type;        // Тип самолета
    int maxPassengers; // Максимальное количество пассажиров
    int currentPassengers; // Текущее количество пассажиров
    
public:
    // Конструктор
    Airplane(const char* t, int maxP, int currP = 0) 
        : maxPassengers(maxP), currentPassengers(currP) {
        type = new char[strlen(t) + 1];
        strcpy(type, t);
    }
    
    // Конструктор копирования
    Airplane(const Airplane& other) 
        : maxPassengers(other.maxPassengers), 
          currentPassengers(other.currentPassengers) {
        type = new char[strlen(other.type) + 1];
        strcpy(type, other.type);
    }
    
    // Деструктор
    ~Airplane() {
        delete[] type;
    }
    
    // Оператор присваивания
    Airplane& operator=(const Airplane& other) {
        if (this != &other) {
            delete[] type;
            type = new char[strlen(other.type) + 1];
            strcpy(type, other.type);
            maxPassengers = other.maxPassengers;
            currentPassengers = other.currentPassengers;
        }
        return *this;
    }
    
    // Оператор == - проверка на равенство типов
    bool operator==(const Airplane& other) const {
        return strcmp(type, other.type) == 0;
    }
    
    // Оператор > - сравнение по максимальному количеству пассажиров
    bool operator>(const Airplane& other) const {
        return maxPassengers > other.maxPassengers;
    }
    
    // Префиксный ++ - увеличение пассажиров
    Airplane& operator++() {
        if (currentPassengers < maxPassengers) {
            currentPassengers++;
        }
        return *this;
    }
    
    // Префиксный -- - уменьшение пассажиров
    Airplane& operator--() {
        if (currentPassengers > 0) {
            currentPassengers--;
        }
        return *this;
    }
    
    // Постфиксный ++ (для полноты - добавим)
    Airplane operator++(int) {
        Airplane temp = *this;
        ++(*this);
        return temp;
    }
    
    // Постфиксный --
    Airplane operator--(int) {
        Airplane temp = *this;
        --(*this);
        return temp;
    }
    
    // Метод для вывода информации
    void print() const {
        cout << "Самолет типа \"" << type << "\"" << endl;
        cout << "  Макс. пассажиров: " << maxPassengers << endl;
        cout << "  Текущих пассажиров: " << currentPassengers << endl;
    }
    
    // Дружественная функция для вывода
    friend ostream& operator<<(ostream& os, const Airplane& a) {
        os << "Самолет \"" << a.type << "\" (" 
           << a.currentPassengers << "/" << a.maxPassengers << ")";
        return os;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    cout << "Создаем самолеты" << endl;
    Airplane boeing("Boeing 737", 180, 120);
    Airplane airbus("Airbus A320", 200, 150);
    Airplane boeing2("Boeing 737", 180, 50);
    
    cout << "boeing: " << boeing << endl;
    cout << "airbus: " << airbus << endl;
    cout << "boeing2: " << boeing2 << endl << endl;
    
    // Проверка на равенство типов
    cout << "Проверка типов" << endl;
    cout << "boeing == boeing2: " << (boeing == boeing2 ? "Да" : "Нет") << endl;
    cout << "boeing == airbus: " << (boeing == airbus ? "Да" : "Нет") << endl << endl;
    
    // Сравнение по максимальному количеству пассажиров
    cout << "Сравнение по вместимости" << endl;
    cout << "boeing > airbus: " << (boeing > airbus ? "Да" : "Нет") << endl;
    cout << "airbus > boeing: " << (airbus > boeing ? "Да" : "Нет") << endl << endl;
    
    // Изменение количества пассажиров
    cout << "Изменяем количество пассажиров" << endl;
    cout << "До: " << boeing << endl;
    
    ++boeing; ++boeing; ++boeing; // Три раза увеличиваем
    cout << "После трех ++: " << boeing << endl;
    
    --boeing;
    cout << "После одного --: " << boeing << endl;
    
    // Демонстрация постфиксного оператора
    cout << "\n Постфиксный оператор " << endl;
    cout << "До: " << airbus << endl;
    Airplane temp = airbus++;
    cout << "После airbus++ (значение temp): " << temp << endl;
    cout << "После airbus++ (сам airbus): " << airbus << endl;
    
    return 0;
}
