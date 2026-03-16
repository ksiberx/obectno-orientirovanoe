#include <iostream>
using namespace std;

template <typename T>
T minOfTwo(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
    setlocale(LC_ALL, "ru");
    cout << "Минимум из 5 и 10: " << minOfTwo(5, 10) << endl;
    cout << "Минимум из 3.14 и 2.71: " << minOfTwo(3.14, 2.71) << endl;
    cout << "Минимум из A и Z: " << minOfTwo('A', 'Z') << endl;
    
    return 0;
}
