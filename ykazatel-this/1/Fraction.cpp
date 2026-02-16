#include "Fraction.h"
#include <cmath>
using namespace std;

int Fraction::gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Fraction::reduce() {
    int g = gcd(abs(numerator), abs(denominator));
    numerator /= g;
    denominator /= g;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

Fraction::Fraction(int n, int d) : numerator(n), denominator(d) {
    if (denominator == 0) denominator = 1;
    reduce();
}

Fraction::Fraction() : Fraction(0, 1) {}

void Fraction::input() {
    cout << "Введите числитель: ";
    cin >> numerator;
    cout << "Введите знаменатель: ";
    cin >> denominator;

    if (denominator == 0) {
        cout << "Знаменатель не может быть 0! Установлен 1.\n";
        denominator = 1;
    }

    reduce();
}

void Fraction::print() const {
    cout << "Дробь: " << numerator << "/" << denominator << std::endl;
}

// операции с дробью
Fraction& Fraction::add(const Fraction& other) {
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator *= other.denominator;
    reduce();
    return *this;
}

Fraction& Fraction::sub(const Fraction& other) {
    numerator = numerator * other.denominator - other.numerator * denominator;
    denominator *= other.denominator;
    reduce();
    return *this;
}

Fraction& Fraction::mul(const Fraction& other) {
    numerator *= other.numerator;
    denominator *= other.denominator;
    reduce();
    return *this;
}

// операции с числом
Fraction& Fraction::add(int value) {
    numerator += value * denominator;
    reduce();
    return *this;
}

Fraction& Fraction::sub(int value) {
    numerator -= value * denominator;
    reduce();
    return *this;
}

Fraction& Fraction::mul(int value) {
    numerator *= value;
    reduce();
    return *this;
}
