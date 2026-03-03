#include "head.h"

// Вспомогательные функции
int daysInMonth(int m, int y) {
    if (m < 1 || m > 12) return 0;
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))) 
        return 29;
    return days[m - 1];
}

long dateToDays(int d, int m, int y) {
    long total = 0;
    
    // Годы
    for (int year = 1; year < y; year++) {
        int daysInYear = 365;
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            daysInYear = 366;
        total += daysInYear;
    }
    
    // Месяцы
    for (int month = 1; month < m; month++) {
        total += daysInMonth(month, y);
    }
    
    // Дни
    total += d;
    
    return total;
}

// --- Конструкторы ---
Date::Date() {
    day = 1;
    month = 1;
    year = 2000;
}

Date::Date(int d, int m, int y) {
    // Проверка года
    if (y < 1) y = 2000;
    year = y;
    
    // Проверка месяца
    if (m < 1 || m > 12) m = 1;
    month = m;
    
    // Проверка дня
    int maxDay = daysInMonth(month, year);
    if (d < 1 || d > maxDay) d = 1;
    day = d;
}

Date::Date(const Date &other) {
    day = other.day;
    month = other.month;
    year = other.year;
}

// --- Сеттеры ---
void Date::setDay(int d) {
    int maxDay = daysInMonth(month, year);
    if (d >= 1 && d <= maxDay) {
        day = d;
    }
}

void Date::setMonth(int m) {
    if (m >= 1 && m <= 12) {
        month = m;
        // Корректируем день, если нужно
        int maxDay = daysInMonth(month, year);
        if (day > maxDay) {
            day = maxDay;
        }
    }
}

void Date::setYear(int y) {
    if (y >= 1) {
        year = y;
        // Корректируем день для февраля
        int maxDay = daysInMonth(month, year);
        if (day > maxDay) {
            day = maxDay;
        }
    }
}

void Date::setDate(int d, int m, int y) {
    // Год
    if (y >= 1) year = y;
    else year = 2000;
    
    // Месяц
    if (m >= 1 && m <= 12) month = m;
    else month = 1;
    
    // День
    int maxDay = daysInMonth(month, year);
    if (d >= 1 && d <= maxDay) day = d;
    else day = 1;
}

// --- Операторы ---
int Date::operator-(Date &other) {
    long d1 = dateToDays(day, month, year);
    long d2 = dateToDays(other.day, other.month, other.year);
    
    if (d1 > d2) return d1 - d2;
    else return d2 - d1;
}

Date Date::operator+(int days) {
    Date result = *this;
    
    while (days > 0) {
        int maxDay = daysInMonth(result.month, result.year);
        if (result.day + days <= maxDay) {
            result.day += days;
            days = 0;
        } else {
            days -= (maxDay - result.day + 1);
            result.day = 1;
            result.month++;
            if (result.month > 12) {
                result.month = 1;
                result.year++;
            }
        }
    }
    
    return result;
}

Date& Date::operator+=(int days) {
    while (days > 0) {
        int maxDay = daysInMonth(month, year);
        if (day + days <= maxDay) {
            day += days;
            days = 0;
        } else {
            days -= (maxDay - day + 1);
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
    return *this;
}

void Date::print() {
    if (day < 10) cout << "0";
    cout << day << ".";
    if (month < 10) cout << "0";
    cout << month << "." << year;
}
