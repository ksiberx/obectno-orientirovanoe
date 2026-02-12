#include <iostream>
using namespace std;

class Lift {
    int minF, maxF, curF;
    bool on;
public:
    Lift(int min, int max) : minF(min), maxF(max), curF(min), on(false) {}

    void power(bool state) { on = state; }

    bool isOn() { return on; }

    int floor() { return curF; }

    void call(int f) {
        if (on && f >= minF && f <= maxF)
            curF = f;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Lift l(1, 9);
    l.power(true);
    l.call(5);
    cout << "Этаж: " << l.floor() << endl;
    return 0;
}
