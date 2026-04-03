#include <iostream>
#include <vector>

using namespace std;

class Shape {
public:
    virtual void draw() const {
        cout << "Рисуем общую фигуру" << endl;
    }
    // Виртуальный деструктор
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() const override {
        cout << "Рисуем круг: (•)" << endl;
    }
    
    void circleSpecific() const {
        cout << "Это специфический метод круга" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        cout << "Рисуем прямоугольник: [▯]" << endl;
    }
    
    void rectangleSpecific() const {
        cout << "Это специфический метод прямоугольника" << endl;
    }
};

// Функция для безопасного приведения и отрисовки
void identifyAndDraw(Shape* s) {
    if (!s) {
        cout << "Указатель пуст!" << endl;
        return;
    }
    
    // Пробуем привести к Circle
    Circle* circle = dynamic_cast<Circle*>(s);
    if (circle) {
        cout << "Обнаружен КРУГ -> ";
        circle->draw();
        return;
    }
    
    // Пробуем привести к Rectangle
    Rectangle* rect = dynamic_cast<Rectangle*>(s);
    if (rect) {
        cout << "Обнаружен ПРЯМОУГОЛЬНИК -> ";
        rect->draw();
        return;
    }
    
    // Если ни к чему не привелось
    cout << "Неизвестный тип фигуры -> ";
    s->draw();
}

int main() {
    setlocale(LC_ALL, "ru");
    cout << "Демонстрация безопасного приведения типов" << endl;
    cout << endl;
    
    // Создаём массив указателей на Shape
    Shape* shapes[] = {
        new Circle(),
        new Rectangle(),
        new Circle(),
        new Rectangle(),
        new Shape()      // просто базовая фигура
    };
    
    // Подсчитываем количество элементов
    int size = sizeof(shapes) / sizeof(shapes[0]);
    
    for (int i = 0; i < size; i++) {
        cout << "Фигура " << i + 1 << ": ";
        identifyAndDraw(shapes[i]);
    }
    
    // Освобождаем память
    cout << endl;
    cout << "Освобождаем память" << endl;
    for (int i = 0; i < size; i++) {
        delete shapes[i];
    }
    
    return 0;
}
