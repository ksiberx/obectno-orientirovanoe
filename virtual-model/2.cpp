#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void printInfo() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {}
    
    double area() const override {
        return 3.14159265359 * radius * radius;
    }
    
    double perimeter() const override {
        return 2 * 3.14159265359 * radius;
    }
    
    void printInfo() const override {
        cout << "Circle (radius = " << radius << ")" << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;
    
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double area() const override {
        return width * height;
    }
    
    double perimeter() const override {
        return 2 * (width + height);
    }
    
    void printInfo() const override {
        cout << "Rectangle (width = " << width << ", height = " << height << ")" << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

class Triangle : public Shape {
private:
    double side1, side2, side3;
    
public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}
    
    double area() const override {
        // Формула Герона
        double p = (side1 + side2 + side3) / 2;
        return sqrt(p * (p - side1) * (p - side2) * (p - side3));
    }
    
    double perimeter() const override {
        return side1 + side2 + side3;
    }
    
    void printInfo() const override {
        cout << "Triangle (sides = " << side1 << "," << side2 << "," << side3 << ")" << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

int main() { 
    setlocale(LC_ALL, "ru");
    vector<Shape*> shapes;
    
    shapes.push_back(new Circle(5));
    shapes.push_back(new Rectangle(4, 6));
    shapes.push_back(new Triangle(3, 4, 5));
    
    for (const auto& shape : shapes) {
        shape->printInfo();
        cout << endl;
    }
    
    // Освобождение памяти
    for (auto& shape : shapes) {
        delete shape;
    }
    
    return 0;
}
