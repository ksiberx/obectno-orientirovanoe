#include <iostream>
#include <cstring>
using namespace std;

class Array {
private:
    int* data;
    int size;
    
public:
    Array(int s, int* arr) : size(s) {
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = arr[i];
    }
    
    ~Array() {
        delete[] data;
    }
    
    // Перегрузка [] - возвращает элемент по индексу
    int& operator[](int index) {
        return data[index];
    }
    
    // Перегрузка () - увеличивает все элементы на указанную величину
    void operator()(int value) {
        for (int i = 0; i < size; i++)
            data[i] += value;
    }
    
    // Преобразование к int - возвращает сумму элементов
    operator int() {
        int sum = 0;
        for (int i = 0; i < size; i++)
            sum += data[i];
        return sum;
    }
    
    // Преобразование к char* - возвращает строку из элементов
    operator char*() {
        char* result = new char[100];
        result[0] = '\0';
        char buffer[20];
        for (int i = 0; i < size; i++) {
            sprintf(buffer, "%d ", data[i]);
            strcat(result, buffer);
        }
        return result;
    }
    
    void print() {
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    int arr[] = {1, 2, 3, 4, 5};
    Array a(5, arr);
    
    cout << "Исходный массив: ";
    a.print();
    
    cout << "Элемент [2]: " << a[2] << endl;
    
    a(10); // Увеличиваем на 10
    cout << "После увеличения на 10: ";
    a.print();
    
    int sum = a;
    cout << "Сумма элементов: " << sum << endl;
    
    char* str = a;
    cout << "Строковое представление: " << str << endl;
    delete[] str;
    
    return 0;
}
