#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

class String {
private:
    char* str;
    int length;

public:
    // Конструктор по умолчанию (80 символов)
    String() {
        length = 80;
        str = new char[length + 1];
        str[0] = '\0';
        cout << "Конструктор String: пустая строка 80 символов" << endl;
    }

    // Конструктор с размером
    String(int size) {
        length = size;
        str = new char[length + 1];
        str[0] = '\0';
        cout << "Конструктор String: строка на " << size << " символов" << endl;
    }

    // Конструктор инициализации
    String(const char* input) {
        length = strlen(input);
        str = new char[length + 1];
        strcpy(str, input);
        cout << "Конструктор String: \"" << str << "\"" << endl;
    }

    // Конструктор копирования
    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
        cout << "Конструктор копирования String: \"" << str << "\"" << endl;
    }

    // Деструктор
    ~String() {
        cout << "Деструктор String: \"" << str << "\" удален" << endl;
        delete[] str;
    }

    // Ввод с клавиатуры
    void input() {
        cout << "Введите строку: ";
        char buffer[1000];
        cin.getline(buffer, 1000);

        delete[] str;
        length = strlen(buffer);
        str = new char[length + 1];
        strcpy(str, buffer);
    }

    // Вывод на экран
    void print() {
        cout << "Строка: \"" << str << "\", длина: " << length << endl;
    }
};

class Array {
private:
    int* arr;
    int size;

public:
    // Конструктор по умолчанию
    Array() {
        size = 10;
        arr = new int[size];
        cout << "Конструктор Array: массив на 10 элементов" << endl;
    }

    // Конструктор с размером
    Array(int n) {
        size = n;
        arr = new int[size];
        cout << "Конструктор Array: массив на " << n << " элементов" << endl;
    }

    // Конструктор копирования
    Array(const Array& other) {
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
        cout << "Конструктор копирования Array" << endl;
    }

    // Деструктор
    ~Array() {
        cout << "Деструктор Array: удаляем массив из " << size << " элементов" << endl;
        delete[] arr;
    }

    // Заполнение случайными
    void fillRandom() {
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 100;
        }
        cout << "Массив заполнен случайными числами" << endl;
    }

    // Ввод с клавиатуры
    void input() {
        cout << "Введите " << size << " чисел:" << endl;
        for (int i = 0; i < size; i++) {
            cout << "[" << i << "]: ";
            cin >> arr[i];
        }
    }

    // Вывод на экран
    void print() {
        cout << "Массив: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Изменение размера
    void resize(int newSize) {
        int* newArr = new int[newSize];
        int minSize = (newSize < size) ? newSize : size;

        for (int i = 0; i < minSize; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        size = newSize;
        cout << "Размер изменен на " << newSize << endl;
    }

    // Сортировка (пузырьком - простая и рабочая)
    void sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        cout << "Массив отсортирован" << endl;
    }

    // Минимум
    int getMin() {
        if (size == 0) return 0;
        int minVal = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] < minVal) minVal = arr[i];
        }
        return minVal;
    }

    // Максимум
    int getMax() {
        if (size == 0) return 0;
        int maxVal = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > maxVal) maxVal = arr[i];
        }
        return maxVal;
    }
};

int main() {
    setlocale(LC_ALL, "Ru");
    srand(time(NULL));

    cout << " ЗАДАНИЕ 1: STRING \n\n";

    // Тестируем String
    String s1;
    s1.print();

    String s2(30);
    s2.print();

    String s3("Привет, мир!");
    s3.print();

    String s4 = s3;
    s4.print();

    cout << "\n ЗАДАНИЕ 2: ARRAY \n\n";

    // Тестируем Array
    Array a1;
    a1.fillRandom();
    a1.print();
    cout << "Минимум: " << a1.getMin() << ", Максимум: " << a1.getMax() << endl;

    Array a2(5);
    a2.input();
    a2.print();

    Array a3 = a2;
    a3.print();

    a1.resize(15);
    a1.fillRandom();
    a1.print();

    a2.sort();
    cout << "После сортировки:" << endl;
    a2.print();

    cout << "\n АВТОМАТИЧЕСКОЕ УНИЧТОЖЕНИЕ \n";

    return 0;
}
