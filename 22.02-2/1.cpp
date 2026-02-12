#include <iostream>
using namespace std;

class Point {
private:
    double x, y;

public:
    Point() : x(0), y(0) {}                 // конструктор по умолчанию
    Point(double x, double y) : x(x), y(y) {} // конструктор с параметрами

    inline void setX(double x) { this->x = x; } // inline функция
    inline void setY(double y) { this->y = y; }

    inline double getX() const { return x; }
    inline double getY() const { return y; }

    void print() const {                     // вывод точки
        cout << "Point(" << x << ", " << y << ")\n";
    }
};
