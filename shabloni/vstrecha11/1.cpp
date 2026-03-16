#include <iostream>
using namespace std;

template <typename T>
T average(T arr[], int size) {
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    setlocale(LC_ALL, "ru");
    int intArr[] = {10, 20, 30, 40, 50};
    double doubleArr[] = {1.5, 2.5, 3.5, 4.5};
    
    cout << "Среднее int: " << average(intArr, 5) << endl;
    cout << "Среднее double: " << average(doubleArr, 4) << endl;
    
    return 0;
}
