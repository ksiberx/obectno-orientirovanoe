#include <iostream>
#include <cmath>
using namespace std;

// Шаблон для линейного уравнения ax + b = 0
template <typename T>
void solveLinear(T a, T b) {
    cout << "Уравнение: " << a << "x + " << b << " = 0" << endl;
    
    if (a == 0) {
        if (b == 0)
            cout << "Бесконечное количество решений" << endl;
        else
            cout << "Нет решений" << endl;
    } else {
        T x = -b / a;
        cout << "Корень: x = " << x << endl;
    }
}

// Шаблон для квадратного уравнения ax^2 + bx + c = 0
template <typename T>
void solveQuadratic(T a, T b, T c) {
    cout << "Уравнение: " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
    
    if (a == 0) {
        // Если а = 0, то это линейное уравнение
        solveLinear(b, c);
        return;
    }
    
    T d = b*b - 4*a*c; // Дискриминант
    
    if (d > 0) {
        T x1 = (-b + sqrt(d)) / (2*a);
        T x2 = (-b - sqrt(d)) / (2*a);
        cout << "Два корня: x1 = " << x1 << ", x2 = " << x2 << endl;
    } else if (d == 0) {
        T x = -b / (2*a);
        cout << "Один корень: x = " << x << endl;
    } else {
        cout << "Нет действительных корней" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    cout << "Линейные уравнения" << endl;
    solveLinear(2.0, -8.0);    // 2x - 8 = 0
    solveLinear(0.0, 5.0);      // 0x + 5 = 0
    
    cout << "\nКвадратные уравнения" << endl;
    solveQuadratic(1.0, -5.0, 6.0); 
    solveQuadratic(1.0, -4.0, 4.0);  
    solveQuadratic(2.0, 1.0, 3.0);   
    
    return 0;
}
