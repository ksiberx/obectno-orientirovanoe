#include <iostream>
using namespace std;

class Roll {
public:
    double w, h, price;
};

class Room {
public:
    double l, w, h;
    bool ceiling;
};

class Flat {
public:
    Room rooms[5];
    int count;
};

int main() {
    setlocale(LC_ALL, "Ru");
    Flat f;
    f.count = 1;
    f.rooms[0] = {5, 4, 3, false};

    Roll r = {1, 10, 500};

    double area = 0;
    for (int i = 0; i < f.count; i++) {
        area += 2 * (f.rooms[i].l + f.rooms[i].w) * f.rooms[i].h;
    }

    int rolls = area / (r.w * r.h) + 1;
    cout << "Рулонов: " << rolls << endl;
    cout << "Стоимость: " << rolls * r.price << endl;

    return 0;
}
