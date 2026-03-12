#include <iostream>
using namespace std;

// класс
class Complex {
    double re, im;
public:
    Complex(double r = 0, double i = 0) : re(r), im(i) {}

    // Обычная перегрузка
    Complex operator+(const Complex& o) const { return Complex(re + o.re, im + o.im); }
    Complex operator-(const Complex& o) const { return Complex(re - o.re, im - o.im); }
    bool operator==(const Complex& o) const { return re == o.re && im == o.im; }
    bool operator!=(const Complex& o) const { return !(*this == o); }
    double operator()() const { return sqrt(re * re + im * im); }

    // Друзья
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.re << (c.im >= 0 ? "+" : "") << c.im << "i";
        return out;
    }
    friend istream& operator>>(istream& in, Complex& c) {
        cout << "re im: "; in >> c.re >> c.im;
        return in;
    }
    friend Complex operator+(double n, const Complex& c) { return Complex(n + c.re, c.im); }
};

// класс
class Time {
    int h, m, s;
    void norm() {
        m += s / 60; s %= 60; if (s < 0) { m--; s += 60; }
        h += m / 60; m %= 60; if (m < 0) { h--; m += 60; }
        if (h < 0) h = 0; if (h >= 24) h %= 24;
    }
public:
    Time(int hh = 0, int mm = 0, int ss = 0) : h(hh), m(mm), s(ss) { norm(); }

    void tick() { s++; norm(); }

    // Обычная перегрузка
    Time& operator++() { s++; norm(); return *this; }
    Time operator++(int) { Time t = *this; s++; norm(); return t; }
    Time& operator--() { s--; norm(); return *this; }
    Time operator--(int) { Time t = *this; s--; norm(); return t; }
    Time& operator+=(const Time& o) { h += o.h; m += o.m; s += o.s; norm(); return *this; }
    Time& operator-=(const Time& o) { h -= o.h; m -= o.m; s -= o.s; norm(); return *this; }

    bool operator==(const Time& o) const { return h == o.h && m == o.m && s == o.s; }
    bool operator!=(const Time& o) const { return !(*this == o); }
    bool operator>(const Time& o) const {
        if (h != o.h) return h > o.h;
        if (m != o.m) return m > o.m;
        return s > o.s;
    }
    bool operator<(const Time& o) const { return o > *this; }
    bool operator>=(const Time& o) const { return !(*this < o); }
    bool operator<=(const Time& o) const { return !(*this > o); }

    int operator()() const { return h * 3600 + m * 60 + s; }

    // Друзья
    friend Time operator+(const Time& a, const Time& b) { return Time(a.h + b.h, a.m + b.m, a.s + b.s); }
    friend Time operator-(const Time& a, const Time& b) { return Time(a.h - b.h, a.m - b.m, a.s - b.s); }
    friend ostream& operator<<(ostream& out, const Time& t) {
        out << (t.h < 10 ? "0" : "") << t.h << ":"
            << (t.m < 10 ? "0" : "") << t.m << ":"
            << (t.s < 10 ? "0" : "") << t.s;
        return out;
    }
    friend istream& operator>>(istream& in, Time& t) {
        char c; in >> t.h >> c >> t.m >> c >> t.s;
        t.norm();
        return in;
    }
};

//  тест 
int main() {
    Complex a(3, 4), b(1, 2);
    cout << "a=" << a << " b=" << b << " a+b=" << a + b << " |a|=" << a() << "\n";

    Time t1(10, 30, 45), t2(2, 15, 20);
    cout << "t1=" << t1 << " t2=" << t2 << " t1+t2=" << t1 + t2 << "\n";
    t1.tick();
    cout << "tick: " << t1 << "\n";
    ++t1;
    cout << "++t1: " << t1 << "\n";
}
