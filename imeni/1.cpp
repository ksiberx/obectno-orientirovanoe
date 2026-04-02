#include <iostream>
using namespace std;

namespace Geometry {
    const double PI = 3.14159;

    double circleArea(double radius) {
        return PI * radius * radius;
    }

    double rectangleArea(double width, double height) {
        return width * height;
    }

    namespace Shapes {
        class Circle {
        private:
            double radius;
        public:
            Circle(double r) : radius(r) {}

            double area() const {
                return circleArea(radius);
            }
        };
    }
}

int main() {
    // Способ 1: полная квалификация
    cout << "Circle area (full): " << Geometry::circleArea(5.0) << endl;
    cout << "Rectangle area (full): " << Geometry::rectangleArea(4.0, 6.0) << endl;
    
    // Способ 2: using-объявление
    using Geometry::circleArea;
    using Geometry::rectangleArea;
    cout << "Circle area (using-decl): " << circleArea(3.0) << endl;
    cout << "Rectangle area (using-decl): " << rectangleArea(2.0, 5.0) << endl;
    
    // Способ 3: using namespace
    using namespace Geometry;
    cout << "Circle area (using namespace): " << circleArea(4.0) << endl;
    cout << "Rectangle area (using namespace): " << rectangleArea(3.0, 7.0) << endl;
    
    // Класс из вложенного пространства
    using namespace Geometry::Shapes;
    Circle c(2.5);
    cout << "Circle class area: " << c.area() << endl;

    return 0;
}
