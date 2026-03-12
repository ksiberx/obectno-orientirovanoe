#include <iostream>
#include <string>
using namespace std;

// Задание 1: Класс Date
class Date {
private:
    int day, month, year;
    
    // Вспомогательная функция для проверки високосного года
    bool isLeap(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }
    
    // Количество дней в месяце
    int daysInMonth(int m, int y) const {
        if (m == 2) return isLeap(y) ? 29 : 28;
        if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
        return 31;
    }
    
    // Преобразование даты в количество дней от 01.01.0001
    long toDays() const {
        long total = 0;
        // Считаем дни за все годы
        for (int y = 1; y < year; y++) {
            total += isLeap(y) ? 366 : 365;
        }
        // Считаем дни за месяцы текущего года
        for (int m = 1; m < month; m++) {
            total += daysInMonth(m, year);
        }
        // Добавляем дни текущего месяца
        total += day;
        return total;
    }
    
public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    
    // Оператор разности дат (количество дней между датами)
    int operator-(const Date& other) const {
        return abs(toDays() - other.toDays());
    }
    
    // Оператор увеличения даты на количество дней
    Date operator+(int days) const {
        Date result = *this;
        while (days > 0) {
            int daysInCurrentMonth = result.daysInMonth(result.month, result.year);
            if (result.day + days <= daysInCurrentMonth) {
                result.day += days;
                break;
            } else {
                days -= (daysInCurrentMonth - result.day + 1);
                result.day = 1;
                if (result.month == 12) {
                    result.month = 1;
                    result.year++;
                } else {
                    result.month++;
                }
            }
        }
        return result;
    }
    
    void print() const {
        cout << day << "." << month << "." << year;
    }
};

// Задание 2: Пересечение строк через оператор *
string operator*(const string& s1, const string& s2) {
    string result;
    for (char c : s1) {
        // Если символ есть во второй строке и еще не добавлен в результат
        if (s2.find(c) != string::npos && result.find(c) == string::npos) {
            result += c;
        }
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "ru");
    // Тест Задания 1
    cout << "=== Задание 1: Класс Date ===" << endl;
    Date d1(1, 1, 2023);
    Date d2(15, 3, 2023);
    
    cout << "Дата 1: "; d1.print(); cout << endl;
    cout << "Дата 2: "; d2.print(); cout << endl;
    cout << "Разница в днях: " << (d2 - d1) << " дней" << endl;
    
    Date d3 = d1 + 45;
    cout << "Дата 1 + 45 дней: "; d3.print(); cout << endl;
    
    // Тест Задания 2
    cout << "\n=== Задание 2: Пересечение строк ===" << endl;
    string s1 = "sdqcg";
    string s2 = "rgfas34";
    
    cout << "Строка 1: " << s1 << endl;
    cout << "Строка 2: " << s2 << endl;
    cout << "Пересечение: " << (s1 * s2) << endl;
    
    return 0;
}
