#include <iostream>
using namespace std;

class Fraction {
private:
    int num, den;

public:
    Fraction() : num(0), den(1) {}               // по умолчанию
    Fraction(int n, int d) : num(n), den(d) {}   // с параметрами

    inline int getNum() const { return num; }    // inline
    inline int getDen() const { return den; }

    void print() const {
        cout << num << "/" << den << endl;
    }

    Fraction add(const Fraction& f) {            // сложение дробей
        return Fraction(num * f.den + f.num * den,
                        den * f.den);
    }
};
