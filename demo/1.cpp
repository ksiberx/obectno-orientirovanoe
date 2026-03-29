#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x, y;
    static int pointCount;

public:
    // Конструкторы
    Point() : x(0), y(0) { pointCount++; }
    Point(double x_coord, double y_coord) : x(x_coord), y(y_coord) { pointCount++; }
    Point(const Point& other) : x(other.x), y(other.y) { pointCount++; }

    // Геттеры
    double getX() const { return x; }
    double getY() const { return y; }
    
    // Расстояние от начала координат
    double distance() const { return sqrt(x*x + y*y); }
    
    // Статический метод
    static int getPointCount() { return pointCount; }
    
    // Операторы сравнения
    bool operator==(const Point& other) const { return (x == other.x && y == other.y); }
    bool operator!=(const Point& other) const { return !(*this == other); }
    
    // Ввод/вывод
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << "; " << p.y << ")";
        return os;
    }
    
    friend istream& operator>>(istream& is, Point& p) {
        char ch1, ch2, ch3;
        is >> ch1 >> p.x >> ch2 >> p.y >> ch3;
        return is;
    }
};

// Инициализация статического поля
int Point::pointCount = 0;

// Демонстрация
int main() {
    setlocale(LC_ALL, "ru");
    cout << "Точки\n";
    
    // Создание точек
    Point p1;                    // конструктор по умолчанию
    Point p2(3.5, 4.2);          // с параметрами
    Point p3(p2);                // копирования
    
    cout << "p1: " << p1 << ", расстояние: " << p1.distance() << endl;
    cout << "p2: " << p2 << ", расстояние: " << p2.distance() << endl;
    cout << "p3: " << p3 << ", расстояние: " << p3.distance() << endl;
    
    // Сравнение
    cout << "\np2 == p3? " << (p2 == p3 ? "да" : "нет") << endl;
    cout << "p1 != p2? " << (p1 != p2 ? "да" : "нет") << endl;
    
    // Ввод с клавиатуры
    Point p4;
    cout << "\nВведите точку в формате (x; y): ";
    cin >> p4;
    cout << "Вы ввели: " << p4 << endl;
    
    // Статический счётчик
    cout << "\nВсего создано точек: " << Point::getPointCount() << endl;
    
    return 0;
}
