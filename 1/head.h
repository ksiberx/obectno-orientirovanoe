#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// Задание 1: Класс Date
class Date {
private:
    int day;
    int month;
    int year;

    bool isLeapYear(int y) const;
    int daysInMonth(int m, int y) const;
    long toDays() const;

public:
    Date();
    Date(int d, int m, int y);
    Date(const Date &other);

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);
    void setDate(int d, int m, int y);

    int operator-(const Date &other) const;
    Date operator+(int days) const;
    Date& operator+=(int days);
    
    void print() const;
};

//  Задание 2: Класс MyString
class MyString {
private:
    char* str;
    int length;

public:
    MyString();
    MyString(const char* s);
    MyString(const MyString &other);
    ~MyString();

    int getLength() const { return length; }
    const char* getStr() const { return str; }
    
    void setString(const char* s);
    
    MyString operator*(const MyString &other) const; // Пересечение строк
    
    void print() const;
};

#endif
