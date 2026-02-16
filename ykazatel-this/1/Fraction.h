#pragma once
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

    void reduce();
    int gcd(int a, int b);

public:
    Fraction(int n, int d);
    Fraction();a

    void input();
    void print() const;

    Fraction& add(const Fraction& other);
    Fraction& sub(const Fraction& other);
    Fraction& mul(const Fraction& other);

    Fraction& add(int value);
    Fraction& sub(int value);
    Fraction& mul(int value);
};

#endif
