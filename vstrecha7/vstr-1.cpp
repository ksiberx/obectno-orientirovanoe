#include <iostream>
using namespace std;

class Circle {
private:
    double radius;
    const double PI = 3.14159;
    
public:
    // Конструктор
    Circle(double r = 0) : radius(r) {}
    
    // Геттер для радиуса
    double getRadius() const { return radius; }
    
    // Вычисление длины окружности
    double getLength() const { return 2 * PI * radius; }
    
    // Оператор == - проверка на равенство радиусов
    bool operator==(const Circle& other) const {
        return radius == other.radius;
    }
    
    // Оператор > - сравнение длин окружностей
    bool operator>(const Circle& other) const {
        return getLength() > other.getLength();
    }
    
    // Оператор += - пропорциональное увеличение радиуса
    Circle& operator+=(double value) {
        radius += value;
        return *this;
    }
    
    // Оператор -= - пропорциональное уменьшение радиуса
    Circle& operator-=(double value) {
        radius -= value;
        if (radius < 0) radius = 0; // Радиус не может быть отрицательным
        return *this;
    }
    
    // Дружественная функция для вывода
    friend ostream& operator<<(ostream& os, const Circle& c) {
        os << "Окружность с радиусом " << c.radius 
           << ", длина = " << c.getLength();
        return os;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    // Создаем окружности
    Circle c1(5);
    Circle c2(5);
    Circle c3(7);
    
    cout << "=== Созданные окружности ===" << endl;
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c3: " << c3 << endl << endl;
    
    // Проверка на равенство радиусов
    cout << "c1 == c2: " << (c1 == c2 ? "Да" : "Нет") << endl;
    cout << "c1 == c3: " << (c1 == c3 ? "Да" : "Нет") << endl << endl;
    
    // Сравнение длин
    cout << "c1 > c3: " << (c1 > c3 ? "Да" : "Нет") << endl;
    cout << "c3 > c1: " << (c3 > c1 ? "Да" : "Нет") << endl << endl;
    
    // Изменение радиуса
    cout << "=== Изменяем радиус c1 ===" << endl;
    cout << "Было: " << c1 << endl;
    c1 += 2;
    cout << "После c1 += 2: " << c1 << endl;
    c1 -= 4;
    cout << "После c1 -= 4: " << c1 << endl;
    
    return 0;
}
