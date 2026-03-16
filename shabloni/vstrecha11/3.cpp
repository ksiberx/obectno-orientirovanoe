#include <iostream>
using namespace std;

template <typename T>
T maxOfTwo(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    setlocale(LC_ALL, "ru");
    cout << "Максимум из 5 и 10: " << maxOfTwo(5, 10) << endl;
    cout << "Максимум из 3.14 и 2.71: " << maxOfTwo(3.14, 2.71) << endl;
    cout << "Максимум из A и Z: " << maxOfTwo('A', 'Z') << endl;
    
    return 0;
}
