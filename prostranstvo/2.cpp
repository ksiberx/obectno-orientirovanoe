#include <iostream>
using namespace std;

// Собственное исключение
class DivisionByZeroException {
public:
    const char* what() {
        return "Ошибка: Деление на ноль!";
    }
};

class SafeDivision {
public:
    static double divide(double a, double b) {
        if (b == 0) {
            throw DivisionByZeroException();
        }
        return a / b;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    // Тестируем разные варианты
    double numbers[][2] = {
        {10, 2},
        {15, 3},
        {7, 0},    // деление на ноль
        {25, 5},
        {100, 0},  // деление на ноль
        {0, 5}
    };
    
    for (int i = 0; i < 6; i++) {
        double a = numbers[i][0];
        double b = numbers[i][1];
        
        cout << a << " / " << b << " = ";
        
        try {
            double result = SafeDivision::divide(a, b);
            cout << result << "\n";
        } catch (DivisionByZeroException& e) {
            cout << e.what() << "\n";
        }
    }
    
    // Проверка с вводом пользователя
    cout << "\n--- Ввод от пользователя ---\n";
    double x, y;
    cout << "Введите делимое: ";
    cin >> x;
    cout << "Введите делитель: ";
    cin >> y;
    
    try {
        double result = SafeDivision::divide(x, y);
        cout << "Результат: " << result << "\n";
    } catch (DivisionByZeroException& e) {
        cout << e.what() << "\n";
    }
    
    return 0;
}
